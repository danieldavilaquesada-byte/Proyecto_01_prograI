#ifndef CANCHA_H
#define CANCHA_H

#include <iostream>
#include <string>

using namespace std;

const int CANCHAS = 10;  

class Cancha {
private:
    string codigo;
    string deporte;
    double precio;
    char v[12];  // Guarda: L, O, M

public:
    Cancha();
    Cancha(string cod, string dep, double pre);

    string getCodigo();
    string getDeporte();
    double getPrecio();
    void setPrecio(double nuevoPrecio);
    bool estaOcupada(int franja);  // true si es O, false si es L o M

    void mostrarCancha();
    void mostrarDis();  // las 12

    bool libre(int horaInicial, int horaFinal);
    void ocupado(int horaInicial, int horaFinal);   // marca como O
    void liberar(int horaInicial, int horaFinal);   // marca como L
    void mantenimiento(int horaInicial, int horaFinal); // marca como M
    void quitarmant(int horaInicial, int horaFinal);    // vuelve a L
};

#endif
