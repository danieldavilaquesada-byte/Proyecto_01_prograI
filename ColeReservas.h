#ifndef COLERESERVAS_H
#define COLERESERVAS_H
#include "Reservas.h"
const int max=120;
class ColeReservas{
    private:
    Reserva* reservas[max];
    int canti;
    public:
    ColeReservas();
    bool agregarReserva(Reserva*reservas);
    void mostrarT();
    Reserva* buscarReserva(int num);
    void mostrarXcancha(string codigo);
    bool cancelarReserva(int num);
};
#endif
