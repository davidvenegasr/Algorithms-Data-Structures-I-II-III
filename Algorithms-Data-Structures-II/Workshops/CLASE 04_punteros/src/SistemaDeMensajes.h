#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    void registrarJugador(int id, string ip);
    bool registrado(int id) const;
    ~SistemaDeMensajes();
    void desregistrarJugador(int id);
    Proxy* obtenerProxy(int id);
    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);
    vector<Proxy*> vproxie;


    // Pre: registrado(id)
    string ipJugador(int id) const;


  private:
    ConexionJugador* _conns[4];
};

#endif
