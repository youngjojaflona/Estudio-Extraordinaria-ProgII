//
// Created by jonyf on 02/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PAQUETEPOSTALABSTRACT_H
#define TDAS_EXTRAOD_26_PAQUETEPOSTALABSTRACT_H
#include <string>


class PaquetePostalAbstract {
private:
    std::string codigoSeguimiento;
public:
    // Constructora
    PaquetePostalAbstract(std::string codigoSeguimiento):
    codigoSeguimiento(codigoSeguimiento) {}

    ~PaquetePostalAbstract() {}

    // Getters
    std::string getCodigoSeguimiento() { return this->codigoSeguimiento; }

    // Otros
    virtual double calcularTarifaEnvio(double distanciaKm) = 0;

};

class PaqueteNacional: public PaquetePostalAbstract {
private:
    double tarifaFija;
public:
    //Constructora
    PaqueteNacional(std::string codigoSeguimiento, double tarifaFija):
    PaquetePostalAbstract(codigoSeguimiento), tarifaFija(tarifaFija) {}

    double calcularTarifaEnvio(double distanciaKm) override {
        return this->tarifaFija;
    }
};

class PaqueteInternacional: public PaquetePostalAbstract {
private:
    double precioPorKm;
public:
    // Costructora
    PaqueteInternacional(std::string codigoSeguimiento, double precioPorKm):
    PaquetePostalAbstract(codigoSeguimiento), precioPorKm(precioPorKm) {}

    // Otros
    double calcularTarifaEnvio(double distanciaKm) override {
        double calculo = precioPorKm * distanciaKm;
        return calculo;
    }
};


#endif //TDAS_EXTRAOD_26_PAQUETEPOSTALABSTRACT_H