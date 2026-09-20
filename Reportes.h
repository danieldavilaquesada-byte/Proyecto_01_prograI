#ifndef INFORMES_H
#define INFORMES_H
#include<iostream>
#include "ColeReservas.h"
#include "GestorCanchas.h"
using namespace std;
class Informes{
    private:
    ColeReservas* cole;
    GestorCanchas* gestor;
    public:
    Informes(ColeReservas* c, GestorCanchas* g);
    void canchaMayor();
    void clienteMayor();
    void ingresoT();
    void porcenOcupacion();
    void horasMayMen();
};
#endif
