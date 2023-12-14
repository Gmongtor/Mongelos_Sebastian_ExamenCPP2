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