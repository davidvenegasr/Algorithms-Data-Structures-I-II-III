template <typename T>
string_map<T>::string_map(): _raiz(nullptr), _size(0){
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

    deleteTrie(_raiz); //Borramos el trie en caso de que ya exista

    if (d._raiz != nullptr) {
        _raiz = copiarTrie(d._raiz);
        _size = d._size;
    }
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    deleteTrie(_raiz);  //Borramos recursivamente desde la raiz
}

template<typename T>
void string_map<T>::deleteTrie(Nodo *nActual) {
    if (nActual != nullptr) {
        for (int i = 0; i < nActual->siguientes.size(); i++) {
            deleteTrie(nActual->siguientes[i]);
        }
        if (nActual->definicion != nullptr) {
            delete nActual->definicion;
        }
        delete nActual;
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if (_raiz == nullptr) {
        _raiz = new Nodo();
    }
    Nodo *nActual = _raiz;
    int i = 0;
    while (i < clave.size() && nActual->siguientes[clave[i]] != nullptr) { //Recorre los nodos que existen
        Nodo *sig = nActual->siguientes[clave[i]];
        nActual = sig;
        i++;
    }
    if (i == clave.size() && nActual->definicion != nullptr) {
        return *nActual->definicion;
    } else {
        while (i < clave.size()) { //Define los que faltan
            Nodo *nuevo = new Nodo;
            nActual->siguientes[clave[i]] = nuevo;
            nActual = nuevo;
            i++;
        }
        nActual->definicion = new T();
        _size++;
        return *nActual->definicion;
    }
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& par){
    string clave = par.first;
    int clave_len = clave.length();
    if (_raiz == nullptr){
        _raiz = new Nodo();
    }
    int pos = 0;
    Nodo* nActual = _raiz;
    for( int i = 0; i < clave_len; i++){
        pos = (int)clave[i];
        if(nActual->siguientes[pos] == nullptr){
                Nodo* nuevo = new Nodo();
                nActual->siguientes[pos] = nuevo;
                nActual = nuevo;
        } else {
            nActual = nActual->siguientes[pos];
        }
    }
    if (nActual->definicion != nullptr) { //Agrega el significado
        *(nActual->definicion) = par.second;
    } else {
        nActual->definicion = new T(par.second);
    }
    _size++;
}



template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* nActual = _raiz;
    int clave_len = clave.length();
    for( int i = 0; i < clave_len; i++){
        int pos = (int)clave[i];
        if(nActual == nullptr){
            return 0;
        } else {
            nActual = nActual->siguientes[pos];
        }
    }
    if (nActual->definicion == nullptr)
        return 0;
    else
        return 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* nActual = _raiz;
    int clave_len = clave.length();
    for(int i = 0; i < clave_len; i++){
        int pos = (int)clave[i];
            nActual = nActual->siguientes[pos];
    }
    return *nActual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = _raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = _raiz;
    Nodo* ultimo = _raiz;
    int ultPos = 0;
    for (int i = 0; i < clave.size(); i++) {
        if ((cant(actual->siguientes) > 1 || actual->definicion != nullptr) && ultPos < clave.size() - 1) {
            ultimo = actual;
            ultPos = i;
        }
        actual = actual->siguientes[clave[i]];
    }
    delete actual->definicion;
    _size--;
    actual->definicion = nullptr;
    if (cant(actual->siguientes) == 0) {
        Nodo *siguiente = ultimo->siguientes[clave[ultPos]];
        ultimo->siguientes[clave[ultPos]] = nullptr;
        ultimo = siguiente;
        ultPos++;
        while (ultPos < clave.size()) {
            siguiente = ultimo->siguientes[clave[ultPos]];
            delete ultimo;
            ultimo = siguiente;
            ultPos++;
        }
        delete ultimo;
    }
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template<typename T>
int cant(vector<T *> hijos) {
    int res = 0;
    for (int i = 0; i < hijos.size(); i++) {
        if (hijos[i] != nullptr) {
            res++;
        }
    }
    return res;
}