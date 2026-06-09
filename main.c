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

int main_log() {

    TipoEnvioPaquete* miPaquete = buscarMasPesadoPorCiudad("Logistica.txt", "TOKYO");
    printf("Paquete de %s encontrado. Peso: %.2fkg. Nivel de urgencia: %d"
        , miPaquete->codigoCiudad, miPaquete->pesoKilos, miPaquete->tipoUrgencia);

    free(miPaquete);

    return 0;
}

#pragma endregion

#pragma region TAD CON PUNTERO
#define CHAR_AUD 16

enum TipoFormato {
    WAV,
    MP3,
    FLAC
};

typedef struct {
    char identificador[CHAR_AUD];
    enum TipoFormato formato;
    int totalElementos;
    float* datosPCM;
} TipoMuestraAudio;

TipoMuestraAudio* crearMuestra(char* id, enum TipoFormato formato, int numElementos) {

    TipoMuestraAudio* miMuestra = (TipoMuestraAudio*) malloc(sizeof(TipoMuestraAudio));
    if (miMuestra == NULL) { return NULL; }

    strcpy(miMuestra->identificador, id);
    miMuestra->formato = formato;
    miMuestra->totalElementos = numElementos;
    miMuestra->datosPCM = (float*) calloc(numElementos, sizeof(float));
    if (miMuestra->datosPCM == NULL) { free(miMuestra); return NULL; }

    return miMuestra;
}

void destruirMuestra(TipoMuestraAudio* muestra) {

    // Control de seguridad
    if (muestra != NULL) {

        if (muestra->datosPCM != NULL) { free(muestra->datosPCM); }

        free(muestra);
    }
}

int main_point() {

    TipoMuestraAudio* muestra1 = crearMuestra("Cry Baby", WAV, 10);
    destruirMuestra(muestra1);

    return 0;
}

#pragma endregion

#pragma region LECTURA Y ESCRITURA DE FICHEROS
// Busco hacer una función que escriba TDAs en un fichero txt y luego los lea
#define CHAR_PERF 32

enum TipoEstacion {
    PRIMAVERA = 1,
    VERANO,
    OTONYO,
    INVIERNO
};

typedef struct {
    char marca[CHAR_PERF];
    char version[CHAR_PERF];
    char notaMain[CHAR_PERF];
    enum TipoEstacion estacion;
    double precio;
} TipoPerfume;

TipoPerfume* crearPerfume(char* marca, char*version, char* notaMain, enum TipoEstacion estacion, double precio) {

    TipoPerfume* miPerfume = (TipoPerfume*) malloc(sizeof(TipoPerfume));
    if (miPerfume == NULL) { return NULL; }

    strcpy(miPerfume->marca, marca);
    strcpy(miPerfume->version, version);
    strcpy(miPerfume->notaMain, notaMain);
    miPerfume->estacion = estacion;
    miPerfume->precio = precio;

    return miPerfume;
}

void destruirPerfume(TipoPerfume* perfume) {
    if (perfume != NULL) {
        free(perfume);
    }
}

TipoPerfume* searchMarcaPerfume(char* marcaBuscada) {

    FILE* fichero = fopen("Perfumes.txt", "r");
    if (fichero == NULL) { perror("Error al abrir el fichero"); return NULL; }

    char linea[MAX_LINEA];
    char auxMarca[CHAR_PERF];
    char auxVersion[CHAR_PERF];
    char auxNotaMain[CHAR_PERF];
    float auxPrecio;
    enum TipoEstacion auxEstacion;

    while (fgets(linea, sizeof(linea), fichero)) {
        sscanf(linea, "%[^,],%[^,],%[^,],%d,%f", auxMarca, auxVersion, auxNotaMain, &auxEstacion, &auxPrecio);

        if (strcmp(auxMarca, marcaBuscada) == 0) {
            TipoPerfume* perfume = crearPerfume(auxMarca, auxVersion, auxNotaMain, auxEstacion, auxPrecio);

            fclose(fichero);
            return perfume;
        }
    }

    fclose(fichero);
    return NULL;
}

void addPerfume(TipoPerfume perfume) {

    FILE* fichero = fopen("Perfumes.txt", "a");
    if (fichero == NULL) { perror("Error al abrir el fichero"); return; }

    fprintf(fichero, "%s,%s,%s,%d,%f\n",
        perfume.marca, perfume.version, perfume.notaMain, perfume.estacion, perfume.precio);

    fclose(fichero);
}

void muestraPerfume(TipoPerfume perfume) {

    printf("Nombre: %s %s\nNota principal: %s\n", perfume.marca, perfume.version, perfume.notaMain);
    if (perfume.estacion == PRIMAVERA) { printf("Estacion principal: Primaavera\n"); }
    else if (perfume.estacion == VERANO) { printf("Estacion principal: Verano\n"); }
    else if (perfume.estacion == OTONYO) { printf("Estacion principal: Otonyo\n"); }
    else if (perfume.estacion == INVIERNO) { printf("Estacion principal: Invierno\n"); }
    printf("Precio: %.2f", perfume.precio);

}

void limpiaFichero(char* nameFichero) {
    FILE* fichero = fopen(nameFichero, "w");
    if (fichero != NULL) { fclose(fichero); }
}


// Ahora en un fichero binario

void addPerfumeBin(TipoPerfume* perfume) {

    FILE* fichero = fopen("PerfumesBin.bin", "ab");
    if (fichero == NULL) { perror("Error al abrir el fichero"); return; }

    fwrite(perfume, sizeof(TipoPerfume), 1, fichero);

    fclose(fichero);
}

TipoPerfume* searchPerfumeMarcaBin(char* nameMarca) {

    FILE* fichero = fopen("PerfumesBin.bin", "rb");
    if (fichero == NULL) { return NULL; }

    TipoPerfume* buscado = (TipoPerfume*) malloc(sizeof(TipoPerfume));
    if (buscado == NULL) { return NULL; }

    // Recorremos con fread en la condicion
    while (fread(buscado, sizeof(TipoPerfume), 1, fichero)) {
        if (strcmp(buscado->marca, nameMarca) == 0) {
            fclose(fichero);
            return buscado;
        }
    }

    free(buscado);
    fclose(fichero);
    return NULL;
}


int main() {

    TipoPerfume* perfumeJony = crearPerfume("Givenchy", "gentleman society", "talco", INVIERNO, 75.99);

    addPerfumeBin(perfumeJony);

    TipoPerfume* perfumeBuscado = searchPerfumeMarcaBin("Givenchy");

    muestraPerfume(*perfumeBuscado);

    destruirPerfume(perfumeJony);
    destruirPerfume(perfumeBuscado);

    return 0;
}

#pragma endregion

#pragma region SEGUNDO EXAMEN 25/26
#define CHAR_PROV 11

enum TipoPago {
    GRATIS,
    TRANSFERENCIA,
    TARJETA
};

typedef struct {
    char nombreProveedor[CHAR_PROV];
    double precioMensual;
    enum TipoPago formaPago;
} TipoSubscripcionIA;


TipoSubscripcionIA* buscar(char* nombreFichero, char* filtroPorveedor) {

    FILE* fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) { return NULL; }

    char buffer[1025];
    char auxNombre[CHAR_PROV];
    float auxPrecio;
    char auxFormaPago[20];
    enum TipoPago pagoMapeado;

    while (fgets(buffer, sizeof(buffer), fichero)) {
        if (sscanf(buffer, "%s %f %s", auxNombre, &auxPrecio, auxFormaPago)) {

            int pagoValido = 0;
            if (strcmp(auxFormaPago, "GRATIS") == 0) { pagoMapeado = GRATIS; }
            else if (strcmp(auxFormaPago, "TRANSFERENCIA") == 0) { pagoMapeado = TRANSFERENCIA; }
            else if (strcmp(auxFormaPago, "TARJETA") == 0) { pagoMapeado = TARJETA; }
            else { pagoValido = 0; }

            if (!pagoValido) { continue; }

            if (strcmp(auxNombre, filtroPorveedor) == 0) {
                TipoSubscripcionIA* suscripcion =(TipoSubscripcionIA*) malloc(sizeof(TipoSubscripcionIA));
                if (suscripcion == NULL) { fclose(fichero); return NULL; }

                strcpy(suscripcion->nombreProveedor, auxNombre);
                suscripcion->precioMensual = auxPrecio;
                suscripcion->formaPago = pagoMapeado;

                fclose(fichero);
                return suscripcion;
            }
        }
    }

    fclose(fichero);
    return NULL;
}