#ifndef GESTORCANCHAS_H
#define GESTORCANCHAS_H

#include <string>
#include "Canchas.h"

const int MAX_CANCHAS = 10;

// Clase tipo colección: administra el conjunto de canchas del sistema.
// Usa un arreglo fijo de punteros a Cancha; cada Cancha se crea con new.
class GestorCanchas {
private:
    Cancha* canchas[MAX_CANCHAS];
    int cantidad; // canchas actualmente registradas

public:
    GestorCanchas();
    ~GestorCanchas(); // libera cada Cancha creada dinámicamente

    // Registra una nueva cancha. Retorna false si ya está llena o el código existe.
    bool registrarCancha(const std::string& codigo, const std::string& tipoDeporte, double precioPorHora);

    // Retorna true si ya existe una cancha con ese código.
    bool existeCodigo(const std::string& codigo) const;

    // Retorna el puntero a la cancha encontrada, o nullptr si no existe.
    Cancha* buscarPorCodigo(const std::string& codigo) const;

    // Muestra el listado resumido de todas las canchas registradas.
    void mostrarTodas() const;

    // Cambia el precio por hora de una cancha existente. Retorna false si no existe o precio inválido.
    bool modificarPrecio(const std::string& codigo, double nuevoPrecio);

    // Muestra el detalle de las 12 franjas horarias de una cancha.
    void mostrarDisponibilidad(const std::string& codigo) const;

    int getCantidad() const;
    bool estaLlena() const;
};

#endif