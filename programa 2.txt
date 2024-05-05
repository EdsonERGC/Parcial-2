#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

void calcularPromedioYEstado(Estudiante* est) {
    float suma = 0;
    for (int i = 0; i < 4; ++i) {
        suma += est->notas[i];
    }
    est->promedio = suma / 4.0;
    est->aprobado = est->promedio >= 60.0;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> n;

    Estudiante* estudiantes = new Estudiante[n];

    for (int i = 0; i < n; ++i) {
        cout << "ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].apellido;
        for (int j = 0; j < 4; ++j) {
            cout << "Nota " << j + 1 << " del estudiante " << i + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        calcularPromedioYEstado(&estudiantes[i]);
    }

    cout << "\nResultados:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i + 1 << ": " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Resultado: " << (estudiantes[i].aprobado ? "Aprobado" : "Reprobado") << endl;
        cout << endl;
    }

    delete[] estudiantes;
    return 0;
}
