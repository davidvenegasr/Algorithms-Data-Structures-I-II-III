#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> p;
    if (s.size() > 0) {
        p.push_back(s[0]);
    }
    for (int x:s) {
        for (int i; i < p.size(); i++) {
            if (p[i] == x) {
                break;
            } else if (i == p.size() - 1)
                p.push_back(x);
        }
    }
    return p;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set;
    vector<int> sinRepetidos;
    for (int x: s) {
        set.insert(x);
    }
    for (int x: set){
        sinRepetidos.push_back(x);
    }
    return sinRepetidos;
}

// Ejercicio 3
bool pertece(int a, vector<int> v){
    bool res = false;
    for (int i; i < v.size(); i++){
        if ( a == v[i])
            res = true;
    }
    return res;
}

bool mismos_elementos(vector<int> a, vector<int> b) {
    vector<int> asr = quitar_repetidos_v2(a);
    vector<int> bsr = quitar_repetidos_v2(b);
    bool res = true;
    for (int i = 0; i < asr.size(); ++i) {
        if (!pertece(asr[i],bsr)){
            res = false;
        }
    }
    for (int i = 0; i < bsr.size() ; ++i) {
        if (!pertece(bsr[i], asr)){
            res = false;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> sa;
    set<int> sb;
    for (int x:a){
        sa.insert(x);
    }
    for ( int y:b){
        sb.insert(y);
    }
    if (sa.size() != sb.size()){
        res = false;
    }
    for (int z: sa){
        if (!sb.count(z))
            res = false;
    }
    return res;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    vector<int> aux =  quitar_repetidos_v2(s);
    map <int,int> map;
    for (int x: aux) {
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == s[i])
                j++;
        }
        map.insert(pair<int,int>(x,j));
    }

    return map;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map <int,int> m = contar_apariciones(s);
    vector <int > result;
    for (pair <int, int> p: m){
        if (p.second == 1) {
            result.push_back(p.first);
        }
    }
    return result;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    vector<int > c;
    set<int> intersec;
    for( int x: a)
    {
        c.push_back(x);
    }
    for(int x: b)
    {
        c.push_back(x);
    }
    map <int,int > ap = contar_apariciones(c);
    for(pair <int,int > p: ap){
        if (p.second > 1){
            intersec.insert(p.first);
        }
    }
    return intersec;
}

// Ejercicio 8

int unidades (int u) {
    return u % 10;
}

map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    vector<int> result;
    for(int x:s){
        result.push_back(unidades(x));
    }
    map<int, set<int>> res;

    for (int i = 0; i < s.size(); i++){
        int  units = unidades(s[i]);
        if (res.count(units) == 0) {
            set<int> set;
            for (int j = i; j< s.size(); j++){
                if(unidades(s[j]) == units)
                set.insert(s[j]);
            }
            res[units]  = set;
        }
    }
    return res;
}


// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> result = str;
    map<char,char> dicc;
    for(pair<char, char> p: tr){
        dicc[p.first] = p.second;
    }
    for (int i = 0; i < str.size(); i++){
        if (dicc.count(str[i]))
            result[i]= dicc[str[i]];
        else
            result[i]= str[i];
    }
    return result;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    set<set<LU>> libs;
    bool res = false;
    for(Mail x: s) {
        libs.insert(x.libretas());
    }
    for(Mail mail: s){
        set<LU> libretasPorMail = mail.libretas();
        for (LU libreta: libretasPorMail ) {
            int counter = 0;
            for (set<LU> conj: libs) {
                if (conj.count(libreta)) {
                    counter++;
                    if (counter > 1) {
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail mail: s){
        if (mail.adjunto()){
            set<LU> equipo = mail.libretas();
            if(res.count(equipo)){
                Fecha entregaEnDicc = res[equipo].fecha();
                if ( mail.fecha() > entregaEnDicc ){
                    res[equipo] = mail;
                }
            } else {
                res[equipo] = mail;
            }
        }
    }
  return res;
}
