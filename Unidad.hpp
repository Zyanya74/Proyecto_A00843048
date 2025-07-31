#pragma once
#include <string>
using namespace std;

class Unidad {
protected:
    string nombre;
    int vidaMax, vidaActual, ataque, nivel;

public:
    Unidad(string nombre, int vida, int ataque, int nivel);
    virtual ~Unidad() {}
    virtual void imprimir() const = 0;
    void recibirDanio(int danio);
    bool estaVivo() const;
    virtual void atacar(Unidad* objetivo) = 0;
};
