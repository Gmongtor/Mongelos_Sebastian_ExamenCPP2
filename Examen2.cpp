#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
};
 void imprimirEstudiante(Estudiante estudiante){
     cout << "Nombre: " << estudiante.nombre << endl;
     cout << "Edad: " << estudiante.edad << endl;
     cout << "Promedio: " << estudiante.promedio << endl;
 }