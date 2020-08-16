# Modulo Registro
- Cambiamos la estructura de representacion de Registro:
    En vez de ser un Conjunto ahora es una Lista Enlazada
    Nos parecio adecuado ya que necesitabamos la nocion de orden dentro de la estructura
    Y ademas necesitabamos insertar elementos entre medio de otros, y Lista Enlazada es la adecuado para eso
- Cambiamos el aliasing de la funcion "nc[v]", ahora devuelve por referencia en vez de por copia
    Lo consideramos asi ya que el template de Registro.h nos lo pedia asi