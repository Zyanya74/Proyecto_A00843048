#pragma once
#include "Unidad.hpp"

class Mago : public Unidad {
    int mana;

public:
    Mago(string, int, int, int, int);
    void imprimir() const override;
    void atacar(Unidad* objetivo) override;
};

