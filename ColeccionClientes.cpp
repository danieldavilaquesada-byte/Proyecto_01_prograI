#include <iostream>
#include "ColeccionClientes.h"
using namespace std;

//coleccionclientes.cpp
int const MAXCLIENTES= 100;

ColeccionClientes::ColeccionClientes() {
    capacidad = 100;
    cantidad = 0;
    clientes = new Cliente[100];
}

ColeccionClientes::ColeccionClientes(int can) {
    capacidad = 100;
    cantidad = can;
    clientes = new Cliente[100];
}
ColeccionClientes::~ColeccionClientes() { 
    delete[] clientes;
}

void ColeccionClientes::agregarCliente(Cliente cliente) {
    if (cantidad < capacidad) {
    clientes[cantidad] = cliente;
    cantidad++;
    } else {
    cout << "No se puede agregar más clientes." << endl;
    }
}

void ColeccionClientes::mostrarClientes() {
    for (int i = 0; i < cantidad; i++) {
    cout << clientes[i].toString() << endl;
    }
}
