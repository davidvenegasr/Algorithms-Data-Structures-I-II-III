#include "Tabla.h"

/**
 * \complexity: O(#campos^2*|nc|) = O(|nc|)
 */
Tabla::Tabla(const set<NombreCampo> &campos, const NombreCampo &clave):
    _conjRegistros(), _diccCamposXClave(), _conjCampos(campos) {

    _campoClave = clave;

    //El invariante de rep de Tabla dice que los NC de idXCampo deben estar ordenados
    // lexicograficamente de menor a mayor
    // (similar a lo que sucede con el inv de rep en _celdas de Registro)

    vector<NombreCampo> vectorDeNCs;    //Creo un vector para ordenar a todos los nc
    // int auxIt = 0;                      // de menor a mayor lexicograficamente
    for (NombreCampo nc : campos){      //Vuelco a "campos" en el vector
        vectorDeNCs.push_back(nc);
        //auxIt++;
    }
    sortStrings(vectorDeNCs);       //Ordeno el Vector

    int id = 0;
    for (NombreCampo nc : vectorDeNCs){             //Inserto los nc ya ordenados en el dicc
        _idXCampo.insert(make_pair(nc, id));                   //con su correspondiente id
        id++;
    }
}

Tabla::Tabla(const Tabla& t) {
    _campoClave = t._campoClave;
    _conjCampos = t._conjCampos;
    _idXCampo = t._idXCampo;
    _diccCamposXClave = t._diccCamposXClave;
    _conjRegistros = t._conjRegistros;
}

bool const Tabla::operator==(const Tabla &t) const{
     bool a = _campoClave == t._campoClave;
     bool b = _conjCampos == t._conjCampos;
     bool c = _idXCampo == _idXCampo;
     bool d = _diccCamposXClave == t._diccCamposXClave;
     bool e = _conjRegistros == t._conjRegistros;
     return a && b && c && d && e;
}


void swap(vector<string> &vec, int a, int b){
    string aux = vec[a];
    vec[a]=vec[b];
    vec[b]=aux;
}

/**
 * \complexity: O(|vec|^2*|nc|)
 */
void Tabla::sortStrings (vector<string> &vec){
    for (int i = 0; i < vec.size()-1; ++i) {
        int min = i;
        for (int j = i+1; j < vec.size(); ++j) {
            if (vec[j] < vec[min]){
                min = j;
            }
        }
        swap(vec,i,min);
    }
}

/**
 * \complexity: O(copy(registro)) = O(|nc|+|v|)
 */
void Tabla::insertar(const Registro &reg) {
    auto itNuevo =_conjRegistros.insert(reg);
    if(itNuevo.second){
        Valor valorClaveDeReg = reg[_campoClave];
        _diccCamposXClave.insert(make_pair(valorClaveDeReg, itNuevo.first));
    }
    /*linear_set<Registro>::iterator itNuevo = _conjRegistros.insert(reg).first;
    Valor val = reg[_campoClave];
    _diccCamposXClave.insert(make_pair(val, itNuevo));   //ERROR QUE NO TIENE SENTIDO :C*/
}

/**
 * \complexity: O(|v|)
 */
void Tabla::borrar(const Valor &val) {
    if (_diccCamposXClave.count(val)){
    auto itBorrarDeConj = _diccCamposXClave.at(val);
    _diccCamposXClave.erase(val);
    _conjRegistros.erase(itBorrarDeConj);
    }
}

/**
 * \complexity: O(#campos) = O(1)
 */
set<NombreCampo> Tabla::campos() const {
    return _conjCampos;
}

/**
 * \complexity: O(#registros*(|nc| + |v|))  //Podriamos mejorarlo pasando una ref
 */
linear_set<Registro> Tabla::registros() const {
    return _conjRegistros;
}

/**
 * \complexity: O(|nc|)
 */
NombreCampo Tabla::clave() const {
    return _campoClave;
}

/**
 * \complexity: O(|nc|)
 */
int Tabla::obtenerNroCampo(const NombreCampo &nc) {
    return _idXCampo[nc];
}

/**
 * \complexity: O(|nc| + |v|) *mala complejidad
 */
/*Registro &Tabla::camposXClave(const Valor &val) const{
    auto it = _diccCamposXClave.at(val);
    static Registro aux = *it;
    return aux;
}*/

/**
 * \complexity: O(|v|)
 */
const Registro& Tabla::camposXClave(const Valor &val) const{
    static Registro res;
    if (_diccCamposXClave.count(val) == 1){
        return *_diccCamposXClave.at(val);
    }
    return res;
    // No estoy seguro de si esta funcion esta bien
    // Para mi deberia ir sin el const inicial
    // Si algo anda mal, ver esta funcion jajaja
}
