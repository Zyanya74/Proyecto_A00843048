#pragma once
#include "Unidad.hpp"

class Arquero : public Unidad {
private:
    int flechas;

public:
    Arquero();
    Arquero(int vidaMax, int atk, int lvl, int flechasInicial);

    int getFlechas() const;
    void setFlechas(int f);

    void disparar(Unidad& objetivo);
    void imprimir() const override;
};
