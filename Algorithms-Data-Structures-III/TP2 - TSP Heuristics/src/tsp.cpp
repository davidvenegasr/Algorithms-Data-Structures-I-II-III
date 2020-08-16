#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <set>
#include <map>

#include "graph.h"
#include "hagm.h"
#include "hvmc.h"
#include "mheur.h"
#include "hamc.h"

using namespace std;

int n_H2 = 0;

//PARAMETROS GLOBALES INICIALIZADOS
//Maximas iteraciones para tabuSearch
int MAX_ITER = 100000;
//Maximas iteraciones sin mejora para tabuSearch
int MAX_ITER_SM = 10000;
//Maximo tiempo antes de terminar tabuSearch (en milisegundos), 0: desactivado
double MAX_TIEMPO_MS = 30000;
//Largo de memoria para tabuSearch
int MEM_SIZE = 50;
//Porcentaje de vecindad (de 0 a 1)
float PORC_VECINDAD = 0.1;

// ----------------- START Funciones in/out ---------------------
Grafo leerGrafo(bool dirigido = false) {
    int n, m;
    cin >> n >> m;
    Grafo G(n, vector<Vecino>());
    for (int i = 0; i < m; i++) {
        int v, w;
        float peso;
        cin >> v >> w >> peso;
        G[v-1].push_back(Vecino(w-1, peso));
        if (!dirigido) {G[w-1].push_back(Vecino(v-1, peso));}
    }
    return G;
}

Grafo_lst_inc leerGrafo_lst_inc(bool dirigido = false) {
    int n, m;
    cin >> n >> m;
    n_H2 = n;
    Grafo_lst_inc G;
    for (int i = 0; i < m; i++) {
        int v, w;
        float peso;
        cin >> v >> w >> peso;
        Arista a = Arista(v-1, w-1, peso);
        G.push_back(a);
        if (dirigido) {G.push_back(Arista(w-1, v-1, peso));}
    }
    return G;
}
// ----------------- END Funciones in/out ---------------------


//--------------------------------------------MAIN-------------------------------------------------------
// Recibe por parámetro qué algoritmos utilizar para la ejecución separados por espacios.
// Imprime por clog la información de ejecución de los algoritmos.
// Imprime por cout el resultado de algun algoritmo ejecutado.
int main(int argc, char** argv)
{
	// Leemos el parametro que indica el algoritmo a ejecutar.
	map<string, string> algoritmos_implementados = {
		{"H1", "Heurisitca 1"}, {"H2", "Heuristica 2"}, {"HAGM", "Heuristica AGM"}, {"METAH1", "Metaheurisitca 1"}, {"METAH2", "Metaheuristica 2"} 
	};

	// Verificar que el algoritmo pedido exista.
	if (argc < 2 || algoritmos_implementados.find(argv[1]) == algoritmos_implementados.end())
	{
		cerr << "Algoritmo no encontrado: " << argv[1] << endl;
		cerr << "Los algoritmos existentes son: " << endl;
		for (auto& alg_desc: algoritmos_implementados) cerr << "\t- " << alg_desc.first << ": " << alg_desc.second << endl;
		return 0;
	}

	string algoritmo = argv[1];

	// Verificar que parametros usa.
	if (algoritmo == "METAH1" || algoritmo == "METAH2") {
		if (argc > 2 && argv[2] != "") { MAX_ITER = stoi(argv[2]); }
		if (argc > 3 && argv[3] != "") { MAX_ITER_SM = stoi(argv[3]); }
		if (argc > 4 && argv[4] != "") { MAX_TIEMPO_MS = stoi(argv[4]); }
		if (argc > 5 && argv[5] != "") { MEM_SIZE = stoi(argv[5]); }
		if (argc > 6 && argv[6] != "") { PORC_VECINDAD = stof(argv[6]); }
	}

    Grafo G;
    Grafo_lst_inc G_lst_inc;

    // Leemos el input.
     if (algoritmo != "H2"){
         G = leerGrafo(false);
     }else{
         G_lst_inc = leerGrafo_lst_inc(false);
     }

    // Ejecutamos el algoritmo y obtenemos su tiempo de ejecución.
	float optimum;
	vector<int> circuito;
	optimum = INFTY;

	auto start = chrono::steady_clock::now();
	if (algoritmo == "H1")
	{
		optimum = largo_heuristica_vecinoMasCercano(G, circuito);
	}
	else if (algoritmo == "H2")
	{
		optimum = heuristica_aristaMasCorta(G_lst_inc, n_H2, circuito);
	}
	else if (algoritmo == "HAGM")
	{
		optimum = heuristica_agm(G, circuito);
	}
	else if (algoritmo == "METAH1")
	{
		optimum = tabuSearch(G, circuito, ts_mem_t::ciclos);
	}
	else if (algoritmo == "METAH2")
	{
        optimum = tabuSearch(G, circuito, ts_mem_t::swaps);
	}

	auto end = chrono::steady_clock::now();
	double total_time = chrono::duration<double, milli>(end - start).count();

	// Imprimimos el tiempo de ejecución por stderr.
	clog << total_time << endl;

    // Imprimimos el resultado por stdout.
    cout << (algoritmo == "H2" ? circuito.size() : G.size()) << " " << optimum << endl;
    for (int i = 0; i < circuito.size(); i++) {
        cout << circuito[i] + 1 << " ";
    }
	cout << endl;
	
    return 0;
}
