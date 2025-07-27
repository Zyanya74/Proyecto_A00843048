#pragma once
#include "Unidad.hpp"

class Mago : public Unidad {
private:
    int mana;

public:
    Mago();
    Mago(int vida, int ataque, int nivel, int mana);

    int getMana() const;
    void setMana(int m);

    void imprimir() override;
    void recibeAtaque(int ptosAtaque) override;
    void atacar(Unidad& objetivo) override;
};
