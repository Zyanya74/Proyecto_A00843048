#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>

Arquero::Arquero(string n, int v, int a, int lvl, float p) : Unidad(n, v, a, lvl), precision(p) {}

void Arquero::imprimir() const {
    cout << "Arquero " << nombre << " (Vida: " << vidaActual << "/" << vidaMax << ", Ataque: " << ataque << ", Nivel: " << nivel << ", Precisión: " << precision << ")" << endl;
}

void Arquero::atacar(Unidad* objetivo) {
    float chance = static_cast<float>(rand()) / RAND_MAX;
    if (chance <= precision) {
        int danio = ataque;
        cout << nombre << " acierta y hace " << danio << " de daño!" << endl;
        objetivo->recibirDanio(danio);
    } else {
        cout << nombre << " falla su disparo!" << endl;
    }
}

