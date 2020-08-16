#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include <math.h>
#include<iostream>

using namespace std;

vector<int> rotar(vector<int> v) {
    vector<int> res;
    for (int i = 0; i < v.size(); i++) {
        res.push_back(v[v.size() - i - 1]);
    }
    return res;
}

int busquedaBinaria(vector<int> v, int x) {
    int desde = 0;
    int hasta = v.size();
    int res = -1;
    bool ascendente = true;
    if (v[0] > v[1]) {
        v = rotar(v);
        ascendente = false;
    }
    while (desde <= hasta) {
        int medio = desde + (hasta - desde) / 2;
        if (v[medio] == x) {
            //encontre el elemento
            if (!ascendente) {
                res = v.size() - medio - 1;
            } else {
                res = medio;
            }
        }
        if (v[medio] < x) {
            desde = medio + 1; //esta en la mitad derecha
        } else {
            hasta = medio - 1; //esta en la mitad izquierda
        }
    }
    return res;
}

int busquedaLineal(vector<int> v, int x, int desde, int hasta) {
    int res = -1;
    for (int i = desde; i <= hasta; i++) {
        if (v[i] == x) {
            res = i;
        }
    }
    return res;
}
bool esCreciente (vector<int> v){
    bool res = false;
    if(v.size()==1){
        res=true;
    } else if (v[0]<v[1]){
        res=true;
    }
    return res;
}
int busquedaJumpSearch(vector<int> v, int x) {
    int res = -1;
    int sqrt_v = sqrt((float) v.size());
    int i = 0;
    int stepback= 0;
    if (!v.empty()){
        if (!esCreciente(v)) {
            i=v.size()-1;
            while (v[i] < x) {
                i -= sqrt_v;
            }
            stepback = i + sqrt_v;
            res = busquedaLineal(v, x, i, stepback);
        }else {
            while (v[i] < x && i < v.size()) {
                i += sqrt_v;
            }
            stepback = i - sqrt_v;
            res = busquedaLineal(v, x, stepback, i);
        }
    }
    return res;
}

int buscar(vector<int> v, int x){
    //return busquedaBinaria(v, x);
    return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    using namespace std;
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC/1000);
    return elapsed_secs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> v){
    int res = -1;
    if(v.size()==1){
        res = 0;
    } else if (v.size() == 2) {
        res = (v[0] < v[1] ? 1 : 0);
    } else {
        for (int i=0; i < v.size()-2; i++){
            if( i==0 && v[i]>v[i+1]){           // caso borde inicial
                res = i;
            }
            if( i==v.size()-1 && v[i]>v[i-1]){  // caso borde final
                res = i;
            }
            if (v[i]<=v[i+1]){
                if (v[i+1]>=v[i+2]){
                    res = i+1;
                }
            }
        }
    }
    return res;
}

int puntoFijo(vector<int> v){
    int res = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == i) {
            res = i;
            break;
        }
    }
    return res;
}

int encontrarRotado(vector<int> v, int x){
    return busquedaLineal(v, x, 0, v.size() -1);
}

int menorMasGrande(vector<int> v, int x){
    int res = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= x) {
            res = i;
            break;
        }
    }
    return res;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
    vector <int> res = {};
    int pivote = 0;
    int contador = 0;
    if (!esCreciente(v))
        v = rotar(v);
    if (k < v.size()) {
        for (int i = 0; i < v.size() && contador < k; i++){
            if (v[i] == x) { // si  pertenece al vector
                pivote = i;
                for (int j = 0; j <= k && contador < k; j++) {
                    int lowBound = (pivote > k) ? k: pivote;
                    int highBound = (v.size() - pivote > k) ? k: v.size() - pivote;
                    if (abs(v[pivote - lowBound + j] - x) < abs(v[pivote + highBound - j])) {
                        res.push_back(v[pivote - lowBound + j]);
                        contador++;
                    } else if (j == k) {
                        for ( int m = 0; contador < k; m++){
                            res.push_back(v[pivote+m]);
                            contador++;
                        }
                    }
                }
            }
            else if (v[i] > x) { //si x no pertenece al vector
                pivote = i - 1;
                for (int p = 0; p < v.size() && contador < k; p++) {
                    for (int j = 0; j <= k && contador < k; j++) {
                        int lowBound = (pivote > k) ? k : pivote;
                        int highBound = (v.size() - pivote > k) ? k : v.size() - pivote;
                        if (abs(v[pivote - lowBound + j] - x) < abs(v[pivote + highBound - j])) {
                            res.push_back(v[pivote - lowBound + j]);
                            contador++;
                        } else if (j == k) {
                            for (int m = 0; contador < k; m++) {
                                if (v[pivote + m] = x)
                                    m++;
                                res.push_back(v[pivote + m]);
                                contador++;
                            }
                        }
                    }
                }
            }
        }
    } else {
        res = v;
    }
    return res;
}
