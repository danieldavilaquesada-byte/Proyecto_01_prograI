#include <iostream>
#include "Cliente.h"
#include <sstream>
using namespace std;

Cliente::Cliente(string _nombre, int _numero, int _id) {
    nombre = _nombre;
    numero = _numero;
    id = _id;
}

Cliente::Cliente(){
    nombre = "Vacio";
    numero = 0;
    id = 0;
}

Cliente::string getNombre() const {
    return nombre;
}

Cliente::int getNumero() const {
    return numero;
}

Cliente::int getId() const {
    return id;
}

Cliente::void setNombre(string _nombre) {
    nombre = _nombre;
}

Cliente::void setNumero(int _numero) {
    numero = _numero;
}  

Cliente::void setId(int _Id) {
    numero = _Id;
} 

Cliente::string toString() {
    stringstream ss;
    ss << "Nombre: " << nombre << ", Numero: " << numero << ", Id: " << id;
    return ss.str();
}
