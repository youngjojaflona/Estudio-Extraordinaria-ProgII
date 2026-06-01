//
// Created by jonyf on 01/06/2026.
//

#include <iostream>
#include <stdlib.h>
#include "PluginAudio.h"
#include "PluginAudioAbstract.h"

int main() {

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
