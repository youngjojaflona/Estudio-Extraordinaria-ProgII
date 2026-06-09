//
// Created by jonyf on 09/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PROVEEDORIA_H
#define TDAS_EXTRAOD_26_PROVEEDORIA_H
#include <iostream>
#include <string>
#include <sstream>

class ProveedorIA {
private:
    float precioMensual;
    std::string nombreProveedor;
public:
    // Constructora
    ProveedorIA(float precioMensual, std::string nombreProveedor): precioMensual(precioMensual), nombreProveedor(nombreProveedor) {}

    // Getters
    float getPrecioMensual() const { return precioMensual; }
    std::string getNombreProveedor() const { return nombreProveedor; }

    // Setter
    void setPrecioMensual(float precioMensual) { this->precioMensual = precioMensual; }

    // Otros
    std::string aplanar() const {
        std::stringstream ss;
        ss << "precioMensual = " << this->precioMensual << ", nombreProveedor = " << this->nombreProveedor;
        return ss.str();
    }
};


#endif //TDAS_EXTRAOD_26_PROVEEDORIA_H