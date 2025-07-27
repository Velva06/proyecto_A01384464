#include "Tipos.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero(string n) : Unidad(n, 120, 20, 3) {}
void Guerrero::usarUltima(Unidad& objetivo) {
    cout << nombre << " usa su ULTIMA habilidad: ¡Golpe demoledor!\n";
    objetivo.recibirDanio(40);
}

Arquero::Arquero(string n) : Unidad(n, 80, 25, 2) {}
void Arquero::usarUltima(Unidad& objetivo) {
    cout << nombre << " usa su ULTIMA habilidad: ¡Doble flecha!\n";
    objetivo.recibirDanio(20);
    objetivo.recibirDanio(20);
}

Mago::Mago(string n) : Unidad(n, 100, 18, 3) {}
void Mago::usarUltima(Unidad& objetivo) {
    cout << nombre << " usa su ULTIMA habilidad: ¡Explosión mágica!\n";
    objetivo.recibirDanio(35);
}

Tanque::Tanque(string n) : Unidad(n, 150, 10, 3) {}
void Tanque::usarUltima(Unidad&) {
    cout << nombre << " usa su ULTIMA habilidad: ¡Se cura!\n";
    salud += 30;
    if (salud > saludMax) salud = saludMax;
}

Asesino::Asesino(string n) : Unidad(n, 60, 30, 2) {}
void Asesino::usarUltima(Unidad& objetivo) {
    cout << nombre << " usa su ULTIMA habilidad: ¡Golpe crítico!\n";
    objetivo.recibirDanio(50);
}
