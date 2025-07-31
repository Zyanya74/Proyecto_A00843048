#include "Guerrero.hpp"
#include <iostream>

Guerrero::Guerrero(string n, int v, int a, int lvl, int f) : Unidad(n, v, a, lvl), fuerza(f) {}

void Guerrero::imprimir() const {
    cout << "Guerrero " << nombre << " (Vida: " << vidaActual << "/" << vidaMax << ", Ataque: " << ataque << ", Nivel: " << nivel << ", Fuerza: " << fuerza << ")" << endl;
}

void Guerrero::atacar(Unidad* objetivo) {
    int danio = ataque + fuerza;
    cout << nombre << " ataca con fuerza " << danio << "!" << endl;
    objetivo->recibirDanio(danio);
}


