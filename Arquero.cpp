#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arquero::Arquero() : Unidad("Arquero", 80, 15, 1), precision(0.8f) {}

Arquero::Arquero(int vida, int ataque, int nivel, float precision)
    : Unidad("Arquero", vida, ataque, nivel), precision(precision) {}

float Arquero::getPrecision() const { return precision; }
void Arquero::setPrecision(float p) { precision = p; }

void Arquero::imprimir() {
    Unidad::imprimir();
    cout << "Precisión: " << precision * 100 << "%" << endl;
}

void Arquero::atacar(Unidad& objetivo) {
    std::srand(std::time(nullptr));
    int minAtk = getAtaque() / 2;
    int maxAtk = getAtaque();
    if (objetivo.getNivel() > getNivel()) maxAtk = minAtk;
    int ptosAtk = rand() % (maxAtk - minAtk + 1) + minAtk;
    float chance = static_cast<float>(rand()) / RAND_MAX;
    if (chance < precision) {
        ptosAtk += getAtaque() * 0.5;
        cout << "Tiro crítico!\n";
    }
    cout << getNombre() << " ataca a " << objetivo.getNombre() << " causando " << ptosAtk << " puntos de daño.\n";
    objetivo.recibeAtaque(ptosAtk);
}

