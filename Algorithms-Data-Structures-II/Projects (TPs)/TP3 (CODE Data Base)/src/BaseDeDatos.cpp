#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos(): _base() {}

void BaseDeDatos::AgregarTabla(string nt, const Tabla& t){
    Tabla ta = t;
    if (_base.count(nt))
        _base.erase(nt);
    _base.insert(make_pair(nt,t));
}

void BaseDeDatos::BorrarTabla(string nt){
    _base.erase(nt);
}
void BaseDeDatos::AgregarRegistro(string nt, Registro r){
    _base.at(nt).insertar(r);
}
void BaseDeDatos::BorrarRegistro(string nt, string v){
    _base.at(nt).borrar(v);
}
set<NombreTabla> BaseDeDatos::NombreTablas(){
    return _base.claves();
}
bool BaseDeDatos::pertenece(NombreTabla nt){
    return _base.claves().count(nt);
}
Tabla BaseDeDatos::TablaBD(string nt){
    return _base.at(nt);
}
linear_set<Registro> BaseDeDatos::EjecutarConsulta(const Consulta& c) {
    linear_set<Registro> res;
    /** CONSULTA FROM **/
    if (c.tipo_consulta() == FROM) {
        Tabla t = _base.at(c.nombre_tabla());
        for (const Registro &reg: t.registros()) {
            res.insert(reg);
        }
    /** CONSULTA SELECT **/
    } else if (c.tipo_consulta() == SELECT) {
        /** Consulta: SELECT(FROM(t),c,v) **/
        if (c.subconsulta1().tipo_consulta() == FROM) {
            Tabla t = _base.at(c.subconsulta1().nombre_tabla());
            /** Select CON clave **/
            if (c.campo1() == t.clave()) {
                res = selectConClave(c);

            } /** Select SIN clave **/
            else {
                res = selectSinClave(c);

            }
        } /** Consulta: SELECT(SELECT(FROM(t),c2,v2),c1,v1) **/
        else if (c.subconsulta1().tipo_consulta() == SELECT
                 && c.subconsulta1().subconsulta1().tipo_consulta() == FROM) {
            Tabla t = _base.at(c.subconsulta1().subconsulta1().nombre_tabla());
            if (c.campo1() == t.clave() && c.subconsulta1().campo1() != t.clave()){
                res = selectSelectFrom(c);
            } else{
                res = select(c);
            }
        } /** Consulta: SELECT(PRODUCT(FROM(t1),FROM(t2)),c1,v1) **/
        else if (c.subconsulta1().tipo_consulta() == PRODUCT
                 && c.subconsulta1().subconsulta1().tipo_consulta() == FROM
                 && c.subconsulta1().subconsulta2().tipo_consulta() == FROM) {
            Tabla t1 = _base.at(c.subconsulta1().subconsulta1().nombre_tabla());
            if (c.campo1() == t1.clave()){
                res = selectProdFromFrom(c);
            } else{
                res = select(c);
            }
        } /** Consulta: Select Normal**/
        else {
            res = select(c);
        }
    /** CONSULTA MATCH **/
    } else if (c.tipo_consulta() == MATCH) {
        /** CONSULTA JOIN con claves **/
        if (c.subconsulta1().tipo_consulta() == PRODUCT
            && c.subconsulta1().subconsulta1().tipo_consulta() == FROM
            && c.subconsulta1().subconsulta2().tipo_consulta() == FROM){
            Tabla t1 = TablaBD(c.subconsulta1().subconsulta1().nombre_tabla());
            Tabla t2 = TablaBD(c.subconsulta1().subconsulta2().nombre_tabla());
            if (!(t1 == t2) && t1.clave() == c.campo1() && t2.clave() == c.campo2()){
                res = joinConClaves(c);
            } else{
                res = match(c);
            }
        }/** Consulta Match Normal **/
        else{
            res = match(c);
        }
    /** CONSULTA PROJ **/
    } else if (c.tipo_consulta() == PROJ) {
        linear_set<Registro> subconsulta1 = EjecutarConsulta(c.subconsulta1());
        set<NombreCampo> campos = c.conj_campos();
        for (Registro a: subconsulta1){
            Registro nuevo;
            set<NombreCampo> camposA = a.campos();
            for( auto itr = campos.begin(); itr != campos.end(); itr++){
                if(camposA.count(*itr)){
                    nuevo.definir(*itr, a[*itr]);
                }
            }
            res.insert(nuevo);
        }
    /** CONSULTA RENAME **/
    } else if (c.tipo_consulta() == RENAME) {
        linear_set<Registro> subconsulta1 = EjecutarConsulta(c.subconsulta1());
        if (subconsulta1.size() > 0) {
            auto it = subconsulta1.begin();
            Registro b = *it;
            set<NombreCampo> nuevosCampos = b.campos();
            NombreCampo nuevoC = c.campo2();
            NombreCampo viejoC = c.campo1();
            for (Registro a: subconsulta1) {
                Registro nuevo;
                set<NombreCampo> camposA = a.campos();
                for( auto itr = nuevosCampos.begin(); itr != nuevosCampos.end(); itr++){
                    if (camposA.count(*itr)){
                        if(*itr == viejoC){
                            nuevo.definir(nuevoC, a[*itr]);
                        } else {
                            nuevo.definir(*itr, a[*itr]);
                        }
                    }
                }
                res.insert(nuevo);
            }
        }
    /** CONSULTA INTER **/
    } else if (c.tipo_consulta() == INTER) {
        linear_set<Registro> subConsulta1;
        linear_set<Registro> subConsulta2;
        subConsulta1 = EjecutarConsulta(c.subconsulta1());
        subConsulta2 = EjecutarConsulta(c.subconsulta2());
        for(const auto &reg : subConsulta1){
            if (subConsulta2.count(reg) == 1){
                res.fast_insert(reg);
            }
        }
    /** CONSULTA UNION **/
    } else if (c.tipo_consulta() == UNION) {
        linear_set<Registro> subconsulta1 = EjecutarConsulta(c.subconsulta1());
        linear_set<Registro> subconsulta2 = EjecutarConsulta(c.subconsulta2());
        for (Registro a: subconsulta1){
            res.insert(a);
        }
        for (Registro b: subconsulta2){
            res.insert(b);
        }
    /** CONSULTA PRODUCT **/
    } else if (c.tipo_consulta() == PRODUCT) {
        linear_set<Registro> subconsulta1 = EjecutarConsulta(c.subconsulta1());
        linear_set<Registro> subconsulta2 = EjecutarConsulta(c.subconsulta2());
        for (Registro a: subconsulta1) {
            for (Registro b: subconsulta2) {
                res.insert(mergeRegs(a, b));
            }
        }
    }
    return res;
}

/** FUNCIONES AUXILIARES de CONSULTA **/

// --------------------------SELECT----------------------------------------------------

/**
 * \complexity O(|nt| + |nc| + |v|)
 */
linear_set<Registro> BaseDeDatos::selectConClave(const Consulta &c) {
    linear_set<Registro> res;
    NombreTabla nt = c.subconsulta1().nombre_tabla();
    NombreCampo nc = c.campo1();
    Valor v = c.valor();
    Tabla tabla = TablaBD(nt);

    const Registro& reg = tabla.camposXClave(v);
    if (!reg.campos().empty()){
        res.insert(reg);
    }
    return res;
}

/**
 * \complexity O( |nt| + |nc| + n*|v| + k*(|v|+|nc|) )
 */
linear_set<Registro> BaseDeDatos::selectSinClave(const Consulta &c) {
    linear_set<Registro> res;
    NombreTabla nt = c.subconsulta1().nombre_tabla();
    NombreCampo nc = c.campo1();
    Valor v = c.valor();
    Tabla tabla = TablaBD(nt);

    int nroCampo = tabla.obtenerNroCampo(nc);
    list<linear_set<Registro>::iterator> listaDeItsDeRegistros;

    linear_set<Registro> registrosDeTabla = tabla.registros();

    //Guardo una lista de iteradores de registro
    for (linear_set<Registro>::iterator it = registrosDeTabla.begin();
            it != registrosDeTabla.end(); ++it){
        Registro r = *it;
        if (r.valorXNroDeCampo(nroCampo)== v){
            listaDeItsDeRegistros.push_back(it);
        }
    }

    //Vuelco todos los iteradores al conj respuesta
    for (const auto& iter : listaDeItsDeRegistros){
        res.fast_insert(*iter);
    }

    return res;
}

/**
 * \complexity O(|nt| + |nc| + |v|)
 */
linear_set<Registro> BaseDeDatos::selectSelectFrom(const Consulta &c) {
    linear_set<Registro> res;
    NombreTabla nt = c.subconsulta1().subconsulta1().nombre_tabla();
    Tabla tabla = TablaBD(nt);

    NombreCampo c1 = c.campo1();
    Valor v1 = c.valor();
    NombreCampo c2 = c.subconsulta1().campo1();
    Valor v2 = c.subconsulta1().valor();

    // Como se que c1 es la clave de tabla, la funcion me devuelve el valor
    // correspondiente, o un registro vacio
    Registro reg = tabla.camposXClave(v1);
    if (!reg.campos().empty()){
        if (reg[c2]== v2){      //si coincide con los valores de la subconsulta es lo que buscaba
            res.insert(reg);
        }
    }
    return res;
}

/**
 * \complexity O( |nt| + |nc| + |v| + n2*(|v|+|nc|) )
 */
linear_set<Registro> BaseDeDatos::selectProdFromFrom(const Consulta &c) {
    linear_set<Registro> res;
    NombreCampo c1 = c.campo1();
    Valor v1 = c.valor();

    NombreTabla nt1 = c.subconsulta1().subconsulta1().nombre_tabla();
    NombreTabla nt2 = c.subconsulta1().subconsulta2().nombre_tabla();

    Tabla tabla1 = TablaBD(nt1);
    const Registro& reg = tabla1.camposXClave(v1);

    if (!reg.campos().empty()){
        Tabla tabla2 = TablaBD(nt2);
        linear_set<Registro> registrosDeTabla2 = tabla2.registros();
        for (const auto& regToMerge : registrosDeTabla2){
            res.insert(mergeRegs(reg, regToMerge));
        }
    }
    return res;
}

Registro BaseDeDatos::mergeRegs(const Registro &r1, const Registro &r2) {
    Registro reg(r1);
    for (const auto& regsDeR2 : r2.campos()){
        reg.definir(regsDeR2, r2[regsDeR2]);
    }
    return reg;
}

linear_set<Registro> BaseDeDatos::select(const Consulta &c) {
    linear_set<Registro> res;
    linear_set<Registro> subConsulta;
    subConsulta = EjecutarConsulta(c.subconsulta1());
    for (auto reg : subConsulta){
        if (reg[c.campo1()] == c.valor()){
            res.insert(reg);
        }
    }
    return res;
}

// --------------------------MATCH------------------------------------------------------

linear_set<Registro> BaseDeDatos::joinConClaves(const Consulta &c){
    linear_set<Registro> reg;
    Tabla tabla1 = TablaBD(c.subconsulta1().subconsulta1().nombre_tabla());
    Tabla tabla2 = TablaBD(c.subconsulta1().subconsulta2().nombre_tabla());
    NombreCampo campoClave1 = tabla1.clave();
    NombreCampo campoClave2 = tabla2.clave();
    int nroCampo1 = tabla1.obtenerNroCampo(campoClave1);
    int nroCampo2 = tabla2.obtenerNroCampo(campoClave2);

    list<pair<linear_set<Registro>::iterator, Registro>>listaDeReg1;
    list<pair<linear_set<Registro>::iterator, Registro>>listaDeReg2;

    linear_set<Registro> conjResAux1 = tabla1.registros();
    linear_set<Registro> conjResAux2 = tabla2.registros();

    linear_set<Registro>::iterator it1 = conjResAux1.begin();
    linear_set<Registro>::iterator it2 = conjResAux2.begin();

    while (it1 != conjResAux1.end() && it2 != conjResAux2.end()){
        Registro regDeIt1 = *it1;
        Registro regMatch1 = tabla2.camposXClave(regDeIt1.valorXNroDeCampo(nroCampo1));

        Registro regDeIt2 = *it2;
        Registro regMatch2 = tabla1.camposXClave(regDeIt2.valorXNroDeCampo(nroCampo2));

        if(!regMatch1.campos().empty()){
            listaDeReg1.push_back(make_pair(it1, regMatch1));
        }
        if(!regMatch2.campos().empty()){
            listaDeReg2.push_back(make_pair(it2, regMatch2));
        }
        ++it1;
        ++it2;
    }
    linear_set<Registro> conjRes1;
    linear_set<Registro> conjRes2;

    for (pair<linear_set<Registro>::iterator, Registro> it : listaDeReg1){
        Registro regToMerge = *(it.first);
        conjRes1.fast_insert(mergeRegs(regToMerge, it.second));
    }
    for (pair<linear_set<Registro>::iterator, Registro> it : listaDeReg2){
        Registro regToMerge = *(it.first);
        conjRes2.fast_insert(mergeRegs(regToMerge, it.second));
    }

    if (conjRes1.size() > conjRes2.size()){
        reg = conjRes1;
    } else{
        reg = conjRes2;
    }
    return reg;
}

linear_set<Registro> BaseDeDatos::match(const Consulta &c) {
    linear_set<Registro> res;
    linear_set<Registro> subConsulta;
    subConsulta = EjecutarConsulta(c.subconsulta1());
    for (auto reg : subConsulta){
        if (reg[c.campo1()] == reg[c.campo2()]){
            res.insert(reg);
        }
    }
    return res;
}
