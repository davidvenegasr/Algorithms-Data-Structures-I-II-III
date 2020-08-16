
template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cantElementos(0) {
}


template <class T>
Conjunto<T>::~Conjunto() { 
    removerHijos(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    bool res = false;
    Nodo* actual = _raiz;
    while (actual != nullptr) {
        if (actual->valor == clave){
            res = true;
            break;
        } else if (actual->valor > clave) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }
    return res;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(vacio()){                              //Si el arbol esta vacio crea un nuevo nodo
        Nodo* nuevo = new Nodo(clave);
        _raiz = nuevo;
        _cantElementos++;
    } else {
        Nodo* actual = _raiz;
        while (actual != nullptr && actual->valor != clave) {
            if (actual->valor > clave) {            //Si es menor, nos fijamos el nodo izq
                if (actual->izq != nullptr) {
                    actual = actual->izq;
                } else {
                    Nodo* nuevo = new Nodo(clave);
                    actual->izq= nuevo;
                    _cantElementos++;
                }
            } else {
                if(actual->der != nullptr){         //Sino el derecho
                    actual = actual->der;
                } else{
                    Nodo* nuevo = new Nodo(clave);
                    actual->der= nuevo;
                    _cantElementos++;
                }
            }
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    removerAux(clave);
    _cantElementos--;
    return;
}

template <class T>
void Conjunto<T>::removerHijos(Nodo* nodo) {
    if(nodo != nullptr){
        removerHijos(nodo->der);
        removerHijos(nodo->izq);
        delete(nodo);
    }

}

template <class T>
void Conjunto<T>::removerAux(const T& clave) {
    Nodo *nActual = _raiz;
    Nodo *nPadre = _raiz;
    while (nActual->valor != clave) {
        nPadre = nActual;
        if (clave < nActual->valor)
            nActual = nActual->izq;
        else
            nActual = nActual->der;
    }
    if (dosHijos(nActual)) {
        T *aux = new T;
        *aux = siguiente(clave);
        removerAux(*aux);
        nActual->valor = *aux;
        delete (aux);
    } else {
        if (esSoloRaiz()) {
            _raiz = nullptr;
        } else if (esHoja(nActual)) {
            if (nPadre->der == nActual)
                nPadre->der = nullptr;
            else
                nPadre->izq = nullptr;
        } else if (unSoloHijo(nActual)) {
            if (nActual == _raiz) {
                if (nActual->der != nullptr)
                    _raiz = nActual->der;
                else
                    _raiz = nActual->izq;
            } else if (nActual->der != nullptr) {
                if (nPadre->der == nActual)
                    nPadre->der = nActual->der;
                else
                    nPadre->izq = nActual->der;
            } else {
                if (nPadre->der == nActual)
                    nPadre->der = nActual->izq;
                else
                    nPadre->izq = nActual->izq;
            }
        }
        delete (nActual);
    }
}



template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {    Nodo* actual = _raiz;
    stack<Nodo*> padres;
    while (actual != nullptr) {                     //busco el nodo de la clave
        if (actual->valor == clave){
            break;
        }
        if (actual->valor > clave) {
            padres.push(actual);
            actual = actual->izq;
        } else if (actual->valor < clave) {
            actual = actual->der;
        }
    }
    if (actual->der != nullptr){                    //Aca ya tenemos el valor y buscamos el minimo
        actual = actual->der;
        while(actual->izq != nullptr){               //buscamos el minimo
            actual = actual->izq;
        }
    } else {
        while(actual != padres.top()->izq){
            actual = padres.top();
            padres.pop();
        }
        actual = padres.top();
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while (actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while (actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cantElementos;
}

template <class T>
bool Conjunto<T>::vacio() const {
    return cardinal() == 0;
}

template <class T>
bool Conjunto<T>::esSoloRaiz() const {
    return cardinal() == 1;
}

template <class T>
bool Conjunto<T>::esHoja(Nodo* nodo) const {
    return (nodo->der == nullptr) && (nodo->izq == nullptr);
}

template <class T>
bool Conjunto<T>::unSoloHijo(Nodo* nodo) const {
    return (nodo->der != nullptr && nodo->izq == nullptr) || (nodo->der == nullptr && nodo->izq != nullptr);
}


template <class T>
bool Conjunto<T>::dosHijos(Nodo* nodo) const {
    return (nodo->der != nullptr && nodo->izq != nullptr);
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

