#include <iostream>
#include "ColeccionEsperas.h"
#include <sstream>
using namespace std;

ColeccionEsperas::ColeccionEsperas(){
    esperas = new Espera*[20];
    for (int i=0;i<20;i++) {
        esperas[i] = NULL;
    }
}

ColeccionEsperas::~ColeccionEsperas() {
    for (int i=0;i<cantidad;i++) {
        delete esperas[i];
    }
    delete[] esperas;
}

void ColeccionEsperas::RegistrarCliente(Espera* clienteEspera) {
    if (cantidad < capacidad) {
        esperas[cantidad] = clienteEspera;
        cantidad++;
        contador++;
        cout << "Cliente registrado correctamente en la lista" << endl;
        clienteEspera->setConsecutivo(contador);
    } else {
        cout << "No se pudo agregar al cliente" << endl;
    }
}

string ColeccionEsperas::mostrarListado() {
    stringstream s;
    if (cantidad == 0) {
        s << "La lista esta vacia"<<endl;
    } else {
        for (int i =0;i<cantidad;i++) {
            if (esperas[i] != NULL) {
                s << esperas[i]->toString() << endl;
            }
        }
    }
    return s.str();
}

void ColeccionEsperas::cambiarEstado() {
    int consecutivoBuscado;
    cout << "Ingrese el numero consecutivo de la espera a modificar: ";
    cin >> consecutivoBuscado;

    bool encontrado = false;
    for (int i=0;i<cantidad;i++) {
        if (esperas[i] != NULL && esperas[i]->getConsecutivo() == consecutivoBuscado) {
            encontrado = true;
            int opcion;
            cout<<"Seleccione el nuevo estado:"<<endl;
            cout<<"1. Esperando"<<endl;
            cout<<"2. Asignado"<<endl;
            cout<<"3. Cancelado"<<endl;
            cout<<"Opcion: ";
            cin >>opcion;

            if (opcion == 1) {
                esperas[i]->setEstado("esperando");
                cout << "Estado cambiado a: esperando"<<endl;
            } else if (opcion == 2) {
                esperas[i]->setEstado("asignado");
                cout << "Estado cambiado a: asignado"<<endl;
            } else if (opcion == 3) {
                esperas[i]->setEstado("cancelado");
                cout << "Estado cambiado a: cancelado"<<endl;
            } else {
                cout << "Opcion no valida";
            }
            break;
        }
    }

    if (encontrado == false) {
        cout << "No se encontro ningun registro de espera con ese consecutivo"<<endl;
    }
}
