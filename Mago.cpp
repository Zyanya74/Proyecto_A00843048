#include "Mago.hpp"
#include <iostream>

Mago::Mago(string n, int v, int a, int lvl, int m) : Unidad(n, v, a, lvl), mana(m) {}

void Mago::imprimir() const {
    cout << "Mago " << nombre << " (Vida: " << vidaActual << "/" << vidaMax << ", Ataque: " << ataque << ", Nivel: " << nivel << ", Mana: " << mana << ")" << endl;
}

void Mago::atacar(Unidad* objetivo) {
    int danio = ataque + (mana / 10);
    cout << nombre << " lanza hechizo y hace " << danio << " de daño!" << endl;
    objetivo->recibirDanio(danio);
    mana -= 10;
    if (mana < 0) mana = 0;
}
