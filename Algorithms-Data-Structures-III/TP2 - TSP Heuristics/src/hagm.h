#include "graph.h"

#ifndef HAGM
#define HAGM

float heuristica_agm (Grafo &G, vector<Vertice> &circuito); 

float calcularPeso(Grafo &G, vector<Vertice> &circuito); 

vector<Vertice> camino_dfs (vector<Vertice> &padre); 

Vertice obtenerHijo(vector<Vertice> &pila, vector<Vertice> &padre, vector<bool> &visit); 

bool estaEnPila(vector<Vertice> &pila, Vertice v);

vector<Vertice> agm_prim (Grafo &G); 

int obtenerIndiceMin(vector<float> &distancia, vector<bool> &visitado);

float obtenerPesoArista(Grafo &G, Vertice i, Vertice j);

bool todosVisitados(vector<bool> &visitado);

#endif