#ifndef PROCESAMIENTO_DATOS_H
#define PROCESAMIENTO_DATOS_H

#include <string>
#include <map>
using namespace std;

class ProcesadorEstadisticas {
public:
    // Lee datos hasta que id == 0 y acumula estadísticas
    void cargarDatos();

    // Muestra resultados calculados
    void mostrarResultados() const;

private:
    int totalHuertas = 0;
    float produccionTotal = 0.0f;
    int contadorFertilizantes = 0;
    float superficieTotal = 0.0f;

    // Contadores por tipo de cultivo y por barrio
    map<char,int> conteoCultivos;
    map<string,int> conteoBarrios;
};

#endif // PROCESAMIENTO_DATOS_H
