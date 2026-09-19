#ifndef ESPERA_H
#define ESPERA_H

#include<iostream>
#include "Cliente.h"
#include "Cancha.h"
using namespace std;

//espera.h

/*Cuando una cancha se encuentre ocupada en la franja de tiempo deseada por un cliente, el sistema permitirá al usuario
registrar al cliente en un listado de espera, cada registro de espera deberá almacenar:
− Número consecutivo.
− Puntero a cliente interesado.
− Puntero a cancha solicitada.
− Posición de la franja horaria.
− Estado: esperando, atendido o cancelado.
Nota: Se aclara que el “listado de espera” corresponde a un arreglo unidimensional de 10 campos y no a una lista
enlazada.
Un mismo cliente no podrá aparecer dos veces en estado de espera para la misma cancha y franja horaria.
Solo podrán incorporarse clientes al listado de espera cuando la franja solicitada se encuentre ocupada (O). Las franjas que se
encuentren en mantenimiento (M) no generarán registros en el listado de espera.
Las operaciones mínimas serán:
− Registrar un cliente en listado de espera
− Mostrar el listado de espera.
− Cambiar el estado (esperando, asignado o cancelado.) Nota: “asignado” significa que, al liberarse la cancha, ese
cliente obtuvo la reserva, “cancelado” significa que el cliente ya no desea reservar una cancha
Cuando en el modulo de reservas, se cancele una reserva, en ese momento el sistema deberá informar si existen clientes
esperando por esa cancha y franja horaria. */

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