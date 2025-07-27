#include "Hechicero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Hechicero::Hechicero() : Unidad(), mana(50) {}

Hechicero::Hechicero(int vidaMax, int atk, int lvl, int manaInicial)
    : Unidad(vidaMax, atk, lvl), mana(manaInicial) {}

int Hechicero::getMana() const { return mana; }

void Hechicero::setMana(int m) { mana = m; }

void Hechicero::lanzarHechizo(Unidad& objetivo) {
    if (mana < 10) {
        std::cout << "¡No hay suficiente maná para lanzar el hechizo!" << std::endl;
        return;
    }

    std::srand(std::time(0));
    int daño = getAtaque() + (rand() % 15 + 5); // daño extra de 5 a 19
    std::cout << "🔥 Hechizo lanzado con " << daño << " puntos de daño mágico." << std::endl;

    objetivo.recibeAtaque(daño);
    mana -= 10;
}

void Hechicero::imprimir() const {
    Unidad::imprimir();
    std::cout << "Maná         : " << mana << std::endl;
}
