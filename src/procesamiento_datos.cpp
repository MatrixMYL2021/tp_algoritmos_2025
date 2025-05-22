#include "procesamiento_datos.h"
#include <iostream>
#include <limits>
using namespace std;

void ProcesadorEstadisticas::cargarDatos() {
    cout << "=== Carga de datos de huertas ===\n";
    while (true) {
        int id;
        cout << "Identificador (0 para finalizar): ";
        cin >> id;
        if (!cin || id == 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string barrio;
        cout << "Barrio: ";
        getline(cin, barrio);

        char tipo;
        cout << "Tipo de cultivo (H/F/A/L/O): ";
        cin >> tipo;

        float superficie;
        cout << "Superficie (m2): ";
        cin >> superficie;

        float produccion;
        cout << "Producción mensual (kg): ";
        cin >> produccion;

        char fert;
        cout << "¿Usa fertilizante? (S/N): ";
        cin >> fert;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Actualizar estadísticas
        totalHuertas++;
        produccionTotal += produccion;
        superficieTotal += superficie;
        if (toupper(fert) == 'S')
            contadorFertilizantes++;
        conteoCultivos[toupper(tipo)]++;
        conteoBarrios[barrio]++;
    }
    cout << "Carga finalizada. Total de huertas: " << totalHuertas << "\n";
}

void ProcesadorEstadisticas::mostrarResultados() const {
    if (totalHuertas == 0) {
        cout << "No hay datos. Primero carga las huertas.\n";
        return;
    }

    cout << "\n=== Resultados ===\n";
    cout << "Total de huertas: " << totalHuertas << "\n";
    cout << "Producción promedio (kg): "
         << (produccionTotal / totalHuertas) << "\n";
    cout << "Porcentaje con fertilizante: "
         << (contadorFertilizantes * 100.0f / totalHuertas) << " %\n";

    // Tipo de cultivo más frecuente
    char tipoFrecuente = ' ';
    int maxCant = 0;
    for (auto &p : conteoCultivos) {
        if (p.second > maxCant) {
            maxCant = p.second;
            tipoFrecuente = p.first;
        }
    }
    string tipoStr;
    switch (tipoFrecuente) {
        case 'H': tipoStr = "hortalizas"; break;
        case 'F': tipoStr = "frutas";     break;
        case 'A': tipoStr = "aromáticas"; break;
        case 'L': tipoStr = "legumbres";  break;
        case 'O': tipoStr = "otros";      break;
        default:  tipoStr = "desconocido";
    }
    cout << "Cultivo más frecuente: " << tipoStr << "\n";

    cout << "Superficie promedio (m2): "
         << (superficieTotal / totalHuertas) << "\n";

    cout << "Huertas por barrio:\n";
    for (auto &p : conteoBarrios) {
        cout << "  - " << p.first << ": " << p.second << "\n";
    }
}
