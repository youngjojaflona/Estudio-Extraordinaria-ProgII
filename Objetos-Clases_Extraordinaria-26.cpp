//
// Created by jonyf on 01/06/2026.
//

#include <iostream>
#include <stdlib.h>
#include "PluginAudio.h"
#include "PluginAudioAbstract.h"

#pragma region MAIN GEMINI PLUGINS
int main1() {

    // Ejemplo de ceacion de objeto y uso de aplanar()
    PluginAudio EQ(9.99, "Pro-Q3");

    std::string test = EQ.aplanar2();
    std::cout << test << std::endl;
    //================================================


    // Ejemplo con herencia
    // Variable polimórfica: Un puntero de la clase base (madre) apuntando a un hijo
    PluginAudioAbstract* miPlugin = new PluginSuscripcion("FabFilter Pro-Q3", 9.99);

    // C++ decidirá en tiempo de ejecución llamar al métod de PluginSuscripcion
    std::cout << "Coste suscripcion (12 meses): "
              << miPlugin->calcularCosteAnual(12) << " Euros" << std::endl;

    delete miPlugin; // Llama primero al destructor del hijo y luego al del padre

    // Cambiamos el puntero a un plugin perpetuo
    miPlugin = new PluginPerpetuo("Soundtoys Echoboy", 149.00);

    // Aquí ejecutará la lógica de PluginPerpetuo, devolviendo un valor fijo
    std::cout << "Coste perpetuo (12 meses): "
              << miPlugin->calcularCosteAnual(12) << " Euros" << std::endl;

    delete miPlugin;

    return 0;
}

#pragma endregion

#pragma region MAIN GEMINI LOGISTICA
#include "PaquetePostal.h"
#include "PaquetePostalAbstract.h"

int main_log() {

    // Clase inicial
    PaquetePostal miPaquete("Arturia MiniLab 3", 3.25);

    if (miPaquete.esLigero()) {
        std::cout << miPaquete.resumir() << std::endl;
    }

    // Clase abstracta
    PaquetePostalAbstract* paqueton = new PaqueteNacional("90210", 3.99);

    double tarifaPaqueton = paqueton->calcularTarifaEnvio(60.5);
    std::cout << tarifaPaqueton << std::endl;

    delete paqueton;

    PaquetePostalAbstract* paquetito = new PaqueteInternacional("28903", 0.006);
    double tarifaPaquetito = paquetito->calcularTarifaEnvio(700);
    std::cout << tarifaPaquetito << std::endl;
    delete paquetito;

    return 0;
}

#pragma endregion

#pragma region PRUEBA PERSONAL
#include "RazaHumana.h"

int main() {

    Moro riadChouChou(1.78, 20);
    Panchito jonathan(1.71, 20);

    std::cout << riadChouChou.fraseTipica() << std::endl;
    if (riadChouChou.getTono() > 0) {
        std::stringstream ss;
        ss << "Tono de piel: " << riadChouChou.getTono() << ". Mmm demasiado oscurito para mi gusto.";
        std::cout << ss.str() << std::endl;
    }

    std::cout << jonathan.fraseTipica() << std::endl;
    if (jonathan.getTono() > 0) {
        std::stringstream ss;
        ss << "Tono de piel: " << jonathan.getTono() << ". Mmm demasiado oscurito para mi gusto.";
        std::cout << ss.str() << std::endl;
    }

    if (RazaHumana::getCount() < 3) {
        std::cout << "Total de personas: " << std::to_string(RazaHumana::getCount()) << ". Bueno, está bien." << std::endl;
    } else { std::cout << "Total de personas: " << std::to_string(RazaHumana::getCount()) << ". Demasiados" << std::endl;}

    Negro chemita(1.96, 19);

    std::cout << chemita.fraseTipica() << std::endl;
    if (chemita.getTono() > 0) {
        std::stringstream ss;
        ss << "Tono de piel: " << chemita.getTono() << ". Mmm demasiado oscurito para mi gusto.";
        std::cout << ss.str() << std::endl;
    }

    if (RazaHumana::getCount() < 3) {
        std::cout << "Total de personas: " << std::to_string(RazaHumana::getCount()) << ". Bueno, esta bien." << std::endl;
    } else { std::cout << "Total de personas: " << std::to_string(RazaHumana::getCount()) << ". Demasiados" << std::endl;}

    return 0;
}

#pragma endregion

#pragma region SEGUNDO EXAMEN 25/26

