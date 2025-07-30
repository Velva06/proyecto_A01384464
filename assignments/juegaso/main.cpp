#include <iostream>
#include <ctime>
#include "Utilidades.hpp"

int main() {
    srand(time(0));
    cout << "*********BIENVENIDO AL JUEGO DE COMBATES 3v3***********\n\n";
    cout << "Gana el primero en derrotar completo al equipo rival!!\n";
    cout << "Deberas escribir el numero del personaje que quieres en tu equipo\n";
    
    auto equipoJugador = elegirEquipoJugador();
    auto equipoEnemigo = generarEquipoEnemigo();

    cout << "\nTu equipo está listo para pelear...\n\n";
    combate(equipoJugador, equipoEnemigo);

    return 0;
}
