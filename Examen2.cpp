#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <algorithm>

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
        if (find(materias.begin(), materias.end(), materia) == materias.end()) {
            throw MateriaInvalidaException();
        }
        if (fecha.length() != 10 || fecha[4] != '-' || fecha[7] != '-') {
            throw FechaInvalidaException();
        }

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

    try {
        estudiante1.registrarAsistencia("2023-12-11", "Matematicas", Asistio);
        estudiante1.registrarAsistencia("2023-12-12", "Fisica", Falta);
        estudiante1.registrarAsistencia("2023-12-13", "Quimica", Tardanza);
        // Puedes añadir aquí registros adicionales para probar las excepciones
    } catch (const FechaInvalidaException& e) {
        cout << "Excepción capturada: " << e.what() << endl;
    } catch (const MateriaInvalidaException& e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }

    imprimirEstudiante(estudiante1);

    return 0;
}


