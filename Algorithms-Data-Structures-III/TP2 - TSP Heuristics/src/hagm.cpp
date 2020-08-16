#include "hagm.h"

//Heuristica AGM basada en Prim
float heuristica_agm (Grafo &G, vector<Vertice> &circuito) {
    vector<Vertice> padre = agm_prim(G);
    circuito = camino_dfs(padre);

    return calcularPeso(G, circuito);
}

float calcularPeso(Grafo &G, vector<Vertice> &circuito) {
    float peso = 0;
    //Acumulo el peso de las aristas que une cada vertice del circuito
    for (int i = 0; i < circuito.size(); i++) {
        peso += obtenerPesoArista(G, circuito[i], circuito[(i+1) % circuito.size()]);
    }

    return peso;
}

vector<Vertice> camino_dfs (vector<Vertice> &padre) {
    vector<Vertice> orden;
    vector<Vertice> pred = vector<Vertice>(padre.size(), -1);
    vector<bool> visit = vector<bool>(padre.size(), false);
    vector<Vertice> pila;

    Vertice r = 0;  //Uso como raiz el vertice 0

    pred[r] = 0;
    orden.push_back(r);
    pila.push_back(r);

    while (!pila.empty()) {
        Vertice tope = pila[pila.size()-1];
        //Obtengo un hijo no visitado
        Vertice hijo = obtenerHijo(pila, padre, visit);

        //Si encontre un hijo no visitado, lo agrego al recorrido y a la pila
        if (hijo >= 0) {
            pred[hijo] = tope;
            orden.push_back(hijo);
            pila.push_back(hijo);
        }else{
            //Sino lo saco de la pila, y lo marco como visitado
            visit[pila.back()] = true;
            pila.pop_back();
        }
    }

    return orden;
}

Vertice obtenerHijo(vector<Vertice> &pila, vector<Vertice> &padre, vector<bool> &visit) {
    Vertice res = -1;
    Vertice tope = pila[pila.size()-1];

    for (int i = 0; i < padre.size(); i++) {
        if (padre[i] == tope && !estaEnPila(pila, i) && !visit[i]) {return i;}
    }

    return res;
}

bool estaEnPila(vector<Vertice> &pila, Vertice v) {
    for (int i = 0; i < pila.size(); i++) {
        if (pila[i] == v) {return true;}
    }
    return false;
}

vector<Vertice> agm_prim (Grafo &G) {
    vector<bool> visitado = vector<bool>(G.size(), false);
    vector<float> distancia = vector<float>(G.size(), INFTY);
    vector<Vertice> padre = vector<Vertice>(G.size(), -1);

    //Arranco en el nodo 0
    Vertice s = 0;
    distancia[s] = 0;
    visitado[s] = true;

    //Proceso vecinos de s inicial
    for (Vecino v : G[s]) {
        distancia[v.dst] = v.peso;
        padre[v.dst] = s;
    }

	// Esquivo hacer O(n) en la guarda
	int cantVisitados = 1;
    while (cantVisitados < G.size()) { 
        //Obtiene el indice del minimo elemento del arreglo, sin visitar
        int e = obtenerIndiceMin(distancia, visitado);
        visitado[e] = true;
		cantVisitados++;

        //Para cada vecino, actualizo la distancia y su padre
        for (Vecino v : G[e]) {
            if (distancia[v.dst] > v.peso && !visitado[v.dst]) {
                distancia[v.dst] = v.peso;
                padre[v.dst] = e;
            }
        }
    }
    return padre;
}

int obtenerIndiceMin(vector<float> &distancia, vector<bool> &visitado) {
	int minimo = -1;

    for (int i = 0; i < distancia.size(); i++) {
        if (!visitado[i]) {
            if (distancia[i] < distancia[minimo] ||  minimo == -1) {minimo = i;}
        }
    }

    return minimo;
}

float obtenerPesoArista(Grafo &G, Vertice i, Vertice j) {
    for (Vecino v : G[i]) {
        if (v.dst == j) {return v.peso;}
    }
    return 0;
}

bool todosVisitados(vector<bool> &visitado) {
	for (bool v : visitado) {
		if (!v) {return false;}
	}
	return true;
}

// Heuristica de AGM basada en Kruskal, no esta terminada porque se complica implementar usando struct Vecino
/*
vector<int> altura = vector<int>(G.size(), 0);
vector<int> padre = vector<int>(G.size(), 0);

int uf_find(int x) {
	if (padre[x] != x) {
		padre[x] = find(padre[x]);
	}
	return padre[x];
}

void uf_union(x, y) {
	x = find(x);
	y = find(y);

	if (altura[x] < altura[y]) {
		padre[x] = y;
	}else{
		padre[y] = x;
	}
	if (altura [x] = altura [y]) {altura[x] += 1};
}

//Heuristica AGM basada en Kruskal
int heuristica_agm_kruskal (Grafo G, vector<int> &circuito) {
    int peso_circuito = 0;

	for (int i = 0; i < n; i++) {
		altura[i] = 1;
		padre[i] = i;
	}

	//No funciona con la estructura de Vecino, necesitamos una lista de aristas.

	return peso_circuito;
}
*/
