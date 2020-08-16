#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    prim = nullptr;
    ult = nullptr;
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l; //!consultar
}

template <typename T>
Lista<T>::~Lista() {
    destruirNodos();
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* nuevo = new Nodo(elem);

    if (prim){
        nuevo->sig = prim;
        nuevo->ant = ult;
        prim->ant = nuevo;
        ult->sig = nuevo;
        prim = nuevo;
    } else {
        prim = nuevo;
        ult = nuevo;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* nuevo = new Nodo(elem);

    if (!prim){
        prim = nuevo;
        ult = nuevo;
    } else {
        nuevo->sig = prim;
        nuevo->ant = ult;
        prim->ant = nuevo;
        ult->sig = nuevo;
        ult = nuevo;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {

    Nodo* temp = prim;
    for(int j = 0; j < i; j++){
        temp= temp->sig;
    }
    if (longitud() == 1){
        prim = nullptr;
        ult = nullptr;
        delete(temp);
    } else {

        if (temp == prim) {
            prim = temp->sig;
            prim->ant = temp->ant;
            ult->sig = temp->sig;
            delete (temp);
        } else if (temp == ult) {
            ult = temp->ant;
            prim->ant = temp->ant;
            ult->sig = temp->sig;
            delete (temp);
        } else {
            Nodo *act = temp->ant;
            act->sig = temp->sig;
            act = temp->sig;
            act->ant = temp->ant;
            delete (temp);
        }
    }
}

template <typename T>
int Lista<T>::longitud() const {
    // Completar
    int len = 0;
    Nodo* actual = prim;
    if(actual!= nullptr) {
        do {
            actual = actual->sig;
            len++;
        } while (actual != prim);
    }
    return len;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    Nodo* actual = prim;
    for(int j = 0; j < i; j++){
        actual->sig = actual;
    }
    return actual->valor;

}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = prim;
    for(int j = 0; j < i; j++){
        actual= actual->sig;
    }
    return actual->valor;
}

template <typename T>void Lista<T>::mostrar(ostream& o) {
    // Completar
}

template <typename T>
void Lista<T>::copiarNodos(const Lista& o) {
     if(o.longitud()>0) {
         Nodo *actual = o.prim;
         if (o.longitud() == 1) {
             agregarAtras(iesimo(0));
         } else {
             do {
                 agregarAtras(actual->valor);
                 actual = actual->sig;
             } while (actual != o.prim);
         }
     }
}
template <typename  T>
void Lista<T>::destruirNodos(){
    int i = longitud();
    Nodo* actual = prim;
    while (i>0){
        Nodo* siguiente = actual->sig;
        eliminar(i);
        actual = siguiente;
        i--;
    }

}