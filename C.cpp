#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { Asistio, Falta, Tardanza } EstadoAsistencia;

typedef struct {
    char fecha[11];
    char materia[50];
    EstadoAsistencia estado;
} Asistencia;

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
    char materias[10][50];
    int numMaterias;
    Asistencia asistencias[50];
    int numAsistencias;
} Estudiante;

void agregarMateria(Estudiante* est, const char* materia) {
    if (est->numMaterias < 10) {
        strcpy(est->materias[est->numMaterias++], materia);
    }
}
int esMateriaValida(Estudiante* est, const char* materia) {
    for (int i = 0; i < est->numMaterias; i++) {
        if (strcmp(est->materias[i], materia) == 0) {
            return 1;
        }
    }
    return 0;
}
int esFechaValida(const char* fecha) {
    return (strlen(fecha) == 10 && fecha[4] == '-' && fecha[7] == '-');
}
void registrarAsistencia(Estudiante* est, const char* fecha, const char* materia, EstadoAsistencia estado) {
    if (!esMateriaValida(est, materia)) {
        printf("Error: La materia no existe.\n");
        return;
    }
    if (!esFechaValida(fecha)) {
        printf("Error: El formato de la fecha es inválido.\n");
        return;
    }

    if (est->numAsistencias < 50) {
        strcpy(est->asistencias[est->numAsistencias].fecha, fecha);
        strcpy(est->asistencias[est->numAsistencias].materia, materia);
        est->asistencias[est->numAsistencias].estado = estado;
        est->numAsistencias++;
    }
}
void imprimirEstudiante(Estudiante* est) {
    printf("Nombre: %s\n", est->nombre);
    printf("Edad: %d\n", est->edad);
    printf("Promedio: %.2f\n", est->promedio);
    printf("Materias:\n");
    for (int i = 0; i < est->numMaterias; i++) {
        printf(" - %s\n", est->materias[i]);
    }
    printf("Asistencias:\n");
    for (int i = 0; i < est->numAsistencias; i++) {
        printf("Fecha: %s, Materia: %s, Estado: ", est->asistencias[i].fecha, est->asistencias[i].materia);
        switch (est->asistencias[i].estado) {
            case Asistio:
                printf("Asistió\n");
                break;
            case Falta:
                printf("Falta\n");
                break;
            case Tardanza:
                printf("Tardanza\n");
                break;
        }
    }
}
int main() {
    Estudiante estudiante1 = {"Sebastian", 18, 4.5, {}, 0, {}, 0};

    agregarMateria(&estudiante1, "Matematicas");
    agregarMateria(&estudiante1, "Fisica");
    agregarMateria(&estudiante1, "Quimica");

    registrarAsistencia(&estudiante1, "2023-12-11", "Matematicas", Asistio);
    registrarAsistencia(&estudiante1, "2023-12-12", "Fisica", Falta);
    registrarAsistencia(&estudiante1, "2023-12-13", "Quimica", Tardanza);

    registrarAsistencia(&estudiante1, "20231211", "Matematicas", Asistio); // Fecha mal formateada
    registrarAsistencia(&estudiante1, "2023-12-12", "Historia", Falta);    // Materia no existente

    imprimirEstudiante(&estudiante1);

    return 0;
}