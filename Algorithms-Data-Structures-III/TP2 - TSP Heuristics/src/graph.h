#ifndef GRAPH
#define GRAPH

#include <vector>
#include <cfloat>
#include <chrono>

using namespace std;

// Definimos las estructuras de representación de grafos
typedef int Vertice;

typedef float Peso;
const Peso INFTY = FLT_MAX;

struct Vecino {
	// PARA NO OLVIDARME: dst es el índice den G[]. ej.: si dst = 6, en realidad es el vertice 7, pero obtenemos sus datos haciendo G[6]
    Vertice dst;
    Peso peso;
    Vecino(Vertice d, Peso p) : dst(d), peso(p) {}
};

typedef vector<Vertice> Ciclo;

typedef vector<vector<Vecino>> Grafo;

/** Representacion de grafo mediante Lista de incidencia */
struct Arista{
    Vertice src;
    Vertice dst;
    Peso peso;
    Arista() {src=0; dst=0; peso=0;}
    Arista(Vertice s, Vertice d, Peso p) : src(s), dst(d), peso(p) {}
    bool operator<(const Arista &a) const {
        return (peso <= a.peso);
    }
    bool operator==(const Arista &a) const {
        return peso == a.peso && ((dst == a.dst && src == a.src) || (dst == a.src && src == a.dst));
    }
};
typedef vector<Arista> Grafo_lst_inc ;

//Tabu-search memory type (Para nombrar el tipo de memoria que se va a usar en Tabu-search)
enum ts_mem_t {ciclos, swaps};
//Tipo para guardar las aristas ya visitadas en METAH2
typedef pair<Arista,Arista> Swap;

//PARAMETROS GLOBALES
//Maximas iteraciones para tabuSearch
extern int MAX_ITER;
//Maximas iteraciones sin mejora para tabuSearch
extern int MAX_ITER_SM;
//Maximo tiempo antes de terminar tabuSearch (en milisegundos), 0: desactivado
extern double MAX_TIEMPO_MS;
//Largo de memoria para tabuSearch
extern int MEM_SIZE;
//Porcentaje de vecindad (de 0 a 1)
extern float PORC_VECINDAD;

#endif
