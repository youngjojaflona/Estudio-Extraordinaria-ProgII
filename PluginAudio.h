//
// Created by jonyf on 01/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PLUGINAUDIO_H
#define TDAS_EXTRAOD_26_PLUGINAUDIO_H
#include <string>
#include <sstream>


class PluginAudio {
private:
    float precioMensual;
    std::string nombrePlugin;
public:
    // Constructores
    PluginAudio();
    PluginAudio(float precioMensual, std::string nombrePlugin): precioMensual(precioMensual), nombrePlugin(nombrePlugin) {}

    // Getters
    float getPrecioMensual() const { return precioMensual; }
    std::string getNombrePlugin() const { return nombrePlugin; }

    // Setter
    void setPrecioMensual(float precioMensual){ this->precioMensual = precioMensual; }

    // Otros
    std::string aplanar() const {
        return "precioMensual = " + std::to_string(this->precioMensual) + ", nombrePlugin = " + this->nombrePlugin;
    }

    // Alternativo de aplanar
    // Métod0 aplanar: devuelve un std::string formateado con los datos
    std::string aplanar2() const {
        std::stringstream ss;
        ss << "precioMensual = " << this->precioMensual << ", nombrePlugin = " << this->nombrePlugin;
        return ss.str();
    }

};


#endif //TDAS_EXTRAOD_26_PLUGINAUDIO_H