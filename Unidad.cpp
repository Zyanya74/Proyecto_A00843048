#include "Unidad.hpp"
#include <cstdlib>
#include <ctime>

Unidad::Unidad() : vida(100), salud(100), ataque(20), nivel(1) {}

Unidad::Unidad(int vidaMax, int atk, int lvl)
    : vida(vidaMax), salud(vidaMax), ataque(atk), nivel(lvl) {}

int Unidad::getVida() const { return vida; }
int Unidad::getSalud() const { return salud; }
int Unidad::getAtaque() const { return ataque; }
int Unidad::getNivel() const { return nivel; }

void Unidad::setVida(int v) {
    vida = v;
    salud = v;
}

void Unidad::setSalud(int s) {
    salud = (s > vida) ? vida : s;
}

void Unidad::setAtaque(int a) {
    ataque = a;
}

void Unidad::setNivel(int n) {
    nivel = n;
}

int Unidad::porcentajeSalud() const {
    return (salud * 100) / vida;
}

void Unidad::imprimeBarra() const {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    int vacíos = 20 - llenos;
    for (int i = 0; i < llenos; ++i) std::cout << "%";
    for (int i = 0; i < vacíos; ++i) std::cout << "=";
    std::cout << std::endl;
}

void Unidad::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) salud = 0;
}

void Unidad::atacar(Unidad& objetivo) {
    std::srand(std::time(0));
    int daño = 0;

    if (objetivo.getNivel() > nivel) {
        daño = 1 + rand() % (ataque / 2);
    } else {
        daño = (ataque / 2) + rand() % ((ataque - (ataque / 2)) + 1);
    }

    std::cout << "Atacando con " << daño << " puntos de daño." << std::endl;
    objetivo.recibeAtaque(daño);
}

void Unidad::imprimir() const {
    std::cout << "\n===== UNIDAD =====" << std::endl;
    std::cout << "Vida Maxima : " << vida << std::endl;
    std::cout << "Salud Actual: " << salud << std::endl;
    std::cout << "Ataque      : " << ataque << std::endl;
    std::cout << "Nivel       : " << nivel << std::endl;
    std::cout << "Barra de vida: ";
    imprimeBarra();
    std::cout << "===================" << std::endl;
}
