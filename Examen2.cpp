#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>

using namespace std;

class FechaInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "El formato de la fecha es inválido.";
    }
};
class MateriaInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "La materia no existe.";
    }
};

enum EstadoAsistencia { Asistio, Falta, Tardanza };

struct Asistencia {
    string fecha;
    string materia;
    EstadoAsistencia estado;
};

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<string> materias;
    vector<Asistencia> asistencias;

    void agregarMateria(const string& materia) {
        materias.push_back(materia);
    }

    void registrarAsistencia(const string& fecha, const string& materia, EstadoAsistencia estado) {
        Asistencia nuevaAsistencia = {fecha, materia, estado};
        asistencias.push_back(nuevaAsistencia);
    }

    void mostrarAsistencias() const {
        cout << "Asistencias de " << nombre << ":" << endl;
        for (const auto& asistencia : asistencias) {
            cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia
                 << ", Estado: " << (asistencia.estado == Asistio ? "Asistió" : asistencia.estado == Falta ? "Falta" : "Tardanza") << endl;
        }
    }
};

void imprimirEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    cout << "Materias: " << endl;
    for (const auto& materia : estudiante.materias) {
        cout << materia << endl;
    }
    estudiante.mostrarAsistencias();
}

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Sebastian";
    estudiante1.edad = 18;
    estudiante1.promedio = 4.5;
    estudiante1.agregarMateria("Matematicas");
    estudiante1.agregarMateria("Fisica");
    estudiante1.agregarMateria("Quimica");

    estudiante1.registrarAsistencia("2023-12-11", "Matematicas", Asistio);
    estudiante1.registrarAsistencia("2023-12-12", "Fisica", Falta);
    estudiante1.registrarAsistencia("2023-12-13", "Quimica", Tardanza);

    imprimirEstudiante(estudiante1);

    return 0;
}


