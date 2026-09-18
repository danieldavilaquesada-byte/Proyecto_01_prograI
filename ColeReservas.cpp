#include <iostream>
using namespace std;
#include "ColeReservas.h"
ColeReservas::ColeReservas(){
    canti=0;
    for(int i=0;i<max;i++){
        reservas[i]=nullptr;
    }
}
bool ColeReservas::agregarReserva(Reserva* reserva){
    if(canti<max){
        reservas[canti]=reserva;
        canti++;
        return true;
    }else{
        return false;
    }
}
void ColeReservas::mostrarT(){
    if(canti==0){
        cout<<"No hay reservas"<<endl;
    }else{
        for(int i=0;i<canti;i++){
            if(reservas[i]!=nullptr){
            reservas[i]->mostrarReserva();
            }
        }
    }
}
Reserva* ColeReservas::buscarReserva(int num){
    for(int i=0;i<canti;i++){
        if(reservas[i]!=nullptr&&reservas[i]->getnumReser()==num){
            return reservas[i];
        }
    }
    return nullptr;
}
void ColeReservas::mostrarXcancha(string codigo){
    bool encontro=false;
    for(int i=0;i<cant;i++){
        if(resrervas[i]!=nullptr&&reservas[i]->getCancha()->getCodigo()==codigo){
            reservas[i]->mostrarReserva();
            encontro=true;
        }
    }
    if(encontro==false){
        cout<<"No hay reservas para esa cancha"<<endl;
    }
}
bool ColeReservas::cancelarReserva(int num){
    Reserva* reserva=buscarReserva(num);
    if(reserva!=nullptr){
        reserva->cancelarReserva();
        return true;
    }
    cout<<"La reserva no se encontro"<<endl;
        return false;
    }
