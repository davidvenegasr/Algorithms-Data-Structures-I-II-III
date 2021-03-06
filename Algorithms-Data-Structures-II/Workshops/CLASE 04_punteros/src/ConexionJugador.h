#ifndef CONEXIONJUGADOR_H
#define CONEXIONJUGADOR_H

#include "Internet.h"
#include <string>

using namespace std;

class ConexionJugador {
  public:
    ConexionJugador(string ip);
    void enviarMensaje(string mensaje);
    string ip() const;
    //~ConexionJugador();

  private:
    string _ip;

    Internet* _internet = &Internet::internet();

};

#endif
