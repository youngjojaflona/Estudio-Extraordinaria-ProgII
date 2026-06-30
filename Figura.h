//
// Created by jonyf on 27/06/2026.
//

#ifndef TDAS_EXTRAOD_26_FIGURA_H
#define TDAS_EXTRAOD_26_FIGURA_H
#include <sstream>
#include <cmath>
#include <iostream>

class Figura {
public:
    Figura() {}
    virtual ~Figura() {}

    virtual double area() = 0;
    virtual double perimetro() = 0;

    void mostrarInfo() {
        std::stringstream ss;
        ss << "Area = " << this->area() << "\nPerimetro = " << this->perimetro() << std::endl;
        std::cout << ss.str();
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo() {}
    Rectangulo(double base, double altura): base(base), altura(altura) {}

    double area() override {
        return this->base * this->altura;
    }

    double perimetro() override {
        return this->base * 2 + this->altura * 2;
    }
};

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo() {}
    Circulo(double radio): radio(radio) {}

    double area() override {
        return M_PI * this->radio * this->radio;
    }

    double perimetro() override {
        return 2 * M_PI * this->radio;
    }
};


#endif //TDAS_EXTRAOD_26_FIGURA_H