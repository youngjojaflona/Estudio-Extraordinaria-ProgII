//
// Created by jonyf on 05/06/2026.
//

#ifndef TDAS_EXTRAOD_26_RAZAHUMANA_H
#define TDAS_EXTRAOD_26_RAZAHUMANA_H
#include <string>

enum TipoTono {
    BLANCO,
    MARRON,
    AMARILLO,
    NEGRO,
    MARRON_INDIO
} ;

class RazaHumana {
private:
    // Miembro compartido por todas las clases hijas
    static int count;

protected:
    TipoTono tono;
    float altura;
    int edad;

public:
    // Constructora y destructora virtual
    RazaHumana();
    RazaHumana(float altura, int edad):
    tono(tono), altura(altura), edad(edad) {}
    virtual ~RazaHumana();

    // Getters
    TipoTono getTono() const { return this->tono; }
    float getAltura() const { return this->altura; }
    int getEdad() const { return this->edad; }

    // Setters
    void setTono(TipoTono tono){ this->tono = tono; }
    void setAltura(float altura){ this->altura = altura; }
    void setEdad(int edad){ this->edad = edad; }

    // Métodos
    virtual std::string fraseTipica() = 0;

};

class Moro : public RazaHumana {
public:
    // Constructoras y destructoras
    Moro();
    Moro(float altura, int edad): RazaHumana(altura, edad) { this->tono = MARRON; }

    // Metodo
    std::string fraseTipica() override;

};

class Panchito : public RazaHumana {
public:
    // Constr y destr
    Panchito();
    Panchito(float altura, int edad): RazaHumana(altura, edad) { this->tono = MARRON; }

    // Metodo
    std::string fraseTipica() override;
};


#endif //TDAS_EXTRAOD_26_RAZAHUMANA_H