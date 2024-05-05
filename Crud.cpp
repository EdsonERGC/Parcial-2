#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_ESTUDIANTES 100

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    string resultado;
};

void calcularPromedio(Estudiante &estudiante) {
    float suma = 0;
    for (int i = 0; i < 4; i++) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / 4;
}

void determinarResultado(Estudiante &estudiante) {
    if (estudiante.promedio >= 60) {
        estudiante.resultado = "Aprobado";
    } else {
        estudiante.resultado = "Reprobado";
    }
}

void agregarEstudiante(ofstream &archivo, const Estudiante &estudiante) {
    archivo.write(reinterpret_cast<const char*>(&estudiante), sizeof(Estudiante));
}

void leerEstudiante(ifstream &archivo, Estudiante &estudiante) {
    archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad_estudiantes = 0;

    ofstream archivo("notas.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;

    for (int i = 0; i < cantidad_estudiantes; i++) {
        cout << "\nIngrese los datos del estudiante " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "Nota 1: ";
        cin >> estudiantes[i].notas[0];
        cout << "Nota 2: ";
        cin >> estudiantes[i].notas[1];
        cout << "Nota 3: ";
        cin >> estudiantes[i].notas[2];
        cout << "Nota 4: ";
        cin >> estudiantes[i].notas[3];

        calcularPromedio(estudiantes[i]);
        determinarResultado(estudiantes[i]);

        agregarEstudiante(archivo, estudiantes[i]);
    }

    archivo.close();

    cout << "\nDatos almacenados en el archivo notas.dat:\n\n";
    ifstream archivo_lectura("notas.dat", ios::binary);
    if (!archivo_lectura) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    for (int i = 0; i < cantidad_estudiantes; i++) {
        leerEstudiante(archivo_lectura, estudiantes[i]);
        cout << "ID: " << estudiantes[i].id << ", Nombre: " << estudiantes[i].nombre << ", Apellido: " << estudiantes[i].apellido << ", Promedio: " << estudiantes[i].promedio << ", Resultado: " << estudiantes[i].resultado << endl;
    }
    archivo_lectura.close();

    return 0;
}
