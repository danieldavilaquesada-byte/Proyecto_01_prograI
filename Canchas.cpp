#include <iostream>

using namespace std;

const int MAX = 10;   // maximo de canchas
const int LARGO = 30; // largo de codigo y deporte

class Cancha {
private:
    char codigo[LARGO];
    char deporte[LARGO];
    double precio;
    char v[12];  // Guarda: L, O, M

public:
    Cancha();
    Cancha(char cod[], char dep[], double pre);

    char* getCodigo();
    char* getDeporte();
    double getPrecio();
    void setPrecio(double nuevoPrecio);

    void mostrarCancha();
    void mostrarDis();  // las 12

    bool libre(int horaInicial, int horaFinal);
    void ocupado(int horaInicial, int horaFinal);      // marca como O
    void liberar(int horaInicial, int horaFinal);      // marca como L
    void mantenimiento(int horaInicial, int horaFinal);// marca como M
    void quitarMant(int horaInicial, int horaFinal);   // vuelve a L
};

// Constructor por defecto: todo libre
Cancha::Cancha() {
    codigo[0] = '\0';
    deporte[0] = '\0';
    precio = 0.0;
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

// Constructor con datos: todo libre
Cancha::Cancha(char cod[], char dep[], double pre) {
    int i = 0;
    while (cod[i] != '\0' && i < LARGO - 1) {
        codigo[i] = cod[i];
        i++;
    }
    codigo[i] = '\0';

    i = 0;
    while (dep[i] != '\0' && i < LARGO - 1) {
        deporte[i] = dep[i];
        i++;
    }
    deporte[i] = '\0';

    precio = pre;
    for (int i = 0; i < 12; i++) v[i] = 'L';
}

// Getters: devuelven el arreglo interno
char* Cancha::getCodigo() { return codigo; }
char* Cancha::getDeporte() { return deporte; }
double Cancha::getPrecio() { return precio; }

// Setter del precio
void Cancha::setPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
}

// Mostrar los datos de la cancha
void Cancha::mostrarCancha() {
    cout << "Codigo: " << codigo << endl;
    cout << "Deporte: " << deporte << endl;
    cout << "Precio x hora: " << precio << endl;
}

// Mostrar las 12 franjas (horas, estados, posiciones)
void Cancha::mostrarDis() {
    cout << "Disponibilidad de la cancha " << codigo << endl;
    cout << "********************************" << endl;

    int hora = 8;
    for (int i = 0; i < 12; i++) {
        cout << hora << ":00  ";
        hora++;
    }
    cout << endl;

    for (int i = 0; i < 12; i++) {
        cout << " " << v[i] << "    ";
    }
    cout << endl;

    for (int i = 0; i < 12; i++) {
        cout << "[" << i << "]  ";
    }
    cout << endl;
}

// Ver si un rango de franjas esta libre (todas en L)
bool Cancha::libre(int horaInicial, int horaFinal) {
    if (horaInicial < 0 || horaFinal > 11 || horaInicial > horaFinal) {
        return false;
    }
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] != 'L') {
            return false;
        }
    }
    return true;
}

// Marcar un rango como ocupado (O)
void Cancha::ocupado(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'L') v[i] = 'O';
    }
}

// Volver un rango a libre (L)
void Cancha::liberar(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'O') v[i] = 'L';
    }
}

// Marcar un rango como mantenimiento (M)
void Cancha::mantenimiento(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'L') v[i] = 'M';
    }
}

// Quitar mantenimiento (volver a L)
void Cancha::quitarMant(int horaInicial, int horaFinal) {
    for (int i = horaInicial; i <= horaFinal; i++) {
        if (v[i] == 'M') v[i] = 'L';
    }
}

// Comparar dos cadenas de char (devuelve true si son iguales)
bool sonIguales(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

// Buscar una cancha por codigo; devuelve la posicion o -1
int buscarCancha(Cancha canchas[], int total, char codigo[]) {
    for (int i = 0; i < total; i++) {
        if (sonIguales(canchas[i].getCodigo(), codigo)) return i;
    }
    return -1;
}

int main() {
    Cancha canchas[MAX];
    int total = 0;  // cuantas canchas hay registradas
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

    return 0;
}
