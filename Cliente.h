#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
using namespace std;

//cliente.h

class Cliente{

private:
    string nombre;
    int numero;
public:
    Cliente();
    Cliente(string nombre, int numero);

    string getNombre() const;
    int getNumero() const;

    void setNombre(string nombre);
    void setNumero(int numero);

    string toString();

};

#endif