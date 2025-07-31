#include "Unidad.hpp"
#include <iostream>

Unidad::Unidad(string n, int v, int a, int lvl) : nombre(n), vidaMax(v), vidaActual(v), ataque(a), nivel(lvl) {}

void Unidad::recibirDanio(int danio) {
    vidaActual -= danio;
    if (vidaActual < 0) vidaActual = 0;
}

bool Unidad::estaVivo() const {
    return vidaActual > 0;
}



