//
// Created by luisb on 25/11/2019.
//
#include "gtest-1.8.1/gtest.h"
#include "../src/Registro.h"


TEST(test_registro, test_definir_ver_campos) {
    Registro reg;
    reg.definir("dni", "40710668");
    set<NombreCampo> res;
    res.insert("dni");
    ASSERT_EQ(reg.campos(),res);
}

TEST(test_registro, test_definir_ver_campos2) {
    Registro reg;
    reg.definir("dni", "40710668");
    reg.definir("lu", "4318");
    set<NombreCampo> res;
    res.insert("dni");
    res.insert("lu");
    ASSERT_EQ(reg.campos(),res);
}

TEST(test_registro, test_definir_ver_campos3) {
    Registro reg;
    reg.definir("dni", "40710668");
    reg.definir("lu", "4318");
    reg.definir("primer_nombre", "luis");
    reg.definir("segundo_nombre", "ricardo");
    reg.definir("apellido", "bustamante");
    set<NombreCampo> res;
    res.insert("apellido");
    res.insert("segundo_nombre");
    res.insert("primer_nombre");
    res.insert("lu");
    res.insert("dni");
    ASSERT_EQ(reg.campos(),res);
}

TEST(test_registro, test_definir_ver_valor) {
    Registro reg;
    reg.definir("dni", "40710668");
    reg.definir("lu", "4318");
    reg.definir("primer_nombre", "luis");
    reg.definir("segundo_nombre", "ricardo");
    reg.definir("apellido", "bustamante");
    ASSERT_EQ(reg["dni"],"40710668");
    ASSERT_EQ(reg["apellido"],"bustamante");
    ASSERT_NE(reg["apellido"],"Bustamante");
}

TEST(test_registro, test_valorXNroCampo_simple) {
    Registro reg;
    reg.definir("dni", "40710668");
    reg.definir("lu", "4318");

    ASSERT_EQ(reg.valorXNroDeCampo(0),"40710668");
    ASSERT_EQ(reg.valorXNroDeCampo(1),"4318");
}

TEST(test_registro, test_valorXNroCampo_ordenado) {
    Registro reg;
    reg.definir("apellido", "bustamante");
    reg.definir("dni", "40710668");
    reg.definir("lu", "4318");
    reg.definir("primer_nombre", "luis");
    reg.definir("segundo_nombre", "ricardo");

    ASSERT_EQ(reg.valorXNroDeCampo(0),"bustamante");
    ASSERT_EQ(reg.valorXNroDeCampo(1),"40710668");
    ASSERT_EQ(reg.valorXNroDeCampo(2),"4318");
    ASSERT_EQ(reg.valorXNroDeCampo(3),"luis");
    ASSERT_EQ(reg.valorXNroDeCampo(4),"ricardo");
}

TEST(test_registro, test_valorXNroCampo_desordenado) {
    Registro reg;
    reg.definir("primer_nombre", "luis");
    reg.definir("segundo_nombre", "ricardo");
    reg.definir("lu", "4318");
    reg.definir("apellido", "bustamante");
    reg.definir("dni", "40710668");

    ASSERT_EQ(reg.valorXNroDeCampo(0),"bustamante");
    ASSERT_EQ(reg.valorXNroDeCampo(1),"40710668");
    ASSERT_EQ(reg.valorXNroDeCampo(2),"4318");
    ASSERT_EQ(reg.valorXNroDeCampo(3),"luis");
    ASSERT_EQ(reg.valorXNroDeCampo(4),"ricardo");
}

TEST(test_registro, test_valorXNroCampo_extensivo) {
    Registro reg;
    reg.definir("segundo_nombre", "ricardo");
    ASSERT_EQ(reg.valorXNroDeCampo(0),"ricardo");

    reg.definir("primer_nombre", "luis");
    ASSERT_EQ(reg.valorXNroDeCampo(0),"luis");

    reg.definir("lu", "4318");
    ASSERT_EQ(reg.valorXNroDeCampo(0),"4318");

    reg.definir("apellido", "bustamante");
    ASSERT_EQ(reg.valorXNroDeCampo(0),"bustamante");

    reg.definir("dni", "40710668");
    ASSERT_EQ(reg.valorXNroDeCampo(1),"40710668");
}

TEST(test_registro, test_igualdad) {
    Registro reg1;
    reg1.definir("primer_nombre", "luis");
    reg1.definir("segundo_nombre", "ricardo");
    reg1.definir("lu", "4318");
    reg1.definir("apellido", "bustamante");
    reg1.definir("dni", "40710668");
    Registro reg2;
    reg2.definir("segundo_nombre", "ricardo");
    reg2.definir("lu", "4318");
    reg2.definir("apellido", "bustamante");
    reg2.definir("dni", "40710668");
    reg2.definir("primer_nombre", "luis");
    Registro reg3;
    reg3.definir("segundo_nombre", "ricardo");
    reg3.definir("lu", "4318");
    reg3.definir("apellido", "bustamante");
    reg3.definir("dni", "40710668");
    reg3.definir("primer_nombre", "AAAAAAAA");
    ASSERT_EQ(reg1, reg2);
    ASSERT_FALSE (reg1 == reg3);
}

TEST(test_registro, test_igualdad2) {
    Registro reg1;
    reg1.definir("primer_nombre", "luis");
    reg1.definir("segundo_nombre", "ricardo");
    reg1.definir("lu", "4318");
    reg1.definir("apellido", "bustamante");
    reg1.definir("dni", "40710668");
    Registro reg2 (reg1);
    ASSERT_EQ(reg1, reg2);
    Registro reg3 = reg2;
    ASSERT_EQ(reg2, reg3);
    reg3.definir("domicilio","calle falsa 123");
    ASSERT_FALSE (reg1 == reg3);
    ASSERT_FALSE (reg2 == reg3);
}
