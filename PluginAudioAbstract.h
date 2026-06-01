//
// Created by jonyf on 01/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PLUGINAUDIOABSTRACT_H
#define TDAS_EXTRAOD_26_PLUGINAUDIOABSTRACT_H
#include <string>


class PluginAudioAbstract {
protected:
    std::string nombrePlugin;
public:
    // Constructor y destructor obligatorio
    PluginAudioAbstract(std::string nombrePlugin): nombrePlugin(nombrePlugin) {}
    virtual ~PluginAudioAbstract() {}

    // Getters
    std::string getNombrePlugin() const { return this->nombrePlugin; }

    // Otros
    virtual double calcularCosteAnual(int mesesUso) = 0;

};

class PluginSuscripcion : public PluginAudioAbstract {
private:
    float cuotaMensual;
public:
    // Constructor
    PluginSuscripcion(std::string nombrePlugin, float cuotaMensual): PluginAudioAbstract(nombrePlugin), cuotaMensual(cuotaMensual) {}

    // Otro
    double calcularCosteAnual(int mesesUso) override {
        return this->cuotaMensual * mesesUso;
    }
};

class PluginPerpetuo : public PluginAudioAbstract {
private:
    float pagoUnico;
public:
    // Constructor
    PluginPerpetuo(std::string nombrePlugin, float pagoUnico): PluginAudioAbstract(nombrePlugin), pagoUnico(pagoUnico) {}

    // Otro
    double calcularCosteAnual(int mesesUso) override {
        return this->pagoUnico;
    }
};


#endif //TDAS_EXTRAOD_26_PLUGINAUDIOABSTRACT_H