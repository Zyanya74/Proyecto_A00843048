#include <iostream>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

void mostrarEstadisticasFinales(const Unidad& u) {
    cout << "\n--- Estadísticas finales de " << u.getNombre() << " ---" << endl;
    cout << "Nivel: " << u.getNivel() << endl;
    cout << "Ataque: " << u.getAtaque() << endl;
    cout << "Salud restante: " << u.getSalud() << endl;
}

int main() {
    Guerrero g1(100, 20, 5, 10);
    Arquero a1(80, 15, 4, 0.8f);
    Mago m1(90, 25, 6, 50);

    cout << "COMBATE INICIAL" << endl;
    g1.imprimir();
    a1.imprimir();
    m1.imprimir();

    cout << "\n>>> Ronda 1:" << endl;
    g1.atacar(a1); // Guerrero ataca al Arquero
    a1.atacar(g1); // Arquero ataca al Guerrero

    cout << "\n>>> Ronda 2:" << endl;
    m1.atacar(g1); // Mago ataca al Guerrero
    g1.atacar(m1); // Guerrero ataca al Mago

    cout << "\n>>> Ronda 3:" << endl;
    a1.atacar(m1); // Arquero ataca al Mago
    m1.atacar(a1); // Mago ataca al Arquero

    // Mostrar estado final
    mostrarEstadisticasFinales(g1);
    mostrarEstadisticasFinales(a1);
    mostrarEstadisticasFinales(m1);

    return 0;
}
