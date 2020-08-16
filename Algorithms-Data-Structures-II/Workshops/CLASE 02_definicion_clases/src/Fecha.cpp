//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
    bool res = false;
    if (anio % 4 == 0 && (anio % 100 != 0  || anio % 400 == 0))
        res = true;
    return res;
}

// Ejercicio 2: diasEnMes
int diasEnMes( Anio anio, Mes mes){
    int dias;
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            dias = 30;
        } else if (mes == 2) {
            if (esBisiesto(anio))
                dias = 29;
            else
                dias = 28;
        } else {
            dias = 31;
        }
    return dias;
}
//
//

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  void sumar_periodo (Periodo p);
  // Ejercicio 7: sumar período a fecha

 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);

};

void  Fecha::sumar_anios(int anios) {
    _anio += anios;
}
void Fecha::sumar_meses(int meses) {
    Mes res = _mes + meses;
    while (res > 12) {
        sumar_anios(1);
        res -=12;
    }
    _mes = res;
}

void Fecha::sumar_dias(int dias) {
    std::vector<Dia> maxDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Dia res = _dia + dias;
    while ( maxDays[_mes] < res) {
        if (maxDays[_mes] == 31) {
            res -= 31;
            sumar_meses(1);
        }
        else if (maxDays[_mes] == 30) {
            sumar_meses(1);
            res -= 30;
        } else {

            if (esBisiesto(_anio)) {
                sumar_meses(1);
                res -= 29;
            }
            else {
                sumar_meses(1);
                res -=28;
            }
        }
    }
    _dia = res;

}
// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) {
    _anio = anio;
    _mes = mes;
    _dia = dia;
}

Anio Fecha::anio() const {
    return _anio;
}

Mes Fecha::mes() const {
    return _mes;
}

Dia Fecha::dia() const {
    return _dia;
}




// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return _anio == o.anio() && _mes == o.mes() && _dia == o.dia();
}

bool Fecha::operator<(Fecha o) const {
    return _anio < o.anio() || (_anio == o.anio() && _mes < o.mes()) || (_anio == o.anio() && _mes == o.mes() && _dia < o.dia());
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
    return !(f1 == f2);
}

// Ejercicio 6: clase período
class Periodo {

public:
    Periodo (Anio _anio, Mes mes, Dia dia);

    int anios();
    int meses();
    int dias();

private:
    Anio _anio;
    Mes _mes;
    Dia _dia;


};

Periodo::Periodo(Anio anio, Mes mes, Dia dia) : _anio(anio), _mes(mes), _dia(dia){
}


int Periodo::anios(){
    return _anio;
}

int Periodo::meses(){
    return _mes;
}

int Periodo::dias(){
    return _dia;
}

void Fecha::sumar_periodo(Periodo p){
     sumar_anios(p.anios());
     sumar_meses(p.meses());
     sumar_dias(p.dias());
}

// Ejercicio 8: clase Intervalo

class Intervalo {
public:
    Intervalo(Fecha desde, Fecha hasta);

    Fecha desde() const;
    Fecha hasta() const;

    int enDias() const;

private:
    Fecha _desde;
    Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta): _desde(desde), _hasta(hasta) {}

Fecha Intervalo::desde() const {
    return _desde;
}

Fecha Intervalo::hasta() const {
    return _hasta;
}

int Intervalo::enDias() const {
    Fecha actual = _desde;
    int dias = 0;
    while (actual != _hasta) {
        dias++;
        actual.sumar_periodo(Periodo(0, 0, 1));
    }
    return dias;
}

