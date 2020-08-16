//
// Created by daredevil on 04/12/19.
//

#include "gtest-1.8.1/gtest.h"
#include "../src/Driver.h"
#include "../src/BaseDeDatos.h"

TEST(crearBase, crea_Base){
    BaseDeDatos bd;
    ASSERT_TRUE(bd.NombreTablas().empty());
}

TEST(agregarTabla, agregarTabla){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre","DNI","Direccion"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);
    ASSERT_EQ(bd.NombreTablas().size(), 1);
    ASSERT_TRUE(bd.pertenece("personas"));
    ASSERT_FALSE(bd.pertenece("persona"));
}

TEST(eliminarTabla, eliminarTabla){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre","DNI","Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);
    ASSERT_EQ(bd.NombreTablas().size(),1);
    ASSERT_TRUE(bd.pertenece("personas"));
    bd.BorrarTabla("personas");
    ASSERT_FALSE(bd.pertenece("personas"));
    ASSERT_EQ(bd.NombreTablas().size(), 0);
}



TEST(agregarRegistro, agregarRegistro){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre","DNI","Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);


    Registro r;
    string campo1 = "Nombre";
    string valor1 = "David";
    string campo2 = "DNI";
    string valor2 = "95857878";
    string campo3 = "Sueldo";
    string valor3 = "0";

    r.definir(campo1,valor1);
    r.definir(campo2,valor2);
    r.definir(campo3,valor3);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
    bd.AgregarRegistro("personas",r);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),1);
}


TEST(borrarRegistro, borrarRegistro){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre","DNI","Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);

    Registro r;
    string campo1 = "Nombre";
    string valor1 = "David";
    string campo2 = "DNI";
    string valor2 = "95857878";
    string campo3 = "Sueldo";
    string valor3 = "0";

    r.definir(campo1,valor1);
    r.definir(campo2,valor2);
    r.definir(campo3,valor3);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
    bd.AgregarRegistro("personas",r);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),1);
    bd.BorrarRegistro("personas","95857878");
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
}

TEST(pisarTabla, pisarTabla){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre","DNI","Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);
    
    Registro r;
    string campo1 = "Nombre";
    string valor1 = "David";
    string campo2 = "DNI";
    string valor2 = "95857878";
    string campo3 = "Sueldo";
    string valor3 = "0";

    r.definir(campo1,valor1);
    r.definir(campo2,valor2);
    r.definir(campo3,valor3);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
    bd.AgregarRegistro("personas",r);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),1);
    bd.BorrarRegistro("personas","95857878");
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
    bd.AgregarRegistro("personas",r);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),1);
    
    set<NombreCampo> campos2 = {"Apellido","CUIT","Sueldo"};
    clave = "CUIT";
    Tabla t2(campos2, clave);
    bd.AgregarTabla("personas",t2);
    ASSERT_EQ(bd.TablaBD("personas").registros().size(),0);
}

TEST(testFrom, testFrom){

    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre", "DNI", "Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);
    Registro r;
    string campo1 = "Nombre";
    string valor1 = "David";
    string campo2 = "DNI";
    string valor2 = "95857878";
    string campo3 = "Sueldo";
    string valor3 = "0";
    r.definir(campo1,valor1);
    r.definir(campo2,valor2);
    r.definir(campo3,valor3);

    Registro r2;
    campo1 = "Nombre";
    valor1 = "Luis";
    campo2 = "DNI";
    valor2 = "40333333";
    campo3 = "Sueldo";
    valor3 = "99000";

    r2.definir(campo1,valor1);
    r2.definir(campo2,valor2);
    r2.definir(campo3,valor3);
    
    bd.AgregarRegistro("personas",r);
    bd.AgregarRegistro("personas",r2);
    linear_set<Registro> consulta = bd.EjecutarConsulta(Consulta("from(personas)"));
    ASSERT_EQ(consulta.size(),2);

}


TEST(testSelect, selectSimple){
    BaseDeDatos bd;
    set<NombreCampo> campos = {"Nombre", "DNI", "Sueldo"};
    NombreCampo clave = "DNI";
    Tabla t(campos, clave);
    bd.AgregarTabla("personas",t);
    Registro r;
    string campo1 = "Nombre";
    string valor1 = "David";
    string campo2 = "DNI";
    string valor2 = "95857878";
    string campo3 = "Sueldo";
    string valor3 = "0";
    r.definir(campo1,valor1);
    r.definir(campo2,valor2);
    r.definir(campo3,valor3);

    Registro r2;
    campo1 = "Nombre";
    valor1 = "Luis";
    campo2 = "DNI";
    valor2 = "40333333";
    campo3 = "Sueldo";
    valor3 = "99000";

    r2.definir(campo1,valor1);
    r2.definir(campo2,valor2);
    r2.definir(campo3,valor3);
    
    bd.AgregarRegistro("personas",r);
    bd.AgregarRegistro("personas",r2);
    Consulta c("select(from(personas),Nombre,'David')");
    linear_set<Registro> cons = bd.EjecutarConsulta(c);
    for(Registro _r : cons){
        ASSERT_EQ(_r,r);
    }
    
}
/*
TEST(test_interseccion, test_misma_tabla){
    BaseDeDatos bd;
    linear_set<NombreCampo> campos = {"Producto","ID","Precio"};
    bd.agregarTabla("Productos","ID",campos);

    Registro r;
    r.agregar("Producto","Agua");
    r.agregar("ID","1");
    r.agregar("Precio","10");

    Registro r2;
    r2.agregar("Producto","Jugo");
    r2.agregar("ID","2");
    r2.agregar("Precio","20");

    Registro r3;
    r3.agregar("Producto","Jugo");
    r3.agregar("ID","3");
    r3.agregar("Precio","30");

    bd.agregarRegistro("Productos",r);
    bd.agregarRegistro("Productos",r2);
    bd.agregarRegistro("Productos",r3);

    linear_set<Registro> registros = bd.query(
            Consulta(
                    "inter("
                    "select(from(Productos),Producto,'Jugo'),"
                    "select(from(Productos),ID,'3'))"));
    for(Registro rx : registros){
        ASSERT_EQ(rx, r3);
    }
}

TEST(test_union, test_misma_tabla){
    BaseDeDatos bd;
    linear_set<NombreCampo> campos = {"Producto","Precio"};
    bd.agregarTabla("Productos","Producto",campos);

    Registro r;
    r.agregar("Producto","Agua");
    r.agregar("Precio","10");

    Registro r2;
    r2.agregar("Producto","Jugo");
    r2.agregar("Precio","20");

    bd.agregarRegistro("Productos",r);
    bd.agregarRegistro("Productos",r2);

    linear_set<NombreCampo> campos2 = {"Empleado","Sueldo"};
    bd.agregarTabla("Empleados","Empleado",campos2);

    Registro r3;
    r3.agregar("Empleado","Carlos");
    r3.agregar("Sueldo","10");

    Registro r4;
    r4.agregar("Empleado","R2D2");
    r4.agregar("Sueldo","C3PO");

    bd.agregarRegistro("Empleados",r3);
    bd.agregarRegistro("Empleados",r4);

    linear_set<Registro> registros = bd.query(
            Consulta(
                    "union("
                        "select(from(Productos),Producto,'Jugo'),"
                        "select(from(Empleados),Empleado,'R2D2')"
                        ")"
                        ));
    linear_set<Registro> aux = {r2, r4};

    ASSERT_EQ(registros, aux); // igualdad de conjuntos no se si funciona
}
*/