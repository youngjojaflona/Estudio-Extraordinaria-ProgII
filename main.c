#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma region EJEMPLO GEMINI PLUGINS
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

    // Buffer de datos
    char linea[MAX_LINEA];
    char auxTipo[20];
    char auxName[CHAR_LIZ];
    float auxPrice;

    // Recorrido del fichero
    while (fgets(linea, sizeof(linea), fichero) != NULL) {
        sscanf(linea, "%s %f %s", auxTipo, &auxPrice, auxName);

        if (strcmp(auxName, desarrolladorBuscado) == 0) {

            // Reserva de memoria para la estructura.
            // Como ninguno de los campos del struct es un puntero*, solo hacemos un malloc.
            TipoLicenciaPlugin* plugin = (TipoLicenciaPlugin*)malloc(sizeof(TipoLicenciaPlugin));
            if (plugin == NULL) { fclose(fichero); return NULL; }

            // Rellenar campos
            strcpy(plugin->nombreDesarrollador, auxName);
            plugin->precioMensual = auxPrice;
            if (strcmp(auxTipo, "DEMO") == 0) { plugin->tipoLicencia = DEMO; }
            else if (strcmp(auxTipo, "SUSCRIPCION") == 0) { plugin->tipoLicencia = SUSCRIPCION; }
            else if (strcmp(auxTipo, "PERPETUA") == 0) { plugin->tipoLicencia = PERPETUA; }

            // Cerrar y devolver
            fclose(fichero);
            return plugin;
        }
    }
    fclose(fichero);
    return NULL;
}

int main1(void) {

    TipoLicenciaPlugin* plugin = buscarLicenciaPorDesarrollador("Plugins.txt", "Soundtoys");
    printf("Precio de %s: %.2f\n", plugin->nombreDesarrollador, plugin->precioMensual);
    free(plugin);

    return 0;
}
#pragma endregion

#pragma region EJEMPLO GEMINI LOGISTICA
#define CHAR_LOG 9
#define MAX_LINEA 1024

enum NivelUrgencia {
    ESTANDAR,
    EXPRES,
    PREMIUM
};

typedef struct {
    char codigoCiudad[CHAR_LOG];
    double pesoKilos;
    enum NivelUrgencia tipoUrgencia;
} TipoEnvioPaquete;

TipoEnvioPaquete* buscarMasPesadoPorCiudad(char* nombreFichero, char* ciudadBuscada) {

    FILE* fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) { return NULL; }

    char linea[MAX_LINEA];
    char auxNivel[20];
    double auxPeso;
    char auxCiudad[CHAR_LOG];

    while (fgets(linea, sizeof(linea), fichero)) {
        sscanf(linea, "%s %lf %s", auxNivel, &auxPeso, auxCiudad);

        if (strcmp(auxCiudad, ciudadBuscada) == 0) {

            TipoEnvioPaquete* paquete = (TipoEnvioPaquete*)malloc(sizeof(TipoEnvioPaquete));
            if (paquete == NULL) { fclose(fichero); free(paquete); return NULL; }

            strcpy(paquete->codigoCiudad, auxCiudad);
            paquete->pesoKilos = auxPeso;
            if (strcmp(auxNivel, "ESTANDAR") == 0) { paquete->tipoUrgencia = ESTANDAR; }
            else if (strcmp(auxNivel, "EXPRES") == 0) { paquete->tipoUrgencia = EXPRES; }
            else if (strcmp(auxNivel, "PREMIUM") == 0) { paquete->tipoUrgencia = PREMIUM; }

            fclose(fichero);
            return paquete;
        }
    }

    fclose(fichero);
}

int main() {

    TipoEnvioPaquete* miPaquete = buscarMasPesadoPorCiudad("Logistica.txt", "TOKYO");
    printf("Paquete de %s encontrado. Peso: %.2fkg. Nivel de urgencia: %d"
        , miPaquete->codigoCiudad, miPaquete->pesoKilos, miPaquete->tipoUrgencia);

    free(miPaquete);

    return 0;
}

#pragma endregion