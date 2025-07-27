#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

#include <vector>
#include "Unidad.hpp"

void mostrarEstado(Unidad* u);
Unidad* crearPersonaje(int tipo);
void mostrarOpciones();
std::vector<Unidad*> elegirEquipoJugador();
std::vector<Unidad*> generarEquipoEnemigo();
void combate(std::vector<Unidad*>& jugador, std::vector<Unidad*>& enemigo);

#endif
