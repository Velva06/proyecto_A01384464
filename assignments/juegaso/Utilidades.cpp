#include "Utilidades.hpp"
#include "Tipos.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void mostrarEstado(Unidad* u) {
    cout << u->getNombre() << " [" << u->getSalud() << "/" << u->getSaludMax()
         << "] Carga Ult: " << u->getCargaUltima() << "/" << u->getCargaMaxima() << endl;
}

Unidad* crearPersonaje(int tipo) {
    switch (tipo) {
        case 1: return new Guerrero("Guerrero");
        case 2: return new Arquero("Arquero");
        case 3: return new Mago("Mago");
        case 4: return new Tanque("Tanque");
        case 5: return new Asesino("Asesino");
        default: return nullptr;
    }
}

void mostrarOpciones() {
    cout << "1. Guerrero - Vida alta, daño medio, Ult: golpe fuerte\n";
    cout << "2. Arquero  - Vida baja, daño alto, Ult: doble flecha\n";
    cout << "3. Mago     - Vida media, daño medio, Ult: explosión mágica\n";
    cout << "4. Tanque   - Vida muy alta, daño bajo, Ult: se cura\n";
    cout << "5. Asesino  - Vida muy baja, daño muy alto, Ult: crítico\n";
}

vector<Unidad*> elegirEquipoJugador() {
    vector<Unidad*> equipo;
    for (int i = 0; i < 3; ++i) {
        int eleccion;
        cout << "\nElige tu personaje #" << (i + 1) << ":\n";
        mostrarOpciones();
        while (!(cin >> eleccion) || eleccion < 1 || eleccion > 5) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intenta de nuevo: ";
        }
        equipo.push_back(crearPersonaje(eleccion));
    }
    return equipo;
}

vector<Unidad*> generarEquipoEnemigo() {
    vector<Unidad*> equipo;
    for (int i = 0; i < 3; ++i) {
        int tipo = rand() % 5 + 1;
        equipo.push_back(crearPersonaje(tipo));
    }
    return equipo;
}

void combate(vector<Unidad*>& jugador, vector<Unidad*>& enemigo) {
    int turno = 1;
    size_t i = 0, j = 0;

    while (i < jugador.size() && j < enemigo.size()) {
        cout << "\n--- TURNO #" << turno << " ---\n";
        mostrarEstado(jugador[i]);
        mostrarEstado(enemigo[j]);

        cout << "\n" << jugador[i]->getNombre() << " ataca primero.\n";
        jugador[i]->intentarUsarUltima(*enemigo[j]);
        if (!enemigo[j]->estaVivo()) j++;

        if (j >= enemigo.size()) break;

        cout << enemigo[j]->getNombre() << " contraataca.\n";
        enemigo[j]->intentarUsarUltima(*jugador[i]);
        if (!jugador[i]->estaVivo()) i++;

        turno++;
    }

    cout << "\n====== RESULTADO FINAL ======\n";
    if (i >= jugador.size())
        cout << "¡Perdiste! El enemigo ganó.\n";
    else
        cout << "¡Ganaste! Derrotaste al enemigo.\n";
}
