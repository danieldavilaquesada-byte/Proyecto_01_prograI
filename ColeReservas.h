#ifndef COLERESERVAS_H
#define COLERESERVAS_H
#include "Reservas.h"
#include <string>
const int max_reserv=120;
class ColeReservas{
    private:
    Reserva* reservas[max_reserv];
    int canti;
    public:
    ColeReservas();
    int getCanti();
    Reserva* getReserva(int posicion);
    bool agregarReserva(Reserva*reservas);
    void mostrarT();
    Reserva* buscarReserva(int num);
    void mostrarXcancha(string codigo);
    bool cancelarReserva(int num);
    Reserva* registrarReserva(Cliente* cli, Cancha* canch, int horaInicial, int cant);
};
#endif
