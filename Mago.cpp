#include "Mago.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Mago::Mago() : Unidad("Mago", 90, 25, 1), mana(100) {}

Mago::Mago(int vida, int ataque, int nivel, int mana)
    : Unidad("Mago", vida, ataque, nivel), mana(mana) {}

int Mago::getMana() const { return mana; }
void Mago::setMana(int m) { mana = m; }

void Mago::imprimir() {
    Unidad::imprimir();
    cout << "Maná: " << mana << endl;
}

void Mago::recibeAtaque(int ptosAtaque) {
    int dano = ptosAtaque;
    if (getNivel() >= 4 && mana > 80) dano = ptosAtaque / 3;
    else if (getNivel() >= 3 && mana > 85) dano = ptosAtaque / 2;
    else if ((getNivel() == 1 || getNivel() == 2) && mana == 100) dano = ptosAtaque * 3 / 4;
    Unidad::recibeAtaque(dano);
}

void Mago::atacar(Unidad& objetivo) {
    std::srand(std::time(nullptr));
    int minAtk = getAtaque() / 2;
    int maxAtk = getAtaque();
    if (objetivo.getNivel() > getNivel()) maxAtk = minAtk;
    int ptosAtk = rand() % (maxAtk - minAtk + 1) + minAtk;

    if (mana > 70 && (rand() % 100) < mana / 2) {
        ptosAtk *= 2;
        mana -= 20;
        cout << "Hechizo fuerte lanzado!\n";
    }

    cout << getNombre() << " ataca a " << objetivo.getNombre() << " causando " << ptosAtk << " puntos de daño.\n";
    objetivo.recibeAtaque(ptosAtk);

    if (objetivo.getSalud() == 0) {
        mana += 10;
        cout << getNombre() << " recupera maná por matar al enemigo.\n";
    }
}
