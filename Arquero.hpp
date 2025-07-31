#pragma once
#include "Unidad.hpp"

class Arquero : public Unidad {
    float precision;

public:
    Arquero(string, int, int, int, float);
    void imprimir() const override;
    void atacar(Unidad* objetivo) override;
};

