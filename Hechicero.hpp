#pragma once
#include "Unidad.hpp"

class Hechicero : public Unidad {
private:
    int mana;

public:
    Hechicero();
    Hechicero(int vidaMax, int atk, int lvl, int manaInicial);

    int getMana() const;
    void setMana(int m);

    void lanzarHechizo(Unidad& objetivo);
    void imprimir() const override;
};
