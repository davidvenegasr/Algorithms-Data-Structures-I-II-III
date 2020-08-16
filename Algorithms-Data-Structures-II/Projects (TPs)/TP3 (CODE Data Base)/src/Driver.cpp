
#include <cassert>
#include <cstdlib>
#include <sstream>

#include "Driver.h"

Driver::Driver(): _db() {}

void Driver::crearTabla(NombreTabla nt, vector<NombreCampo> campos,
                        NombreCampo clave) {
    set<NombreCampo> camposSet; 
    for (NombreCampo i: campos){
        camposSet.insert(i);
    }
    Tabla ta(camposSet, clave);
    _db.AgregarTabla(nt,ta);
}

void Driver::insertarRegistro(NombreTabla nt, Registro r) {
    _db.AgregarRegistro(nt,r);
}

Respuesta Driver::consultar(const Consulta& q) {
    linear_set<Registro> resp = _db.EjecutarConsulta(q);
    vector<Registro> vectorFinal;
    for (Registro a: resp){
        vectorFinal.push_back(a);
    }
    return vectorFinal;
}

BaseDeDatos Driver::db(){
    return _db;
}

void Driver::leerDataset(string dataset) {
    ifstream is("datos/" + dataset + ".txt");
    
    vector<string> campos;
    _leerLinea(is, campos);
    crearTabla(dataset, campos, campos[0]);

    int linea = 1;
    while (!is.eof()) {
        vector<string> valores;
        if (!_leerLinea(is, valores)) {
            break;
        }
        if (campos.size() != valores.size()) {
            cerr << "Error leyendo dataset: " << dataset << endl;
            cerr << "El registro en la linea " << linea
                 << " tiene " << valores.size() << " campos"
                 << " pero la tabla declara " << campos.size() << " campos."
                 << endl;
            exit(1);
        }
        Registro r;
        for (size_t i = 0; i < campos.size(); i++) {
            r[campos[i]] = valores[i];
        }
        insertarRegistro(dataset, r);
    }
}

bool Driver::_leerLinea(ifstream& is, vector<string>& valores) const {
    string linea;
    if (!getline(is, linea)) {
        return false;
    }

    istringstream isl(linea);
    string valor;
    while (getline(isl, valor, ',')) {
        valores.push_back(valor);
    }
    return true;
}

