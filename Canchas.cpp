
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
<<<<<<< HEAD


bool sonIguales(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}


int buscarCancha(Cancha canchas[], int total, char codigo[]) {
    for (int i = 0; i < total; i++) {
        if (sonIguales(canchas[i].getCodigo(), codigo)) return i;
    }
    return -1;
}

/*int main() {
    Cancha canchas[MAX];
    int total = 0; 
    int opcion;

    do {
        cout << "\n=== GESTION DE CANCHAS ===" << endl;
        cout << "1. Registrar cancha" << endl;
        cout << "2. Mostrar todas las canchas" << endl;
        cout << "3. Buscar cancha por codigo" << endl;
        cout << "4. Modificar precio" << endl;
        cout << "5. Mostrar disponibilidad" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            char codigo[LARGO], deporte[LARGO];
            double precio;

            cout << "Codigo: ";
            cin >> codigo;
            cout << "Deporte: ";
            cin >> deporte;
            cout << "Precio por hora: ";
            cin >> precio;

            if (total >= MAX) {
                cout << "No se pueden registrar mas canchas." << endl;
            } else if (buscarCancha(canchas, total, codigo) != -1) {
                cout << "Error: ya existe una cancha con ese codigo." << endl;
            } else {
                canchas[total] = Cancha(codigo, deporte, precio);
                total++;
                cout << "Cancha registrada." << endl;
            }

        } else if (opcion == 2) {
            if (total == 0) {
                cout << "No hay canchas registradas." << endl;
            } else {
                for (int i = 0; i < total; i++) {
                    canchas[i].mostrarCancha();
                    cout << "----------------" << endl;
                }
            }

        } else if (opcion == 3) {
            char codigo[LARGO];
            cout << "Codigo a buscar: ";
            cin >> codigo;

            int pos = buscarCancha(canchas, total, codigo);
            if (pos == -1) {
                cout << "No se encontro la cancha." << endl;
            } else {
                canchas[pos].mostrarCancha();
            }

        } else if (opcion == 4) {
            char codigo[LARGO];
            double nuevoPrecio;

            cout << "Codigo de la cancha: ";
            cin >> codigo;

            int pos = buscarCancha(canchas, total, codigo);
            if (pos == -1) {
                cout << "No se encontro la cancha." << endl;
            } else {
                cout << "Nuevo precio por hora: ";
                cin >> nuevoPrecio;
                canchas[pos].setPrecio(nuevoPrecio);
                cout << "Precio actualizado." << endl;
            }

        } else if (opcion == 5) {
            char codigo[LARGO];
            cout << "Codigo de la cancha: ";
            cin >> codigo;

            int pos = buscarCancha(canchas, total, codigo);
            if (pos == -1) {
                cout << "No se encontro la cancha." << endl;
            } else {
                canchas[pos].mostrarDis();
            }

        } else if (opcion == 6) {
            cout << "Saliendo..." << endl;

        } else {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 6);

=======
>>>>>>> e3a4b7b3c3d328f5dc8710a1ef6f20f82357af90
    return 0;
}*/
