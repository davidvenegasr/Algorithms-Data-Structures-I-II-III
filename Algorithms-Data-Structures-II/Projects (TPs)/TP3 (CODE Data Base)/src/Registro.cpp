#include "Registro.h"

Registro::Registro() : _celdas() {
}

Registro::Registro(const Registro &r) {
    this->_celdas = r._celdas;
}

Registro &Registro::operator=(const Registro &r) {
    this->_celdas = r._celdas;
    return *this;
}

bool Registro::operator==(const Registro &r) const{
    return (this->_celdas == r._celdas);
}

Registro::Celda::Celda(int id, NombreCampo nc, Valor v){
    idCampo=id;
    nombreCampo=nc;
    valor=v;
}

bool Registro::Celda::operator==(const Registro::Celda &c) const{
    return (this->idCampo == c.idCampo && this->nombreCampo == c.nombreCampo && this->valor == c.valor);
}

//Registro Registro::unirRegistro(const Registro &r1, const Registro &r2){
//}

/**
 * \complexity: O(#celdas) = O(1)
 */
set<NombreCampo> Registro::campos() const {
    set<NombreCampo> res;

    for (Celda cel : _celdas){
        res.insert(cel.nombreCampo);
    }
    return res;
}


/**
 * \complexity: O(#celdas + |campo|) = O(|campo|)
 */
Valor& Registro::operator[](const NombreCampo& campo) {
    static Valor res;
    for(auto it = _celdas.begin(); it!=_celdas.end(); it++){
        if (it->nombreCampo == campo){
            return  it->valor;
        }
    }
    //Si no lo encontro va a pasar por aca
    definir(campo, "");
    //Busco al campo recien agregado para devolver la referencia a su valor
    for(auto it = _celdas.begin(); it!=_celdas.end(); it++){
        if (it->nombreCampo == campo){
            return  it->valor;
        }
    }
    return res;
}


const Valor &Registro::operator[](const NombreCampo &campo) const {
    static Valor res;

    for (const auto& cel : this->_celdas){
        if (cel.nombreCampo == campo){
            return cel.valor;
        }
    }
    return res;
}

/**
 * \complexity: O(#celdas + |valor|) = O(|valor|)
 */
Valor Registro::valorXNroDeCampo(const int &nroCampo) const {
    Valor res;

    for (Celda cel : _celdas){
        if (cel.idCampo == nroCampo){
            res = cel.valor;
        }
    }
    return res;
}


//Invariante de registro:
// Vamos a asegurar que los idCampos estan ordenados de menor a mayor
// todos siendo numeros consecutivos
// Ej: <0,dni,40710668>,<1,lu,4318>,<2,nombre,luis>

// Y la insercion sera agregar el elemento en orden lexicografico
//  con la 1er coordenada de la tupla en 0, una vez colocada
//  en su posicion adecuada, se la numerara correctamente y
//  las siguientes tuplas se le incrementara en 1 a la misma coordenada

/**
 * \complexity: O(|campo|+|valor|+ #celdas) = O(|campo|+|valor|)
 */
void Registro::definir(const NombreCampo &campo, const Valor &v) {
    Celda celdaNueva = Celda(0, campo, v);
    if (_celdas.empty()){
        _celdas.push_back(celdaNueva);                      // agrego atras ya que esta vacio
    }else if (this->campos().count(campo) == 0){            //Si el campo existe no hago nada
        bool nuevoInsertado = false;
        for (auto it = _celdas.begin(); it != _celdas.end(); it++){
            if (!nuevoInsertado && it->nombreCampo > celdaNueva.nombreCampo){
                celdaNueva.idCampo = it->idCampo;            //cambio el idCampo del nuevo con el que estoy pisando
                _celdas.insert(it, celdaNueva);               //inserto atras de donde estoy parado
                nuevoInsertado = true;                      //habilito la bandera para poder..
            }
            if (nuevoInsertado){
                it->idCampo ++;                              //.. incrementar en uno cada uno de los idCampos siguientes
            }
        }
        if (!nuevoInsertado) {                               // Caso: agregar al final
            auto it = _celdas.end();
            it--;
            celdaNueva.idCampo = it->idCampo +1;
            _celdas.push_back(celdaNueva);
        }
    }
}

