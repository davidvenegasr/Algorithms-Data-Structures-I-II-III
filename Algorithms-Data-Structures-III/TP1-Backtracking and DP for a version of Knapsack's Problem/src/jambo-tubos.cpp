/* TP1 - AED3 2020 - 1ER Cuatrimestre a Distancia
 	Realizado por:
 	Luis Bustamante 43/18
 	David Venegas 783/18
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
//#include <set>
#include <map>

using namespace std;

#define sin_solucion -10e6 // Valor para indicar que no hubo solución.

//CODIGO ACA
vector<int> items_weight;
vector<int> items_resistance;
int n, R_tubo; // n: cantidad de elementeo en el tubo y R_tubo: resistencia

//PROBLEMA determinar la maxima cantidad
//de productos que pueden apilarse en un tubo sin que ninguno este aplastado

// i: posicion del elemento a considerar en este nodo.
// peso_hasta: suma de los pesos de los elementos seleccionados hasta este nodo.
// cant_hasta: cantidad de elementos seleccionados hasta este nodo.
// min_resist: minima resitencia en el tubo

int FB(int i, int min_resist)
{   
	//Caso Base
	if (i==n){	
		if (min_resist<0) return -10e6;
		return 0; 	
	} 
	
	int no_agrego_i = FB(i+1, min_resist);
	int agrego_i = FB(i+1, min(items_resistance[i],min_resist-items_weight[i]));
	return max(no_agrego_i , 1 + agrego_i);
}

// i: posicion del elemento a considerar en este nodo.
// k: cantidad de elementos seleccionados hasta este nodo.
// w: suma de los elementos seleccionados hasta este nodo.
bool poda_factibilidad = true; // define si la poda por factibilidad esta habilitada.
bool poda_optimalidad = true; // define si la poda por optimalidad esta habilitada.
int MS = sin_solucion; // Mejor solucion hasta el momento.
int BT(int i, int cant_hasta, int min_resist)
{
	//Caso Base 	
	if (i==n) {
		if (min_resist < 0){
			return sin_solucion;
		}
		return cant_hasta;
	}

    // Poda por factibilidad.
    if (poda_factibilidad && min_resist < 0) return sin_solucion;

    // Poda por optimalidad.
    if (poda_optimalidad){
		bool p_resistencia = (min_resist < 0) ? false : (cant_hasta + 1 + min_resist <= MS);
		bool p_faltantes = cant_hasta + 1 + n - i <= MS;
		if (p_resistencia || p_faltantes) {
			return (min_resist < 0) ?  sin_solucion : cant_hasta;
		}
    }
	if(!min_resist<0)
		MS = max(MS,cant_hasta-1);

    // Recursión.
	int agrego_i =BT(i+1, cant_hasta+1,min(items_resistance[i],min_resist-items_weight[i]));

	int no_agrego_i = BT(i+1,  cant_hasta, min_resist);
	
	return max(agrego_i,no_agrego_i);

}

			   

vector<vector<int>> cache; // Memoria de PD.
const int UNDEFINED = -1;
// PD(i, peso_hasta): minimo cardinal de un subconjunto de {Si, ... , Sn} que sume W−w.
int PD(int i, int min_R){

	if (min_R < 0) return -10e6;

	if (i == n) return 0;

	if (cache[i][min_R] == -1){
		int no_agrego_i = PD(i+1, min_R);
		int agrego_i = 1 + PD(i+1, min(items_resistance[i], min_R-items_weight[i]));
		cache[i][min_R] = max(no_agrego_i, agrego_i);
	}
	return cache[i][min_R];
}

// Recibe por parámetro qué algoritmos utilizar para la ejecución separados por espacios.
// Imprime por clog la información de ejecución de los algoritmos.
// Imprime por cout el resultado de algun algoritmo ejecutado.
int main(int argc, char** argv)
{
	// Leemos el parametro que indica el algoritmo a ejecutar.
	map<string, string> algoritmos_implementados = {
		{"FB", "Fuerza Bruta"}, 
		{"BT", "Backtracking con podas"}, {"BT-F", "Backtracking con poda por factibilidad"}, 
		{"BT-O", "Backtracking con poda por optimalidad"},
		{"DP", "Programacion dinámica"}
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

    // Leemos el input.
    cin >> n >> R_tubo;
    items_weight.assign(n, 0);
	items_resistance.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> items_weight[i] >>  items_resistance[i];

    // Ejecutamos el algoritmo y obtenemos su tiempo de ejecución.
	int optimum;
	optimum = sin_solucion;
	auto start = chrono::steady_clock::now();
	if (algoritmo == "FB")
	{
		optimum = FB(0, R_tubo);
	}
	else if (algoritmo == "BT")
	{
		MS = sin_solucion;
		poda_optimalidad = poda_factibilidad = true;
		optimum = BT(0, 0, R_tubo);
	}
	else if (algoritmo == "BT-F")
	{
		MS = sin_solucion;
		poda_optimalidad = false;
		poda_factibilidad = true;
		optimum = BT(0, 0, R_tubo);
	}
	else if (algoritmo == "BT-O")
	{
        MS = sin_solucion;
		poda_optimalidad = true;
		poda_factibilidad = false;
		optimum = BT(0, 0, R_tubo);
	}
	else if (algoritmo == "DP")
	{
		// Precomputamos la solucion para los estados.
		cache = vector<vector<int>>(n+1, vector<int>(R_tubo+1, UNDEFINED));
		optimum = PD(0, R_tubo);
	}
	auto end = chrono::steady_clock::now();
	double total_time = chrono::duration<double, milli>(end - start).count();

	// Imprimimos el tiempo de ejecución por stderr.
	clog << total_time << endl;

    // Imprimimos el resultado por stdout.
    cout << (optimum == sin_solucion ? -1 : optimum) << endl;
    return 0;
}
