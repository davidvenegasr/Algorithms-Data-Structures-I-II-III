#include "mheur.h"

Ciclo swap2opt(Ciclo &cicloH, Vertice i, Vertice j) {
    Ciclo cicloNuevo;
    
    //Ajusto los vertices para que i < j
    if (i > j) {
        Vertice aux = i;
        i = j;
        j = aux;
    }

    //Genero camino desde 0 a i inclusive
    for (int v = 0; v <= i; v++) {
        cicloNuevo.push_back(cicloH[v]);
    }
    //Como remuevo arista (i, i+1) y agrego (i, j)
    //Genero camino reversa desde j hasta i+1 inclusive
    for (int v = j; v >= i+1; v--) {
        cicloNuevo.push_back(cicloH[v]);
    }
    //Como remuevo arista (j, j+1) y agrego (i+1, j+1)
    //Genero camino desde j+1 hasta completar
    for (int v = j+1; v < cicloH.size(); v++) {
        cicloNuevo.push_back(cicloH[v]);
    }

    return cicloNuevo;
}

Peso tabuSearch(Grafo &G, Ciclo &ciclo, ts_mem_t mem) {
    //Obtenemos el mejor ciclo posible y el mejor peso, basados en alguna heuristica
    Peso pesoMejorCiclo = heuristica_agm(G, ciclo);
    Ciclo mejorCiclo = ciclo;
    int iterTotal = 0;
    int iterSinMejora = 0;

    srand(time(NULL));

    vector<Swap> memoria_swaps;
    vector<Ciclo> memoria_ciclos;

    if (MEM_SIZE == 0) {MEM_SIZE = 1;}

    //Inicializo la memoria correspondiente
    if (mem==ciclos)    {memoria_ciclos = vector<Ciclo> (MEM_SIZE);}
    if (mem==swaps)     {memoria_swaps = vector<Swap> (MEM_SIZE);}

    int indiceMem = 0;

    auto tiempoInicio = chrono::steady_clock::now();
    
    while(!criterioParada(iterTotal, iterSinMejora, tiempoInicio)) {
        vector<Ciclo> vecindad;
        Peso pesoCiclo;
        if (mem==ciclos){
            //Obtengo la vecindad del ciclo
            vecindad = obtenerVecindad_ciclos(G, ciclo, PORC_VECINDAD);
            //Obtengo el mejor ciclo de la vecindad
            pesoCiclo = obtenerMejorCiclo_ciclos(G, vecindad, memoria_ciclos, ciclo);
            //Recuerdo el ciclo en memoria para no repetir
            memoria_ciclos[indiceMem] = ciclo;
            indiceMem = (indiceMem + 1) % MEM_SIZE;
        }
        if (mem==swaps){
            //Obtengo la vecindad del ciclo
            vecindad = obtenerVecindad_swaps(G, ciclo, memoria_swaps, indiceMem, PORC_VECINDAD);
            //Obtengo el mejor ciclo de la vecindad
            pesoCiclo = obtenerMejorCiclo_swaps(G, vecindad, ciclo);
        }

        //Si supera el óptimo, lo guardo como nuevo óptimo
        if (pesoCiclo < pesoMejorCiclo) {
            mejorCiclo = ciclo;
            pesoMejorCiclo = pesoCiclo;
            iterSinMejora = 0;
        }
        iterTotal++;
        iterSinMejora++;
    }

    ciclo = mejorCiclo;
    return pesoMejorCiclo;
}

bool criterioParada(int iterT, int iterSM, chrono::steady_clock::time_point tiempoInicio) {
    //Parada por iteraciones totales
    if (iterT >= MAX_ITER) {return true;}
    //Parada por iteraciones sin mejora
    if (iterSM >= MAX_ITER_SM) {return true;}
    
    //Parada por tiempo excedido
    auto tiempoActual = chrono::steady_clock::now();
    double tiempoTotal = chrono::duration<double, milli>(tiempoActual - tiempoInicio).count();
    if (MAX_TIEMPO_MS > 0 && tiempoTotal >= MAX_TIEMPO_MS) {return true;}

    return false;
}

vector<Ciclo> obtenerVecindad_ciclos(Grafo &G, Ciclo &ciclo, float porc) {
    vector<Ciclo> vecinos;

    for(int i = 0; i < ciclo.size(); i++) {
        for(int j = i + 1; j < ciclo.size(); j++) {
            float pesoActual = obtenerPesoArista(G, ciclo[i], ciclo[(i+1) % ciclo.size()]) +  obtenerPesoArista(G, ciclo[j], ciclo[(j+1) % ciclo.size()]);
            float pesoNuevo = obtenerPesoArista(G, ciclo[i], ciclo[j]) +  obtenerPesoArista(G, ciclo[(i+1) % ciclo.size()], ciclo[(j+1) % ciclo.size()]);
            //Si el intercambio de aristas 2opt mejora el circuito
            if (pesoNuevo < pesoActual) {
                //Si el ciclo tiene mas de 10 vertices, filtro por un porcentaje random
                if (ciclo.size() > 10 && !seleccionaRandom(porc)) {continue;}

                //Realizo el intercambio y lo agrego a la vecindad
                vecinos.push_back(swap2opt(ciclo, i, j));
            }
        }
    }

    return vecinos;
}

vector<Ciclo> obtenerVecindad_swaps(Grafo &G, Ciclo &ciclo, vector<pair<Arista,Arista>> memoria, int indiceMem, float porc) {
    vector<Ciclo> vecinos;
    for(int i = 0; i < ciclo.size(); i++) {
        for(int j = i + 1; j < ciclo.size(); j++) {

            //Vertices v[i] v[i+1] v[j] v[j+1]
            Vertice vi = ciclo[i];
            Vertice vi_1 = ciclo[(i+1) % ciclo.size()];
            Vertice vj = ciclo[j];
            Vertice vj_1 = ciclo[(j+1) % ciclo.size()];

            // Pesos de aristas:
            //Arista (v[i], v[i+1])
            float peso_arista_actual1 = obtenerPesoArista(G, vi, vi_1);
            //Arista (v[j], v[j+1])
            float peso_arista_actual2 = obtenerPesoArista(G, vj, vj_1);
            //Arista (v[i], v[j])
            float peso_arista_nueva1 = obtenerPesoArista(G, vi, vj);
            //Arista (v[i+1], v[j+1])
            float peso_arista_nueva2 = obtenerPesoArista(G, vi_1, vj_1);

            float pesoActual = peso_arista_actual1 + peso_arista_actual2;
            float pesoNuevo =  peso_arista_nueva1  + peso_arista_nueva2;

            pair<Arista,Arista> swap = {Arista(vi, vj, peso_arista_nueva1), Arista(vi_1, vj_1, peso_arista_nueva2)};

            //Si el intercambio de aristas 2opt mejora el circuito
            //Y la arista no fue swapeada anteriormente
            if (!enMemoria_swaps(swap, memoria) && pesoNuevo < pesoActual) {
                //Si el ciclo tiene mas de 10 vertices, filtro por un porcentaje random
                if (ciclo.size() > 10 && !seleccionaRandom(porc)) {continue;}

                //Realizo el intercambio y lo agrego a la vecindad
                vecinos.push_back(swap2opt(ciclo, i, j));

                //Agrego las aristas a la memoria para no repetir
                memoria[indiceMem] = swap;
                indiceMem = (indiceMem + 1) % MEM_SIZE;
            }
        }
    }
    return vecinos;
}

Peso obtenerMejorCiclo_ciclos(Grafo &G, vector<Ciclo> &vecindad, vector<Ciclo> &memoria, Ciclo &ciclo) {
    Ciclo mejorCiclo = ciclo;
    Peso pesoMejorCiclo = INFTY;

    //Recorro la vecindad
    for(int i = 0; i < vecindad.size(); i++) {
        Ciclo ciclo = vecindad[i];
        Peso pesoCiclo = calcularPeso(G, ciclo);
        //Si no esta en memoria y mejora el optimo, lo reemplazo
        if (!enMemoria_ciclos(ciclo, memoria) && pesoCiclo < pesoMejorCiclo) {
            mejorCiclo = ciclo;
            pesoMejorCiclo = pesoCiclo;
        }
    }

    ciclo = mejorCiclo;
    return pesoMejorCiclo;
}

Peso obtenerMejorCiclo_swaps(Grafo &G, vector<Ciclo> &vecindad, Ciclo &ciclo) {
    Ciclo mejorCiclo = ciclo;
    Peso pesoMejorCiclo = INFTY;

    //Recorro la vecindad
    for(int i = 0; i < vecindad.size(); i++) {
        Ciclo ciclo = vecindad[i];
        Peso pesoCiclo = calcularPeso(G, ciclo);
        //Si mejora el optimo, lo reemplazo
        if (pesoCiclo < pesoMejorCiclo) {
            mejorCiclo = ciclo;
            pesoMejorCiclo = pesoCiclo;
        }
    }

    ciclo = mejorCiclo;
    return pesoMejorCiclo;
}


bool enMemoria_ciclos(Ciclo &ciclo, vector<Ciclo> &memoria) {
    for (Ciclo c : memoria) {
        if (c == ciclo) {return true;}
    }
    return false;
}

bool enMemoria_swaps(Swap swap, vector<Swap> &memoria){
    for (Swap pair : memoria) {
        if (pair == swap) {return true;}
    }
    return false;
}

int randomInt(int tope, int base) {

    int n = tope - base;
    int divisor = RAND_MAX / n;

    int k = rand();
    do { k = k / divisor; } while (k >= n);
    
    return k;
}

bool seleccionaRandom(float porc) {
    if (randomInt(99,0) < (porc * 100)) {return true;}
    
    return false;
}

/*
Ciclo busqLocal2opt (Grafo &G) {
    Ciclo cicloH;
    //Genero el circuito inicial
    float pesoMin = heuristica_agm(G, cicloH);

    bool hayMejora = true;
    //Mientras exista mejora de circuito
    while(hayMejora){
        hayMejora = false;
        //Recorro todos los pares de vertices
        for(int i = 0; i < cicloH.size(); i++) {
            for(int j = i + 1; j < cicloH.size(); j++) {
                float pesoActual = obtenerPesoArista(G, cicloH[i], cicloH[(i+1) % cicloH.size()]) +  obtenerPesoArista(G, cicloH[j], cicloH[(j+1) % cicloH.size()]);
                float pesoNuevo = obtenerPesoArista(G, cicloH[i], cicloH[j]) +  obtenerPesoArista(G, cicloH[(i+1) % cicloH.size()], cicloH[(j+1) % cicloH.size()]);
                //Si el intercambio de aristas 2opt mejora el circuito
                if (pesoNuevo < pesoActual) {
                    //Realizo el intercambio y marco flag de mejora
                    Ciclo cicloH = swap2opt(cicloH, i, j);
                    hayMejora = true;
                }
            }
        }
    }
    return cicloH;
}
*/