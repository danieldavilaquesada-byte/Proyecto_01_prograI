
#include <iostream>
#include "Canchas.h"


Cancha::Cancha() : codigo(""), deporte(""), precio(0) {
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

Cancha::Cancha(string cod, string dep, double pre)
    : codigo(cod), deporte(dep), precio(pre) {
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

string Cancha::getCodigo() {
     return codigo; }
string Cancha::getDeporte() {
     return deporte; }
double Cancha::getPrecio() {
     return precio; }
void Cancha::setPrecio(double p) { precio = p; }

void Cancha::mostrarCancha() {
    cout << "Codigo: " << codigo
         << " | Deporte: " << deporte
         << " | Precio por hora: " << precio << endl;
}

void Cancha::mostrarDis() {
    for (int i = 0; i < 12; i++) {
        cout << "[" << i << "] "
             << i + 8 << ":00-" << i + 9 << ":00: "
             << v[i] << endl;
    }
}

bool Cancha::libre(int ini, int fin) {
    if (ini < 0 || fin >= 12 || ini > fin) return false;

    for (int i = ini; i <= fin; i++) {
        if (v[i] != 'L') return false;
    }
    return true;
}

bool Cancha::estaOcupada(int franja) {
    return franja >= 0 && franja < 12 && v[franja] == 'O';
}

void Cancha::ocupado(int ini, int fin) {
    if (ini < 0 || fin >= 12 || ini > fin) return;
    for (int i = ini; i <= fin; i++) {
        if (v[i] == 'L') v[i] = 'O';
    }
}

void Cancha::liberar(int ini, int fin) {
    if (ini < 0 || fin >= 12 || ini > fin) return;
    for (int i = ini; i <= fin; i++) {
        if (v[i] == 'O') v[i] = 'L';
    }
}

void Cancha::mantenimiento(int ini, int fin) {
    if (libre(ini, fin)) {
        for (int i = ini; i <= fin; i++) v[i] = 'M';
    }
}

void Cancha::quitarmant(int ini, int fin) {
    if (ini < 0 || fin >= 12 || ini > fin) return;
    for (int i = ini; i <= fin; i++) {
        if (v[i] == 'M') v[i] = 'L';
    }
}
