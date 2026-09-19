#ifndef ESPERA_H
#define ESPERA_H

#include<iostream>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

//espera.h
class Espera{
private:
    int consecutivo = 0;
    Cliente* cliente;
    Cancha* cancha;
    int franja;
    string estado;

public:
    Espera();
    Espera(int consecutivo, Cliente* _cliente, Cancha* _cancha, int _franja, string _estado);

    int getConsecutivo() const;
    Cliente* getCliente() const;
    Cancha* getCancha() const;
    int getFranja() const;
    string getEstado() const;

    void setEstado(string _estado);
    void setConsecutivo(int consecutivo);

    string toString() const;
};

#endif
