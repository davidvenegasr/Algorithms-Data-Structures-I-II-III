//
// Created by daredevil on 26/10/19.
//


#ifndef CUADRADO_HPP
#define CUADRADO_HPP

template<class C>
C cuadrado(C a){
    return a * a;
}

#endif

#ifndef CONTINE_HPP
#define CONTINE_HPP

template <class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e){
    bool res = false;
    for(auto i:c){
        if (i == e)
        res = true;
    }
    return res;
}

#endif

#ifndef ESPREFIJO_HPP
#define ESPREFIJO_HPP

template <class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    bool res = false;
    if (a.size() < b.size()) {
        if(a[0] == b[0])
            res = true;
    }
    return res;
}

#endif

#ifndef MAX_HPP
#define MAX_HPP

template <class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem max = c[0];
    for (Elem i: c){
        if (i>max)
            max = i;
    }
    return max;
}



#endif

