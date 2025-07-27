#include <iostream>
#include <ctime>
#include "Utilidades.hpp"

int main() {
    srand(time(0));
    cout << "BIENVENIDO AL JUEGO DE COMBATES 3v3\n";
    auto equipoJugador = elegirEquipoJugador();
    auto equipoEnemigo = generarEquipoEnemigo();

    cout << "\nTu equipo está listo para pelear...\n";
    combate(equipoJugador, equipoEnemigo);

    return 0;
}
