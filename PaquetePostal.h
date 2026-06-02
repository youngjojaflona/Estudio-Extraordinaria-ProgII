//
// Created by jonyf on 02/06/2026.
//

#ifndef TDAS_EXTRAOD_26_PAQUETEPOSTAL_H
#define TDAS_EXTRAOD_26_PAQUETEPOSTAL_H
#include <string>
#include <sstream>


class PaquetePostal {
private:
    double pesoKilos;
    std::string codigoSeguimiento;
public:
    // Constructora
    PaquetePostal(std::string codigoSeguimiento, double pesoKilos):
    codigoSeguimiento(codigoSeguimiento), pesoKilos(pesoKilos) {}

    // Getters
    std::string getCodigoSeguimiento() { return this->codigoSeguimiento; }
    double getPesoKilos() { return this->pesoKilos; }

    //Setters
    void setPesoKilos(double pesoKilos) { this->pesoKilos = pesoKilos; }

    // Otros
    bool esLigero() {
        if (this->pesoKilos <= 23) {
            return true;
        } else {
            return false;
        }
    }

    std::string resumir() {
        std::stringstream ss;
        ss << "tracking = " << this->codigoSeguimiento << ", peso = " << this->pesoKilos;
        return ss.str();
    }
};


#endif //TDAS_EXTRAOD_26_PAQUETEPOSTAL_H