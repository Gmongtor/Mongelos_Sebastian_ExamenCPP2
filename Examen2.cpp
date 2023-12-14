#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    vector<string> materias;
};
 void imprimirEstudiante(Estudiante estudiante) {
     cout << "Nombre: " << estudiante.nombre << endl;
     cout << "Edad: " << estudiante.edad << endl;
     cout << "Promedio: " << estudiante.promedio << endl;
     cout << "Materias: " << endl;
     for (int i = 0; i < estudiante.materias.size(); i++) {
         cout << estudiante.materias[i] << endl;
     }
     void agregarMateria(Estudiante estudiante, string materia) {
         estudiante.materias.push_back(materia);
     }
     void eliminarMateria(Estudiante estudiante, string materia) {
         for (int i = 0; i < estudiante.materias.size(); i++) {
             if (estudiante.materias[i] == materia) {
                 estudiante.materias.erase(estudiante.materias.begin() + i);
             }
         }
     }
 }
    int main() {
        Estudiante estudiante1;
        estudiante1.nombre = "Juan";
        estudiante1.edad = 20;
        estudiante1.promedio = 9.5;
        estudiante1.materias.push_back("Matematicas");
        estudiante1.materias.push_back("Fisica");
        estudiante1.materias.push_back("Quimica");
        imprimirEstudiante(estudiante1);
        agregarMateria(estudiante1, "Programacion");
        imprimirEstudiante(estudiante1);
        eliminarMateria(estudiante1, "Fisica");
        imprimirEstudiante(estudiante1);
        return 0;
    }