#include "Unidad.hpp"
#include <iostream>
using namespace std;

Unidad::Unidad(string n, int hp, int atk, int cargaUlt)
    : nombre(n), saludMax(hp), salud(hp), ataque(atk),
      cargaUltima(0), cargaMaxima(cargaUlt), vivo(true) {}

Unidad::~Unidad() {}

void Unidad::atacar(Unidad& objetivo) {
    cout << nombre << " ataca a " << objetivo.getNombre()
         << " causando " << ataque << " de daño.\n";
    objetivo.recibirDanio(ataque);
    recargarUltima();
}

void Unidad::recargarUltima() {
    if (cargaUltima < cargaMaxima) cargaUltima++;
}

void Unidad::intentarUsarUltima(Unidad& objetivo) {
    if (cargaUltima >= cargaMaxima) {
        usarUltima(objetivo);
        cargaUltima = 0;
    } else {
        atacar(objetivo);
    }
}

void Unidad::recibirDanio(int danio) {
    salud -= danio;
    if (salud <= 0) {
        salud = 0;
        vivo = false;
        cout << nombre << " ha sido derrotado.\n";
    }
}

bool Unidad::estaVivo() const { return vivo; }
string Unidad::getNombre() const { return nombre; }
int Unidad::getSalud() const { return salud; }
int Unidad::getSaludMax() const { return saludMax; }
int Unidad::getCargaUltima() const { return cargaUltima; }
int Unidad::getCargaMaxima() const { return cargaMaxima; }
