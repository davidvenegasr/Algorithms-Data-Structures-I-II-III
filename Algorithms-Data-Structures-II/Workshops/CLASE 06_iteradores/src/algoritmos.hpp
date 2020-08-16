#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

#include <iostream>
#include <iomanip>

// Completar con las funciones del enunciado
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::const_iterator  it = c.begin();
    typename Contenedor::const_iterator  min = it;
    for (; it != c.end();it++){
        if (*it < *min){
            min = it;
        }
    }
    return *min;
}
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::const_iterator it = c.begin();
    double size = 0.0;
    double res = 0.0;
    for (it; it != c.end();it++){
        res = res + *it;\
        size++;
        }
    std::cout << size;
    std::cout << res;
    return res/size;
}



template<class Iterator>
typename Iterator::value_type minimoIter( const Iterator& desde, const Iterator& hasta){
    Iterator itMin = desde;
    for (Iterator it = desde; it != hasta; it++){
        itMin = *it  < *itMin ? it : itMin ;
    }
    return *itMin;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    Iterator it = desde;
    double size = 0.0;
    double res = 0.0;
    while(it!=hasta){
        res = res + *it;
        size++;
        it++;
    }
    std::cout << size;
    std::cout << res;
    return res/size;
}
template <class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    typename Contenedor::const_iterator it = c.begin();
    while (it != c.end()){
        if (*it ==elem){
            it = c.erase(it);
        } else
            it++;
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c){
    typename Contenedor::const_iterator first = c.begin();
    typename Contenedor::const_iterator last = c.end();
    for(typename Contenedor::const_iterator it = c.begin(); first != last; it++){
        if(it == last){
            first++;
            it = first;
        }
        if (*first > *it){
            return false;
        }
    }
    return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    Contenedor menores;
    Contenedor mayores;
    typename Contenedor::const_iterator it = c.begin();
    while(it != c.end()){
        if (*it < elem ){
            typename Contenedor::const_iterator m = menores.end();
            menores.insert(m, *it);
        } else {
            typename Contenedor::const_iterator m = mayores.end();
            mayores.insert(m, *it);
        }
        it++;
    }
    return std::make_pair(menores,mayores);
}


template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    typename Contenedor::const_iterator it1 = c1.begin();
    typename Contenedor::const_iterator it2 = c2.begin();
    while (it1!=c1.end() || it2!=c2.end()) {
        if (it1 == c1.end()) {
            while (it2 != c2.end()) {
                res.insert(res.end(), *it2);
                it2++;
            }
        } else if (it2 == c2.end()) {
            while (it1 != c1.end()) {
                res.insert(res.end(), *it1);
                it1++;
            }
        } else if (*it1 < *it2) {
            res.insert(res.end(), *it1);
            it1++;
        } else {
            res.insert(res.end(), *it2);
            it2++;
        }
    }
}


#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
