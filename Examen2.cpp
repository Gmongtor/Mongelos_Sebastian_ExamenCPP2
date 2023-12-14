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
 void imprimirEstudiante(Estudiante estudiante){
     cout << "Nombre: " << estudiante.nombre << endl;
     cout << "Edad: " << estudiante.edad << endl;
     cout << "Promedio: " << estudiante.promedio << endl;
 }
 void agregarMateria(Estudiante estudiante, string materia){
     estudiante.materias.push_back(materia);
 }
int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Sebastian";
    estudiante1.edad = 18;
    estudiante1.promedio = 0;
    imprimirEstudiante(estudiante1);
    return 0;
}
