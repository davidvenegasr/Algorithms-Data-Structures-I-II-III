//
// Created by luis on 26/11/19.
//

#include "gtest-1.8.1/gtest.h"
#include "../src/Tabla.h"

TEST(test_tabla, test_basico) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    ASSERT_EQ(tabla.campos(), campos);
    ASSERT_EQ(tabla.clave(), clave);
    ASSERT_EQ(tabla.registros(),linear_set<Registro>());
}

TEST(test_tabla, test_obtenerNroCampo) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu", "domicilio", "localidad", "telefono"};
    int idsOrdenadosLexic[] = {     1,      5,          0,      4,          2,          3,          6};
    set<NombreCampo> campos(camposArray, camposArray+7);

    Tabla tabla(campos, clave);


    for (int i=0; i < 7; i++){
        ASSERT_EQ(tabla.obtenerNroCampo(camposArray[i]), idsOrdenadosLexic[i]);
    }
}

TEST(test_tabla, test_obtenerNroCampo2) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    Registro reg3;
    reg3.definir("dni", "111111111");
    reg3.definir("nombre", "david");
    reg3.definir("apellido", "venegas");
    reg3.definir("lu", "1111");

    tabla.insertar(reg1);
    tabla.insertar(reg2);
    tabla.insertar(reg3);

    int idABuscar = tabla.obtenerNroCampo("apellido");

    //Busqueda de valor en una tabla en O(n*|v|)
    bool encontrado = false;
    for (auto reg : tabla.registros()){
        if (reg.valorXNroDeCampo(idABuscar) == "venegas"){
            encontrado = true;
        }
    }

    ASSERT_TRUE(encontrado);
}

TEST(test_tabla, test_insertar) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    tabla.insertar(reg1);

    linear_set<Registro> conj;
    conj.insert(reg1);

    ASSERT_EQ(tabla.registros(),conj);
}

TEST(test_tabla, test_insertar_repetido) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "40710668");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "4318");

    tabla.insertar(reg1);
    tabla.insertar(reg2);

    linear_set<Registro> conj;
    conj.insert(reg1);

    ASSERT_EQ(tabla.registros(),conj);
}

TEST(test_tabla, test_insertar2) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    tabla.insertar(reg1);
    tabla.insertar(reg2);

    linear_set<Registro> conj;
    conj.insert(reg1);
    conj.insert(reg2);

    ASSERT_EQ(tabla.registros(),conj);
}

TEST(test_tabla, test_insertar_y_borrar) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    tabla.insertar(reg1);
    tabla.insertar(reg2);
    tabla.borrar("40710668");
    tabla.borrar("40710668");

    linear_set<Registro> conj;
    conj.insert(reg2);

    ASSERT_EQ(tabla.registros(),conj);
}

TEST(test_tabla, test_insertar_y_borrar2) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    tabla.insertar(reg1);
    tabla.insertar(reg2);
    tabla.borrar("40710668");
    tabla.borrar("99999999");

    linear_set<Registro> conj;

    ASSERT_EQ(tabla.registros(),conj);
}
TEST(test_tabla, test_operadores_y_copia) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    Registro reg3;
    reg3.definir("dni", "11111111");
    reg3.definir("nombre", "david");
    reg3.definir("apellido", "venegas");
    reg3.definir("lu", "1111");

    tabla.insertar(reg1);
    Tabla tabla4(tabla);
    tabla.insertar(reg2);
    tabla.insertar(reg3);

    Tabla tabla2(campos, clave);
    tabla2.insertar(reg1);
    tabla2.insertar(reg2);
    EXPECT_FALSE(tabla == tabla2);
    tabla2.insertar(reg3);
    ASSERT_EQ(tabla == tabla2, true);
    Tabla tabla3(tabla);
    ASSERT_EQ(tabla == tabla3, true);
    EXPECT_FALSE(tabla == tabla4);
}


TEST(test_tabla, test_camposXClave) {
    NombreCampo clave = "dni";
    NombreCampo camposArray[] = {clave, "nombre", "apellido", "lu"};
    set<NombreCampo> campos(camposArray, camposArray+4);

    Tabla tabla(campos, clave);

    Registro reg1;
    reg1.definir("dni", "40710668");
    reg1.definir("nombre", "luis");
    reg1.definir("apellido", "bustamante");
    reg1.definir("lu", "4318");

    Registro reg2;
    reg2.definir("dni", "99999999");
    reg2.definir("nombre", "luis");
    reg2.definir("apellido", "bustamante");
    reg2.definir("lu", "9999");

    Registro reg3;
    reg3.definir("dni", "11111111");
    reg3.definir("nombre", "david");
    reg3.definir("apellido", "venegas");
    reg3.definir("lu", "1111");

    tabla.insertar(reg1);
    tabla.insertar(reg2);
    tabla.insertar(reg3);

    ASSERT_EQ(reg1, tabla.camposXClave("40710668"));
    ASSERT_EQ(reg2, tabla.camposXClave("99999999"));
    ASSERT_EQ(reg3, tabla.camposXClave("11111111"));

}
