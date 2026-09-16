#include <iostream>
#include "Cliente.h"
#include <sstream>
using namespace std;

Cliente::Cliente(string _nombre, int _numero) {
    nombre = _nombre;
    numero = _numero;
}

Cliente::Cliente(){
    nombre = "Vacio";
    numero = 0;
}

Cliente::string getNombre() const {
    return nombre;
}

Cliente::int getNumero() const {
    return numero;
}

Cliente::void setNombre(string _nombre) {
    nombre = _nombre;
}

Cliente::void setNumero(int _numero) {
    numero = _numero;
}  

Cliente::string toString() {
    stringstream ss;
    ss << "Nombre: " << nombre << ", Numero: " << numero;
    return ss.str();
}