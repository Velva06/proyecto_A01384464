// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <iostream>
using namespace std;

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // Constructores
    Unidad();
    Unidad(int vidaMax, int ataqueMax, int nivelInicial);

    // Getters
    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setVida(int nuevaVida);
    void setSalud(int nuevaSalud);
    void setAtaque(int nuevoAtaque);
    void setNivel(int nuevoNivel);

    // Métodos funcionales
    int calcularPorcentajeSalud() const;
    void mostrarBarraVida() const;
    void recibeAtaque(int ptosAtaque);
    void atacar(Unidad& objetivo);
    void imprimir() const;
};
// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
