#include <iostream>
#include "Espera.h"
#include "Cliente.h"
#include "Canchas.h"
#include <sstream>
using namespace std;

Espera::Espera(int _consecutivo, Cliente* _cliente, Cancha* _cancha, int _franja, string _estado){
    consecutivo = _consecutivo;
    cliente = _cliente;
    cancha = _cancha;
    franja = _franja;
    estado = _estado;

}

Espera::Espera(){
consecutivo = 0;
cliente = NULL;
cancha = NULL;
franja = -1;
estado =  "sin especificar";
}

int Espera::getConsecutivo() const {
    return consecutivo;
}

Cliente* Espera::getCliente() const {
    return cliente;
}

Cancha* Espera::getCancha() const {
    return cancha;
}

int Espera::getFranja() const {
    return franja;
}

string Espera::getEstado() const {
    return estado;
}

void Espera::setEstado(string _estado){
    estado = _estado;
}

void Espera::setConsecutivo(int _consecutivo){
    consecutivo = _consecutivo;
}

string Espera::toString() const {
    stringstream s;
    s<<"Consecutivo: "<<consecutivo<<endl;
    s<<"Nombre cliente: "<<cliente->getNombre()<<" Numero cliente: "<<cliente->getNumero()<<" Id cliente: "<<cliente->getId()<<endl;
    s<<"Codigo cancha: "<<cancha->getCodigo()<<" Deporte de la cancha: "<<cancha->getDeporte()<<" Precio cancha: "<<cancha->getPrecio()<<endl;
    s<<"Franja: "<<franja<<endl;
    s<<"Estado: "<<estado<<endl;
    return s.str();
}
