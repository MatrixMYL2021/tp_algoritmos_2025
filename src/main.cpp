#include <iostream>
#include <limits>
#include "procesamiento_datos.h"
using namespace std;

int main() {
    ProcesadorEstadisticas procesador;
    int opcion;

    do {
        cout << "\n=== Menú Huertas (Plan Verde) ===\n"
             << "1. Cargar datos\n"
             << "2. Mostrar resultados\n"
             << "3. Salir\n"
             << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                procesador.cargarDatos();
                break;
            case 2:
                procesador.mostrarResultados();
                break;
            case 3:
                cout << "¡Adiós!\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 3);

    return 0;
}

