//
// Created by daredevil on 26/10/19.
//

#include "Diccionario.hpp"

#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP

template<class T>
class Multiconjunto{
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);
    bool operator<=(Multiconjunto<T> otro);

private:
    Diccionario<T, int> _elems;

};

template<class T>
Multiconjunto<T>::Multiconjunto(): _elems() {
}

template<class T>
void Multiconjunto<T>::agregar(T x){
    if(_elems.def(x)){
        _elems.definir(x,_elems.obtener(x)+1);
    } else
        _elems.definir(x,1);
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x){
    int res = 0;
    if(_elems.def(x))
        res = _elems.obtener(x);
    return res;
}
template<class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) {
    bool res = true;
    for(auto i: _elems.claves()) {
        if (_elems.obtener(i) > otro.ocurrencias(i))
            res = false;
    }
    return res;
}

#endif //SOLUCION_MULTICONJUNTO_HPP
