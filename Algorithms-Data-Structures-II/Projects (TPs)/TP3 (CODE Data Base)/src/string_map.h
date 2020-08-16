#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    string_map(const string_map<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */
    string_map& operator=(const string_map& d);
    
    /**
    OPERADOR ASIGNACION
     */
    bool operator==(const string_map<T>& d);
    bool operator==(const string_map<T>& d) const;

    /**
    DESTRUCTOR
    **/
    ~string_map();

    /**
    INSERT
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair<string, T>&);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string &key) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
    const T& at(const string& key) const;
    T& at(const string& key);

    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    void erase(const string& key);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &key);
    
    
    //Claves de un dict 
    set<string> claves();

private:

    struct Nodo {

        Nodo(const T& v): siguientes(254, nullptr), definicion(new T(v)) {};
        Nodo(): siguientes(254, nullptr), definicion(nullptr) {};
        vector<Nodo*> siguientes;
        T* definicion;
        bool _isEndOfWord;

    };

    Nodo* _raiz;
    int _size;
    set<string> _claves;

    Nodo* copiarTrie(Nodo *actual){
        Nodo *nuevo = new Nodo;
        if (actual->definicion != nullptr) {
            nuevo->definicion = new T(*actual->definicion);
        }
        for (int i = 0; i < actual->siguientes.size(); i++) {
            if (actual->siguientes[i] != nullptr) {
                nuevo->siguientes[i] = copiarTrie(actual->siguientes[i]);
            }
        }
        return nuevo;
    };
    void deleteTrie(Nodo* raiz);
    //bool igualarNodos( const Nodo* raiz1, const Nodo* raiz);
    bool igualarNodos(const Nodo* raiz1, const Nodo* raiz2) const {
        const Nodo* actual = raiz1;
        const Nodo* actual2 = raiz2;
        if (raiz1 == nullptr){
            if (raiz2 == nullptr){
                return true;
            } else {
                return false;
            }
        }
        if (actual->definicion != actual2->definicion) {
            return false;
        } else {
            for (int i = 0; i < actual->siguientes.size(); i++) {
                if (actual->siguientes[i] != nullptr && actual->siguientes[i] != nullptr) {
                    if (!igualarNodos(actual->siguientes[i], actual2->siguientes[i])) {
                        return false;
                    } else {
                        return false;
                    }
                } else {
                    return actual->siguientes[i] == nullptr && actual->siguientes[i] == nullptr;
                }
            }
        }
        return true;
    }
};

#include "string_map.hpp"

#endif // STRING_MAP_H_