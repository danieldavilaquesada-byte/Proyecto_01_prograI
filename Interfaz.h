#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "GestorCanchas.h"
#include "ColecionClientes.h"
#include "ColeReservas.h"
#include "ColeccionEsperas.h"
#include "Informes.h"

class Interfaz {
private:
    GestorCanchas canchas;
    ColeccionClientes clientes;
    ColeReservas reservas;
    ColeccionEsperas esperas;
    Informes informes;

public:
    Interfaz();
   
    void centroDeportivo();
    void menuCanchas();
    void menuClientes();
    void menuReservas();
    void menuEsperas();
    void menuInformes();
};

#endif
