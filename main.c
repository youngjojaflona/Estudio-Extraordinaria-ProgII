#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================== EJEMPLO GEMINI 1 ================== */
#define CHAR_LIZ 13
#define MAX_LINEA 1024

// Hacemos el enum a parte para primero declarar este tipo de dato y luego usarlo en la estructura
enum ValoresLicencia {
    DEMO,
    SUSCRIPCION,
    PERPETUA
};

typedef struct {
    char nombreDesarrollador[CHAR_LIZ];
    float precioMensual;
    enum ValoresLicencia tipoLicencia;
} TipoLicenciaPlugin;


TipoLicenciaPlugin* buscarLicenciaPorDesarrollador(char* nombreFichero, char* desarrolladorBuscado) {

    // Abrimos el fichero
    FILE* fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) { printf("no abierto"); return NULL; }

    // Reserva de memoria para la estructura.
    // Como ninguno de los campos del struct es un puntero*, solo hacemos un malloc.
    TipoLicenciaPlugin* plugin = (TipoLicenciaPlugin*)malloc(sizeof(TipoLicenciaPlugin));
    if (plugin == NULL) { printf("no reserva"); return NULL; }

    // Buffer de linea
    char linea[MAX_LINEA];

    // Recorrido del fichero
    while (fgets(linea, sizeof(linea), fichero) != NULL) {
        sscanf(linea, "%i %f %s", plugin->tipoLicencia, plugin->precioMensual, plugin->nombreDesarrollador);
        printf("linea pillada\n");
        if (strcmp(plugin->nombreDesarrollador, desarrolladorBuscado) == 0) {
            fclose(fichero);
            return plugin;
        }
    }
    fclose(fichero);
    free(plugin);
    return NULL;
}

int main(void) {

    TipoLicenciaPlugin* plugin = buscarLicenciaPorDesarrollador("Plugins.txt", "Waves");
    printf("Precio de %s: %f\n", plugin->nombreDesarrollador, plugin->precioMensual);
    free(plugin);

    return 0;
}