//
// Created by daredevil on 26/10/19.
//
#include <vector>
#include <algorithm>
#include "Templates.hpp"

#ifndef SOLUCION_DICCIONARIO_HPP
#define SOLUCION_DICCIONARIO_HPP

template <class Clave, class Valor>
class Diccionario {
public:
    std::vector<Clave> claves();
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    std::vector<Asociacion> _asociaciones;
};

template <class Clave, class Valor>
std::vector<Clave> Diccionario<Clave,Valor>::claves(){
    std::vector<Clave> c;
    std::vector<Clave> res;
    for(auto i: _asociaciones){
        c.push_back(i.clave);
    }
    int vecSize = c.size();
    for(int i = 0; i < vecSize; i++){
        Clave max = maximo< std::vector<Clave>, Clave>(c);
        res.push_back(max);
        c.erase(std::remove(c.begin(), c.end(), max), c.end());
    }
    std::reverse(std::begin(res), std::end(res));
    return res;
}

template <class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario(): _asociaciones() {
}

template <class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template <class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template <class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template <class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}


#endif //SOLUCION_DICCIONARIO_HPP
