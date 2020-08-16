#ifndef __REGISTRO_H__
#define __REGISTRO_H__

#include <set>
#include <list>
//#include "modulos_basicos/linear_set.h"
#include "Tipos.h"

using namespace std;

class Registro {
public:
    Registro();
    Registro(const Registro& r);
    Registro& operator=(const Registro& r);

    set<NombreCampo> campos() const;
    Valor& operator[](const NombreCampo& campo);
    const Valor& operator[](const NombreCampo& campo) const;

    void definir(const NombreCampo& campo, const Valor& v);
    Valor valorXNroDeCampo (const int& nroCampo) const;
    bool operator==(const Registro &r) const;
    //Registro unirRegistro(const Registro &r1, const Registro &r2);
    
private:
    struct Celda {
        int idCampo;
        NombreCampo nombreCampo;
        Valor valor;

        Celda(int id, NombreCampo nc, Valor v);
        bool operator==(const Celda &c) const;

        Celda& operator=(const Celda &c){
            idCampo = c.idCampo;
            nombreCampo = c.nombreCampo;
            valor = c.valor;
            return *this;
        }

    };
    list<Celda> _celdas;


};

#endif /*__REGISTRO_H__*/
