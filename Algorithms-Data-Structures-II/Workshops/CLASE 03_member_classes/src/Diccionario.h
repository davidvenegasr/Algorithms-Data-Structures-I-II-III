#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

bool esPermutacion(std::vector<Clave> c, std::vector<Clave> p);

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	std::vector<Clave> claves() const ;
	bool operator==(Diccionario o) const;
    Diccionario operator||(Diccionario o) const;
    Diccionario operator&&(Diccionario o) const;
private:
    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave _clave;
        Valor _valor;
    };
    std::vector<Asociacion> pares;
};


#endif /*__DICCIONARIO_H__*/
