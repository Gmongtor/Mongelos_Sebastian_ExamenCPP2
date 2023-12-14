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

