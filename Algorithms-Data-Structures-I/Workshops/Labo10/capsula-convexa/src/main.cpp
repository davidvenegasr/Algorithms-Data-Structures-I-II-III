#include <cstdio>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <fstream>

using namespace std;
typedef float                   coordenada;
typedef vector < coordenada >       punto;


void insertionSort(vector< punto > &arr){
	//Rellenar insertion

}

void selectionSort(vector< punto > &puntos){
	//Rellenar selection
}


//Este metodo ordena el vector de puntos segun la coordenada x
//Descomentar el sort que se quiera utilizar y comentar todo el resto
void ordenar(vector< punto > &puntos){
	//Orden por default

	//insertionSort(puntos);
	//selectionSort(puntos);
}

double cross(const punto &O, const punto &A, const punto &B){ 
return (A[0] - O[0]) *1L* (B[1] - O[1]) - (A[1] - O[1]) *1L* (B[0] - O[0]); }


void convex_hull(vector< punto > &pts, vector<int> &res){
	int n=pts.size(), k = 0, k2=0;
	vector<int> res2(n);
	res.resize(n);
	for(int i=0;i<n;++i){
		while(k>=2 && cross(pts[res[k-2]],pts[res[k-1]],pts[i]) <= 0) k--;
		while (k2 >= 2 && cross(pts[res2[k2-2]], pts[res2[k2-1]], pts[i]) >= 0) k2--;
		res[k++] = i;
		res2[k2++]= i;
	}
	reverse(res2.begin()+1,res2.begin()+k2-1);
	res.insert(res.begin(),res2.begin()+1,res2.begin()+k2-1);
	res.resize(k+k2-2);
}

punto crearPunto(float c1, float c2) {
	punto p;
	p.push_back(c1);
	p.push_back(c2);
	return p;
}
int main(){
	int N;
	cout << "Ingrese la cantidad de puntos a generar: " << endl;
	cin >> N;
	vector< punto > puntos;
	vector<int> conv;


	//Se generan muchos puntos que simbolizan el obstaculo
	puntos.push_back(crearPunto(-0.75,0.0));
	puntos.push_back(crearPunto(0.75,0.0));
	for(int i=0;i<N;++i){
		float aux1=(float) rand() / (RAND_MAX) - 0.5;
		float aux2=(float) rand() / (RAND_MAX) - 0.5;
		if(aux1*aux1 + aux2*aux2 > 0.25){
			i--;
			continue;
		}
		puntos.push_back(crearPunto(aux1,aux2));
	}

	//Se ordenan los puntos segun su coordenada x, y luego se calcula la capsula convexa gracias al orden obtenido
	ordenar(puntos);
	convex_hull(puntos,conv);

	cout << "Se escribe el resultado en el archivo solucion" << endl;
	ofstream os("solucion", std::ofstream::out);

	os << conv.size() << " " << puntos.size() << endl;
	for(int i=0;i<(int)conv.size();i++)
		os << puntos[conv[i]][0] << ' ' << puntos[conv[i]][1] << endl;
	for(int i=0;i<(int)puntos.size();i++) 
		os << puntos[i][0] << ' ' << puntos[i][1] << endl;
	os.close();

	return 0;
}
