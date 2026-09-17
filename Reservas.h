#ifdef RESERVAS_H
#define RESERVAS_H
#include <iostream>
class Reserva{
    const int reser=120;
    private:
    int consecutivo;
    Cliente *cliente;
    Cancha *cancha;
    string deporte;
    int monto;
    string estado;
    int horaInicial;
    int horaFinal;
}