#include "Diccionario.h"

/* Completar */

Diccionario::Diccionario(): pares() {}

Diccionario::Asociacion::Asociacion(Clave k, Valor v): _clave(k), _valor(v){};

void Diccionario::definir(Clave k, Valor v) {
    for(int i = 0; i < pares.size(); i++){
        if (pares[i]._clave == k){
            pares[i]._clave = k;
            pares[i]._valor = v;
            return;
        }
    }
    Asociacion a(k,v);
    pares.push_back(a);
}

bool Diccionario::def(Clave k) const {
    for(int i = 0; i < pares.size(); i++){
        if (pares[i]._clave == k){
            return true;
        }
    }
    return false;
}

Valor Diccionario::obtener(Clave k) const {
    for(int i = 0; i < pares.size(); i++){
        if (pares[i]._clave == k){
            return pares[i]._valor;
        }
    }
}

void Diccionario::borrar(Clave k) {
    for(int i = 0; i < pares.size(); i++){
        if (pares[i]._clave == k){
            pares.erase(pares.begin()+i);
        }
    }
}

std::vector<Clave> Diccionario::claves() const {
    std::vector<Clave> claves;
    for(int i = 0; i < pares.size(); i++){
        claves.push_back(pares[i]._clave);
    }
    return claves;
}

bool esPermutacion(std::vector<Clave> c, std::vector<Clave> p){
     for(Clave i:c){
         bool b = false;
         for(Clave j:p)
             if (i = j)
                 b = true;
         if (b == false)
             return false;
     }
    return true;
}

bool Diccionario::operator==(Diccionario o) const {
    bool res = true;
    std::vector<Clave> claves = Diccionario::claves();
    if (!esPermutacion(claves, o.claves())) {
        res = false;
    }
    for (Clave c: claves) {
        if (obtener(c) != o.obtener(c))
            res = false;
    }
    return res;
}

Diccionario Diccionario::operator||(Diccionario o) const {
    Diccionario n = Diccionario();
    std::vector<Clave> claves = Diccionario::claves();
    for (Clave i: claves){
        n.definir(i, Diccionario::obtener(i));
    }
    std::vector<Clave> claves2 = o.claves();
    for (Clave j: claves2){
        if(!n.def(j))
            n.definir(j, o.obtener(j));
    }
    return n;
}
Diccionario Diccionario::operator&&(Diccionario o) const {
    Diccionario n = Diccionario();
    std::vector<Clave> claves = Diccionario::claves();
    for (Clave i: claves){
        if(o.def(i))
        n.definir(i, Diccionario::obtener(i));
    }
    return n;
}