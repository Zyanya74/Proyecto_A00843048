#pragma once
#include "Unidad.hpp"

class Arquero : public Unidad {
private:
    float precision;

public:
    Arquero();
    Arquero(int vida, int ataque, int nivel, float precision);

    float getPrecision() const;
    void setPrecision(float p);

    void imprimir() override;
    void atacar(Unidad& objetivo) override;
};
