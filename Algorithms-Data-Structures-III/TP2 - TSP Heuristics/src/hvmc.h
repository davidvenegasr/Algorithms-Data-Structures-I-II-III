#ifndef HVMC
#define HVMC

#include "graph.h"
#include "hagm.h"

float largo_heuristica_vecinoMasCercano(Grafo &G, vector<Vertice> &circuito);
bool heuristica_vecinoMasCercano(Grafo &G, vector<Vertice> &camino);

#endif
