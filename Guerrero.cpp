#include "Guerrero.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Guerrero::Guerrero() : Unidad("Guerrero", 100, 20, 1), fuerza(10) {}

Guerrero::Guerrero(int vida, int ataque, int nivel, int fuerza)
    : Unidad("Guerrero", vida, ataque, nivel), fuerza(fuerza) {}

int Guerrero::getFuerza() const { return fuerza; }
void Guerrero::setFuerza(int f) { fuerza = f; }

void Guerrero::imprimir() {
    Unidad::imprimir();
    cout << "Fuerza: " << fuerza << endl;
}

void Guerrero::recibeAtaque(int ptosAtaque) {
    int dano = ptosAtaque - (fuerza / 5);
    if (dano < 0) dano = 0;
    Unidad::recibeAtaque(dano);
}

void Guerrero::atacar(Unidad& objetivo) {
    std::srand(std::time(nullptr));
    int minAtk = getAtaque() / 2;
    int maxAtk = getAtaque();
    if (objetivo.getNivel() > getNivel()) maxAtk = minAtk;
    int ptosAtk = rand() % (maxAtk - minAtk + 1) + minAtk;
    ptosAtk += fuerza / 10;
    cout << getNombre() << " ataca a " << objetivo.getNombre() << " causando " << ptosAtk << " puntos de daño.\n";
    objetivo.recibeAtaque(ptosAtk);
}

