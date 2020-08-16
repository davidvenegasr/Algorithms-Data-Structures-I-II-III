#include "Proxy2.h"

Proxy::Proxy(ConexionJugador** conn): _conn(conn) {};
// Completar ...his->
void Proxy::enviarMensaje(string msg) {
    (*_conn)->enviarMensaje(msg);
}

