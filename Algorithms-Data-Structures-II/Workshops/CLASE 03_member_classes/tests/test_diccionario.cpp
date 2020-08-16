#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

TEST(diccionario, ej5_borrar){
    Diccionario d;
    d.definir(1,2);
    d.definir(2,3);
    d.definir(3,4);
    ASSERT_EQ(d.obtener(1), 2);
    d.borrar(1);
    ASSERT_FALSE(d.def(1));
    ASSERT_EQ(d.obtener(2), 3);
    ASSERT_EQ(d.obtener(3), 4);
    d.borrar(1);
    ASSERT_EQ(d.obtener(2), 3);
    ASSERT_EQ(d.obtener(3), 4);

}

// Completar para el ejercicio 5

#endif

#if EJ >= 6

TEST(diccionario, ej6_claves){
    Diccionario d;
    d.definir(1,2);
    d.definir(2,3);
    d.definir(3,4);
    std::vector<Clave> c = d.claves();
    std::vector<Clave> r = {1,2,3};
    ASSERT_TRUE(esPermutacion(c,r) == true);

}
// Completar para el ejercicio 6

#endif

#if EJ >= 7

TEST(diccionario, ej7_igual){
    Diccionario d;
    d.definir(1,2);
    d.definir(2,3);
    d.definir(3,4);
    Diccionario p;
    p.definir(3,4);
    p.definir(2,3);
    p.definir(1,2);
    ASSERT_TRUE(d==p);
    }

// Completar para el ejercicio 7

#endif

#if EJ >= 8

TEST(diccionario, ej8_and_or){
    Diccionario d;
    d.definir(1,2);
    d.definir(2,3);
    d.definir(3,4);
    Diccionario p;
    p.definir(4,4);
    p.definir(5,3);
    p.definir(1,2);
    Diccionario e;
    e.definir(1,2);
    ASSERT_EQ(d&&p,e);
    Diccionario x;;
    x.definir(1,2);
    x.definir(2,3);
    x.definir(3,4);
    x.definir(4,4);
    x.definir(5,3);
    ASSERT_EQ(d||p,x);
    }



#endif

