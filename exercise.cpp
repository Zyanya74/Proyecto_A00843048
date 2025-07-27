#include "Unidad.hpp"
#include "Hechicero.hpp"
#include "Arquero.hpp"

int main() {
    Unidad guerrero(130, 25, 3);
    Hechicero mago(100, 20, 2, 50);
    Arquero legolas(110, 18, 3, 5);

    guerrero.imprimir();
    mago.imprimir();
    legolas.imprimir();

    std::cout << "\n>> Guerrero ataca a mago:\n";
    guerrero.atacar(mago);
    mago.imprimir();

    std::cout << "\n>> Mago lanza hechizo a guerrero:\n";
    mago.lanzarHechizo(guerrero);
    guerrero.imprimir();

    std::cout << "\n>> Arquero dispara a guerrero:\n";
    legolas.disparar(guerrero);
    guerrero.imprimir();

    return 0;
}
