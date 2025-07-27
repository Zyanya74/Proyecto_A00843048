#pragma once
#include <iostream>

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    Unidad();
    Unidad(int vidaMax, int atk, int lvl);

    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);

    int porcentajeSalud() const;
    void imprimeBarra() const;
    void recibeAtaque(int ptosAtaque);
    virtual void atacar(Unidad& objetivo);
    virtual void imprimir() const;
};
