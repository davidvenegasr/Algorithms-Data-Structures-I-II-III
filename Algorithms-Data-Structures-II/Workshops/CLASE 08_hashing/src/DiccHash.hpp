#include "DiccHash.h"

/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash(): _tabla(100), _tam(100), _cant_claves(0) {}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {
    for(list<Asociacion> sec: _tabla){
        sec.clear();
    }
}


/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string& clav) const {
    unsigned int pos = fn_hash(clav);
    list<Asociacion> listA = _tabla[pos];
    for(Asociacion a: listA){
        if(a.clave == clav)
            return true;
    }
    return false;
}

/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 *
 * Pasos a seguir para redimensionar la tabla:
 * - Crear una tabla del doble de tamaño de la original.
 * - Insertar todas las claves de la tabla original en la tabla nueva.
 * - Liberar la memoria reservada para la tabla original.
 */

template<class V>
void DiccHash<V>::definir(const string& clav, const V& sig) {
    unsigned int pos = fn_hash(clav);
    list<Asociacion>& listaClaves = _tabla[pos];
    if(definido(clav)){
        for(Asociacion asoc: listaClaves){
            if (asoc.clave == clav)
                asoc.valor = sig;
        }
    } else {
        Asociacion newElem;
        newElem.clave = clav;
        newElem.valor = sig;
        listaClaves.push_back(newElem);
        _cant_claves++;
    }
    if (factorCarga()> UMBRAL_FC){
        _tam = _tam * 2;
        vector<list<Asociacion>> new_tab(_tam);
        for(list<Asociacion> listaClaves: _tabla){
            for(Asociacion asoc: listaClaves) {
                int n_pos = fn_hash(asoc.clave);
                Asociacion elem;
                elem.clave = asoc.clave;
                elem.valor = asoc.valor;
                new_tab[n_pos].push_back(elem);
            }
        }
        _tabla = new_tab;
    }
}
/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V& DiccHash<V>::significado(const string& clav) {
    unsigned int pos = fn_hash(clav);
    typename list<Asociacion>::iterator it = _tabla[pos].begin();
    typename list<Asociacion>::iterator itEnd = _tabla[pos].end();
    while(it != itEnd){
        if ((*it).clave == clav) {
            return (*it).valor;
        }
        it++;
    }
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string& clav) {
    int pos = fn_hash(clav);
    typename list<Asociacion>::iterator it = _tabla[pos].begin();
    typename list<Asociacion>::iterator end = _tabla[pos].end();

    while(it != end){
        if((*it).clave == clav)
            it = _tabla[pos].erase(it);
        it++;
    }
    _cant_claves--;
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
    return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
    set<string> res;
    for(list<Asociacion> listA: _tabla){
        for(Asociacion a: listA){
            res.insert(a.clave);
        }
    }
    return res;
}

/*
 * SÓLO PARA TESTING
 */
template<class V>
float DiccHash<V>::factorCarga() const {
    return _cant_claves / _tam;
}

/*
 * SÓLO PARA TESTING
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
    unsigned int suma = 0;
    for (int i = 0; i < _tam; i++) {
        suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
    }
    return suma;
}

/*
 * Devuelve la posición de la tabla asociada a la clave dada.
 */
template<class V>
unsigned int DiccHash<V>::fn_hash(const string& str) const {
    long long int hash = 7;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        hash = hash*11 + str[i];
    }
    return hash % (long long int)_tam;
}


template<class V>
bool DiccHash<V>::Asociacion::operator==(const DiccHash::Asociacion &h1) const  {
    return h1.clave == this->clave && h1.valor == this->valor;
}
