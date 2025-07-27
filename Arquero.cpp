#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Arquero::Arquero() : Unidad(), flechas(10) {}

Arquero::Arquero(int vidaMax, int atk, int lvl, int flechasInicial)
    : Unidad(vidaMax, atk, lvl), flechas(flechasInicial) {}

int Arquero::getFlechas() const { return flechas; }

void Arquero::setFlechas(int f) { flechas = f; }

void Arquero::disparar(Unidad& objetivo) {
    if (flechas <= 0) {
        std::cout << "🏹 No hay flechas para disparar." << std::endl;
        return;
    }

    std::srand(std::time(0));
    int daño = (getAtaque() / 2) + rand() % (getAtaque() / 2 + 1);
    std::cout << "🏹 Flecha lanzada con " << daño << " puntos de daño." << std::endl;

    objetivo.recibeAtaque(daño);
    flechas--;
}

void Arquero::imprimir() const {
    Unidad::imprimir();
    std::cout << "Flechas      : " << flechas << std::endl;
}
