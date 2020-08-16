#include "hamc.h"

/* Lo que tenemos que tener cuidado ahora es:
    *) no formar ciclos (antes de tiempo)
    *) que no haya vertices de grado 3 o mayor en el grafo generador que construimos.
    En cada iteracion agregaremos la arista de menor peso entretodas las que
    cumplan estas dos carateristicas. Si agregamos n−1 aristas (en un grafo de n vertices),
    habremos formado un camino hamiltoniano. Para obtener un ciclo, debemos agregar la arista
    entre los dos vertices extremos de este camino. Este procedimiento tambien es goloso.
*/
float heuristica_aristaMasCorta(Grafo_lst_inc &G, int n, vector<Vertice> &circuito) {
    // Sorting
    stable_sort(G.begin(), G.end(), sortByWeight); //esta funcion de la stl ordena en O(nlog(n))

    //Arreglo que guarda el grado de cada vertice durante las iteraciones
    vector<Vertice> grado(n, 0);

    // Indice de la arista a evaluar
    int i = 0;
    // Variable para llevar la cantidad de vertices en el grafo resultado
    int vertices = 0;

    //Inicializo variables
    bool hay_ciclo = false;
    bool hay_nodo_grado_3 = false;
    Grafo_lst_inc aristas;

    //Iteramos hasta que la lista de aristas este llena
    while (aristas.size() <= n - 1) {
        // Si al agregar el nodo no tenemos ningun nodo de grado 3:
        hay_nodo_grado_3 = grado[G[i].src] + 1 >= 3 || grado[G[i].dst] + 1 >= 3;

        // Si al agregar un nodo no hay ciclo:
        if (!hay_nodo_grado_3) {
            //Agrego la arista temportalmente
            aristas.push_back(G[i]);
            //Chequeo si hay ciclo
            hay_ciclo = esCiclo(aristas, n);

            //Si hay ciclo significa que no debe haber camio, por lo que saco la arista nueva
            //Si no hay ciclo actualizo vertices y la tabla de grados
            // OBS: se hace un chequeo de si no estamos en la ultima arista
            //      ya que en el caso de la ultima arista ya se forma un ciclo, por lo que no debemos sacarla
            if (hay_ciclo && aristas.size() != n) { //FIXME: Revisar que este bien la guarda
                // Caso i<n-2: No podemos agregar esa arista
                aristas.pop_back();
            } else {
                grado[G[i].src]++;
                grado[G[i].dst]++;
            }
        }
        i++;
    }

    //Construyo un set con las aristas
    set<Arista> grafo_set;
    //Ademas hago la suma de los pesos del circuito final
    float suma=0;
    for (Arista a : aristas) {
        grafo_set.insert(a);
        suma += a.peso;
    }

    /** Construimos el circuito con el conjunto de Aristas obtenido*/
    //Agregamos los vertices de la arista inicial al circuito, la borramos del cjto
    circuito.push_back(grafo_set.begin()->src);
    circuito.push_back(grafo_set.begin()->dst);
    grafo_set.erase(grafo_set.begin());

    //la variable llevara cuenta de cual es el vertice a buscar en las aristas restantes
    int last = 1;
    while(circuito.size()<n){
        for (auto ptr = grafo_set.begin(); ptr != grafo_set.end(); ptr++){
            if (circuito[last] == ptr->src || circuito[last] == ptr->dst){
                Vertice v = (circuito[last] == ptr->src ? ptr->dst : ptr->src);
                circuito.push_back(v);
                grafo_set.erase(ptr);
                break;
            }
        }
        //Puedo asegurar que voy a avanzar el vertice evaluado ya que deberia haber
        //un circuito correcto en grafo_set
        last++;
    }
    return suma;
}

int esCiclo(Grafo_lst_inc &G,int v_max)
{
    //int V = n;
    int E = G.size();

    vector<representante> representantes(v_max);
    for (int v = 0; v < v_max; ++v){
        representantes[v].padre = v;
        representantes[v].altura = 0;
    }

    // Iteramos sobre las aristas del grafo, y encontramos los representantes de los vertices para cada arista
    // Si dos representantes de una arista son iguales hay un ciclo en el grafo.

    for(int e = 0; e < E; ++e){
        int x = find(representantes, G[e].src);
        int y = find(representantes, G[e].dst);
        if (x == y)
            return 1;
        Union(representantes, x, y);
    }
    return 0;
}

int find(vector<representante> &representantes, int i)
{
    // find root and make root as padre of i (path compression)
    if (representantes[i].padre != i)
        representantes[i].padre = find(representantes, representantes[i].padre);

    return representantes[i].padre;
}

// A function that does union of two sets of x and y
// (uses union by altura)
void Union(vector<representante>& representantes, int x, int y)
{
    int xroot = find(representantes, x);
    int yroot = find(representantes, y);

    // Attach smaller altura tree under root of high altura tree
    // (Union by altura)
    if (representantes[xroot].altura < representantes[yroot].altura)
        representantes[xroot].padre = yroot;
    else if (representantes[xroot].altura > representantes[yroot].altura)
        representantes[yroot].padre = xroot;

        // If alturas are same, then make one as root and increment
        // its altura by one
    else
    {
        representantes[yroot].padre = xroot;
        representantes[xroot].altura++;
    }
}

bool sortByWeight(const Arista &lhs, const Arista &rhs) { return lhs.peso < rhs.peso; }