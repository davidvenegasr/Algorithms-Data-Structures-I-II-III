#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes(){
    for(int i = 0; i < 4; i ++) {
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if (registrado(id)){
        delete _conns[id];
    }
    _conns[id] = new ConexionJugador(ip);
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for(int i = 0; i < 4; i ++) {
        if(registrado(i))
            delete _conns[i];
    }
    for (auto p : vproxie){
        delete p;
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    if (registrado(id)){
        _conns[id]->enviarMensaje(mensaje);
    }
}
string SistemaDeMensajes::ipJugador(int id) const {
    if (registrado(id)){
        return _conns[id]->ip();
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id))
        delete _conns[id];
        _conns[id] = nullptr;
}
#if EJ == 4 || EJ == 5
Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* p = new Proxy(_conns[id]);
    vproxie.push_back(p);
    return p;
}
#elif EJ >= 6
    Proxy* SistemaDeMensajes::obtenerProxy(int id) {
        Proxy *p = new Proxy(&_conns[id]);
        vproxie.push_back(p);
        return p;
    }
#endif