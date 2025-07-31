#pragma once
#include "Unidad.hpp"

class Guerrero : public Unidad {
    int fuerza;

public:
    Guerrero(string, int, int, int, int);
    void imprimir() const override;
    void atacar(Unidad* objetivo) override;
};
