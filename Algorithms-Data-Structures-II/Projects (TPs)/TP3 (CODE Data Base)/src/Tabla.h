#ifndef TP3_TABLA_H
#define TP3_TABLA_H

#include "Tipos.h"
#include "Registro.h"
#include <vector>
#include "modulos_basicos/linear_set.h"
#include "modulos_basicos/linear_map.h"
#include "string_map.h"

using namespace std;

class Tabla {
public:
    Tabla(const set<NombreCampo> &campos, const NombreCampo &clave);
    Tabla(const Tabla& t);
    void insertar(const Registro &reg);
    void borrar(const Valor &val);
    set<NombreCampo> campos() const;
    linear_set<Registro> registros() const;
    NombreCampo clave() const;
    int obtenerNroCampo(const NombreCampo &nc);
    const Registro& camposXClave(const Valor &val) const;
    bool const operator==(const Tabla &t) const;

private:
    linear_set<Registro> _conjRegistros;
    string_map<linear_set<Registro>::iterator> _diccCamposXClave;   // diccTrie(Valor, iterador)
    string_map<int> _idXCampo;                                      // diccTrie(NombreCampo, int)
    set<NombreCampo> _conjCampos;
    NombreCampo _campoClave;
    void sortStrings (vector<string> &vec);
    };

#endif //TP3_TABLA_H
