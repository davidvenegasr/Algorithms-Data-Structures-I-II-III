#include "hvmc.h"

// Devuelve si pude o no hacer un camino hamiltoniano, y lo guardo en el vector camino.
bool heuristica_vecinoMasCercano(Grafo &G, vector<Vertice> &camino){

	vector<bool> visitado(G.size(), false);
	int indice_verticeActual = 0;
	vector<Vecino> Nodo = G[0];
	Vecino ejeMinimaDistancia = Nodo[0];
	
	// Es necesario y suficiente que salte n veces de nodo.
	while(camino.size() < G.size()) // O(|V|)
	{

		// Como uso indice_verticeActual para elegir el primer eje, debo tener al dia el vec de visitados, sino error
		visitado[indice_verticeActual] = true;

		for(int i = 0;i < Nodo.size();i++){
			if(!visitado[Nodo[i].dst]){ // Elijo un eje por el cual no hayamos pasado, sino rompemos el algoritmo
				ejeMinimaDistancia = Nodo[i];
				break;
			}
		}

		for (Vertice i = 0; i < Nodo.size();i++) // Busco el eje con menor peso, O(|E|)
		{
			Vecino eje = Nodo[i];

			if(eje.peso < ejeMinimaDistancia.peso && !visitado[eje.dst]) // Me aseguro de no formar un circuito antes de recorrer todos los ejes
			{
				ejeMinimaDistancia = eje;
			}

		}
		// Preparo las variables para la siguiente operacion
		camino.push_back(indice_verticeActual);

		Nodo = G[ejeMinimaDistancia.dst]; // Elijo el vertice al cual buscarle los mas cercanos
		indice_verticeActual = ejeMinimaDistancia.dst;
	}
	// Uno el ultimo con el primero?
	// return true, siempre es conexo el grafo
	return true;
}

float largo_heuristica_vecinoMasCercano(Grafo &G, vector<Vertice> &circuito){
	bool hayCamino = heuristica_vecinoMasCercano(G, circuito);
	return calcularPeso(G, circuito);
}
