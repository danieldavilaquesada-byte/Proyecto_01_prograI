#ifndef COLERESERVAS_H
#define COLERESERVAS_H
#include "Reservas.h"
#include <string>
const int MAX_RESERVAS=120;
class ColeReservas{
    private:
    Reserva* reservas[MAX_RESERVAS];
    int canti;
    public:
    int getCanti();
    Reserva* getReserva(int i);
    ColeReservas();
    bool agregarReserva(Reserva*reservas);
    void mostrarT();
    Reserva* buscarReserva(int num);
    void mostrarXcancha(string codigo);
    bool cancelarReserva(int num);
    Reserva* registrarReserva(Cliente* cli, Cancha* canch, int horaInicial, int cant);
};
#endif
