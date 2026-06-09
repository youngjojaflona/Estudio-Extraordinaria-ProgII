//
// Created by jonyf on 09/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PROVEEDORIAABSTRACT_H
#define TDAS_EXTRAOD_26_PROVEEDORIAABSTRACT_H
#include <string>

#include "ProveedorIA.h"


class ProveedorIAAbstract {
protected:
    std::string nombreProveedor;
public:
    // Constructor y destructor
    ProveedorIAAbstract(std::string nombreProveedor): nombreProveedor(nombreProveedor) {}
    virtual ~ProveedorIAAbstract(){}

    // Getters
    std::string getNombreProveedor() const { return nombreProveedor; }

    // Otros
    virtual double calcularCoste(int nTokens) = 0;
};

class ProveedorIALocal : public ProveedorIAAbstract{
private:
    int puerto;
public:
    // Constructor
    ProveedorIALocal(std::string nombreProveedor, int puerto): ProveedorIA(nombreProveedor), puerto(puerto) {}

    // Otros
    double calcularCoste(int nTokens) override { return 100; }
};

class ProveedorIARemoto : public ProveedorIAAbstract{
private:
    double costePorToken;
public:
    // Constructor
    ProveedorIARemoto(std::string nombreProveedor, double costePorToken): ProveedorIA(nombreProveedor) , costePorToken(costePorToken) {}

    // Otros
    double calcularCoste(int nTokens) override { return this->costePorToken * nTokens; }
};


#endif //TDAS_EXTRAOD_26_PROVEEDORIAABSTRACT_H