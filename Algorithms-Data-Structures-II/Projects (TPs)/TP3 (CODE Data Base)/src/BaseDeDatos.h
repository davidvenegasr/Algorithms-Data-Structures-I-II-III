#ifndef __BASEDEDATOS_H__
#define __BASEDEDATOS_H__

#include <iostream>
#include <set>
#include "Tabla.h"
#include "Consulta.h"
#include "Tipos.h"

#include <vector>
#include "modulos_basicos/linear_set.h"
#include "modulos_basicos/linear_map.h"
#include "string_map.h"

using namespace std;

class BaseDeDatos{
public:
    
    BaseDeDatos();
    void AgregarTabla(string nt, const Tabla& t);
    void BorrarTabla(string nt);
    void AgregarRegistro(string nt, Registro r);
    void BorrarRegistro(string nt, string v);
    set<NombreTabla> NombreTablas();
    Tabla TablaBD(string nt);
    linear_set<Registro> EjecutarConsulta(const Consulta& c);
    bool pertenece(NombreTabla nt);
    
private:
    string_map<Tabla> _base;

    linear_set<Registro> selectConClave(const Consulta &c);
    linear_set<Registro> selectSinClave(const Consulta &c);
    linear_set<Registro> selectSelectFrom(const Consulta &c);
    linear_set<Registro> selectProdFromFrom(const Consulta &c);
    linear_set<Registro> select(const Consulta &c);

    Registro mergeRegs(const Registro &r1, const Registro &r2);

    linear_set<Registro> joinConClaves(const Consulta &c);
    linear_set<Registro> match(const Consulta &c);
};


#endif /*__CONSULTA_H__*/
