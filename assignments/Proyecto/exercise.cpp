#include <iostream>
#include "Personaje.hpp"
using namespace std;

int main() {
    // Crear dos unidades
    Unidad guerrero(120, 25, 3);
    Unidad mago(90, 30, 4);

    std::cout << "Estado inicial del guerrero:" << std::endl;
    guerrero.imprimir();

    std::cout << "Estado inicial del mago:" << std::endl;
    mago.imprimir();

    // Mago ataca al guerrero
    std::cout << "\nMago ataca al guerrero..." << std::endl;
    mago.atacar(guerrero);

    // Estado después del ataque
    std::cout << "\nEstado del guerrero después de ser atacado:" << std::endl;
    guerrero.imprimir();

    // Guerrero contraataca
    std::cout << "\nGuerrero contraataca..." << std::endl;
    guerrero.atacar(mago);

    std::cout << "\nEstado del mago después del contraataque:" << std::endl;
    mago.imprimir();

    return 0;
}
