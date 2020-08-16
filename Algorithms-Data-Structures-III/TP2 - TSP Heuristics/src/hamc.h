#ifndef HAMC_H
#define HAMC_H

#include "graph.h"
#include <set>
#include <algorithm>

float heuristica_aristaMasCorta(Grafo_lst_inc &G, int n, vector<Vertice> &circuito);
bool sortByWeight(const Arista &lhs, const Arista &rhs);

//TODO: Mover la estructura Union-Find a otro archivo asi lo pueden usar todos
/*Estructura para implementar Union-Find*/
struct representante{
    int padre; 
    int altura; 
};

int find(vector<representante> &representantes, int i);
void Union(vector<representante>& representantes, int x, int y);
/* Funcion de buqueda de ciclos en un grafo*/
int esCiclo(Grafo_lst_inc &G, int max_v);

#endif //HAMC_H
