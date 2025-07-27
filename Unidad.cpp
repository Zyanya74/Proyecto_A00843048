#include "Unidad.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Unidad::Unidad() : nombre("Desconocido"), vida(100), salud(100), ataque(20), nivel(1) {}

Unidad::Unidad(string nombre, int vidaMax, int atk, int lvl)
    : nombre(nombre), vida(vidaMax), salud(vidaMax), ataque(atk), nivel(lvl) {}

string Unidad::getNombre() const { return nombre; }
int Unidad::getVida() const { return vida; }
int Unidad::getSalud() const { return salud; }
int Unidad::getAtaque() const { return ataque; }
int Unidad::getNivel() const { return nivel; }

void Unidad::setNombre(const string& nom) { nombre = nom; }
void Unidad::setVida(int v) { vida = v; salud = v; }
void Unidad::setSalud(int s) { salud = (s < 0) ? 0 : (s > vida ? vida : s); }
void Unidad::setAtaque(int a) { ataque = a; }
void Unidad::setNivel(int n) { nivel = n; }

int Unidad::porcentajeSalud() const {
    return (salud * 100) / vida;
}

void Unidad::imprimeBarra() const {
    int llenos = (porcentajeSalud() * 20) / 100;
    int vacios = 20 - llenos;
    for (int i = 0; i < llenos; ++i) std::cout << "%";
    for (int i = 0; i < vacios; ++i) std::cout << "=";
    std::cout << std::endl;
}

void Unidad::imprimir() {
    std::cout << "\n===== " << nombre << " =====" << std::endl;
    std::cout << "Vida Maxima : " << vida << std::endl;
    std::cout << "Salud Actual: " << salud << std::endl;
    std::cout << "Ataque      : " << ataque << std::endl;
    std::cout << "Nivel       : " << nivel << std::endl;
    std::cout << "Barra de vida: ";
    imprimeBarra();
}

void Unidad::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) salud = 0;
}

void Unidad::atacar(Unidad& objetivo) {
    std::srand(std::time(nullptr));
    int dano;
    if (objetivo.getNivel() > nivel) {
        dano = 1 + rand() % (ataque / 2);
    } else {
        dano = (ataque / 2) + rand() % ((ataque - (ataque / 2)) + 1);
    }
    std::cout << nombre << " ataca a " << objetivo.getNombre() << " causando " << dano << " puntos de dano.\n";
    objetivo.recibeAtaque(dano);
}


