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
