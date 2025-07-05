//GEnera la implementación de la clase base Personaje
//GEnera la implementación de la clase base Personaje
#include "Personaje.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Constructor default
Unidad::Unidad() {
    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;
}

// Constructor con parámetros
Unidad::Unidad(int vidaMax, int ataqueMax, int nivelInicial) {
    vida = vidaMax;
    salud = vidaMax;
    ataque = ataqueMax;
    nivel = nivelInicial;
}

// Getters
int Unidad::getVida() const { return vida; }
int Unidad::getSalud() const { return salud; }
int Unidad::getAtaque() const { return ataque; }
int Unidad::getNivel() const { return nivel; }

// Setters
void Unidad::setVida(int nuevaVida) {
    vida = nuevaVida;
    if (salud > vida) salud = vida;
}

void Unidad::setSalud(int nuevaSalud) {
    salud = (nuevaSalud > vida) ? vida : nuevaSalud;
}

void Unidad::setAtaque(int nuevoAtaque) {
    ataque = nuevoAtaque;
}

void Unidad::setNivel(int nuevoNivel) {
    nivel = nuevoNivel;
}

// Porcentaje de salud
int Unidad::calcularPorcentajeSalud() const {
    return static_cast<int>(round((static_cast<float>(salud) / vida) * 100));
}

// Barra de vida
void Unidad::mostrarBarraVida() const {
    int porcentaje = calcularPorcentajeSalud();
    int vivos = porcentaje / 5;  // 20 caracteres
    int perdidos = 20 - vivos;

    for (int i = 0; i < vivos; ++i) std::cout << '%';
    for (int i = 0; i < perdidos; ++i) std::cout << '.';
    std::cout << " (" << porcentaje << "%)" << std::endl;
}

// Recibir ataque
void Unidad::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) salud = 0;
}

// Atacar a otra unidad
void Unidad::atacar(Unidad& objetivo) {
    srand(time(nullptr));

    int minAtaque, maxAtaque;
    if (objetivo.getNivel() > this->nivel) {
        minAtaque = 1;
        maxAtaque = ataque / 2;
    } else {
        minAtaque = ataque / 2;
        maxAtaque = ataque;
    }

    if (maxAtaque < minAtaque) maxAtaque = minAtaque;

    int ptosAtaque = rand() % (maxAtaque - minAtaque + 1) + minAtaque;
    std::cout << "Atacando con " << ptosAtaque << " puntos." << std::endl;
    objetivo.recibeAtaque(ptosAtaque);
}

// Imprimir características
void Unidad::imprimir() const {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Vida Máxima: " << vida << std::endl;
    std::cout << "Salud Actual: " << salud << std::endl;
    std::cout << "Ataque Máximo: " << ataque << std::endl;
    std::cout << "Barra de Vida: ";
    mostrarBarraVida();
    std::cout << "--------------------------" << std::endl;
}
