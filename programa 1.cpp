#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    bool aprobado;
};

int main() {
    int cantidad_estudiantes;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> cantidad_estudiantes;

    vector<Estudiante> estudiantes(cantidad_estudiantes);

    for (int i = 0; i < cantidad_estudiantes; ++i) {
        cout << "Ingrese ID del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese nombres del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombres;
        cout << "Ingrese apellidos del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].apellidos;
        cout << "Ingrese nota 1 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota1;
        cout << "Ingrese nota 2 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota2;
        cout << "Ingrese nota 3 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota3;
        cout << "Ingrese nota 4 del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nota4;

        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4.0;
        estudiantes[i].aprobado = estudiantes[i].promedio >= 60.0;
    }

    cout << "\nResultados:\n";
    for (int i = 0; i < cantidad_estudiantes; ++i) {
        cout << "Estudiante " << i + 1 << ": " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << endl;
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Resultado: " << (estudiantes[i].aprobado ? "Aprobado" : "Reprobado") << endl;
        cout << endl;
    }

    return 0;
}
