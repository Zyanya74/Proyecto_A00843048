#pragma once
#include "Unidad.hpp"

class Guerrero : public Unidad {
private:
    int fuerza;

public:
    Guerrero();
    Guerrero(int vida, int ataque, int nivel, int fuerza);

    int getFuerza() const;
    void setFuerza(int f);

    void imprimir() override;
    void recibeAtaque(int ptosAtaque) override;
    void atacar(Unidad& objetivo) override;
};
