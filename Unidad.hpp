#pragma once
#include <string>
using namespace std;

class Unidad {
private:
    string nombre;
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    Unidad();
    Unidad(string nombre, int vidaMax, int atk, int lvl);

    virtual ~Unidad() {}

    // Getters
    string getNombre() const;
    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setNombre(const string& nom);
    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);

    // Métodos virtuales para polimorfismo
    virtual void imprimir();
    virtual void recibeAtaque(int ptosAtaque);
    virtual void atacar(Unidad& objetivo);

    int porcentajeSalud() const;
    void imprimeBarra() const;
};


