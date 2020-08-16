#include "graph.h"
#include "hagm.h"
#include "hvmc.h"
#include "random"

#ifndef MHEUR
#define MHEUR

//Busqueda local tradicional
Ciclo busqLocal2opt (Grafo &G);
//Movimiento 2opt
Ciclo swap2opt(Ciclo &cicloH, Vertice i, Vertice j);

//Tabu Search con memoria
//  mem = ciclos -> Memoria basada en últimas soluciones
//  mem = swap   -> Memoria basada en estructura (aristas)
Peso tabuSearch(Grafo &G, Ciclo &ciclo, ts_mem_t mem);

//Obtiene los ciclos que conforman una vecindad (mejoran el ciclo actual)
//[Para memoria basada en estructura (aristas)]
vector<Ciclo> obtenerVecindad_swaps(Grafo &G, Ciclo &ciclo, vector<Swap> memoria, int indiceMem, float porc = 0.1);
//Obtiene el mejor ciclo de una vecindad
//[Para memoria basada en estructura (aristas)]
Peso obtenerMejorCiclo_swaps(Grafo &G, vector<Ciclo> &vecindad, Ciclo &ciclo);
//Verifica si una arista esta en memoria
//[Para memoria basada en estructura (aristas)]
bool enMemoria_swaps(Swap swap, vector<Swap> &memoria);

//Obtiene los ciclos que conforman una vecindad (mejoran el ciclo actual)
//[Para memoria basada en últimas soluciones]
vector<Ciclo> obtenerVecindad_ciclos(Grafo &G, Ciclo &ciclo, float porc = 0.1);
//Obtiene el mejor ciclo de una vecindad
//[Para memoria basada en últimas soluciones]
Peso obtenerMejorCiclo_ciclos(Grafo &G, vector<Ciclo> &vecindad, vector<Ciclo> &memoria, Ciclo &ciclo);
//Verifica si un ciclo esta en memoria
//[Para memoria basada en últimas soluciones]
bool enMemoria_ciclos(Ciclo &ciclo, vector<Ciclo> &memoria);

//Verfica los criterios de parada por iteraciones o tiempo
bool criterioParada(int iterT, int iterSM, chrono::steady_clock::time_point tiempoInicio);

int randomInt(int tope, int base);
bool seleccionaRandom(float porc);

#endif