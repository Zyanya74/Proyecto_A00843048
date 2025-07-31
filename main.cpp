#include "Unidad.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

// Función para leer archivo y llenar ejército
template<typename T>
T convertir(const string& s);

void cargarEjercito(const string& archivo, vector<Unidad*>& ejercito) {
    ifstream file(archivo);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + archivo);
    }

    string tipo;
    while (file >> tipo) {
        string nombre;
        int vida, ataque, nivel;
        file >> nombre >> vida >> ataque >> nivel;

        if (tipo == "Guerrero") {
            int fuerza;
            file >> fuerza;
            ejercito.push_back(new Guerrero(nombre, vida, ataque, nivel, fuerza));
        } else if (tipo == "Arquero") {
            float precision;
            file >> precision;
            ejercito.push_back(new Arquero(nombre, vida, ataque, nivel, precision));
        } else if (tipo == "Mago") {
            int mana;
            file >> mana;
            ejercito.push_back(new Mago(nombre, vida, ataque, nivel, mana));
        }
    }

    file.close();
}

void mostrarEjercito(const vector<Unidad*>& ejercito, const string& nombreEjercito) {
    cout << "\n-- " << nombreEjercito << " --" << endl;
    for (Unidad* u : ejercito) {
        u->imprimir();
    }
}

void batalla(vector<Unidad*>& ejercito1, vector<Unidad*>& ejercito2) {
    cout << "\n\n¡Comienza la batalla!" << endl;
    int ronda = 1;
    while (!ejercito1.empty() && !ejercito2.empty()) {
        cout << "\nRonda " << ronda++ << ":" << endl;
        Unidad* u1 = ejercito1.back(); ejercito1.pop_back();
        Unidad* u2 = ejercito2.back(); ejercito2.pop_back();

        cout << "\nCombate entre:" << endl;
        u1->imprimir();
        u2->imprimir();

        while (u1->estaVivo() && u2->estaVivo()) {
            u1->atacar(u2);
            if (u2->estaVivo()) u2->atacar(u1);
        }

        if (u1->estaVivo()) {
            ejercito1.insert(ejercito1.begin(), u1);
            delete u2;
        } else {
            ejercito2.insert(ejercito2.begin(), u2);
            delete u1;
        }
    }

    cout << "\n\nResultado Final:" << endl;
    if (!ejercito1.empty()) {
        cout << "\n¡El ejército 1 ha ganado! Combatientes restantes:" << endl;
        mostrarEjercito(ejercito1, "Ejército 1");
        for (Unidad* u : ejercito2) delete u;
    } else {
        cout << "\n¡El ejército 2 ha ganado! Combatientes restantes:" << endl;
        mostrarEjercito(ejercito2, "Ejército 2");
        for (Unidad* u : ejercito1) delete u;
    }
}

int main() {
    srand(time(0));
    vector<Unidad*> ejercito1;
    vector<Unidad*> ejercito2;

    try {
        cargarEjercito("ejercito1.txt", ejercito1);
        cargarEjercito("ejercito2.txt", ejercito2);
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    mostrarEjercito(ejercito1, "Ejército 1");
    mostrarEjercito(ejercito2, "Ejército 2");

    batalla(ejercito1, ejercito2);

    for (Unidad* u : ejercito1) delete u;
    for (Unidad* u : ejercito2) delete u;

    return 0;
}