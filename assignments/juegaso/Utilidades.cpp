#include "Utilidades.hpp"
#include "Tipos.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

ostream& operator<<(ostream& os, const Unidad& u) {
    os << u.getNombre()
       << " salud: [" << u.getSalud() << "/" << u.getSaludMax()
       << "] - Carga Ult: " << u.getCargaUltima() << "/" << u.getCargaMaxima();
    return os;
}

void mostrarEstado(Unidad* u) {
    cout << *u << endl;
}



Unidad* crearPersonaje(int tipo, bool esEnemigo = false) {
    string base;
    switch (tipo) {
        case 1: base = "Guerrero"; break;
        case 2: base = "Arquero";  break;
        case 3: base = "Mago";     break;
        case 4: base = "Tanque";   break;
        case 5: base = "Asesino";  break;
        default: throw invalid_argument("Entrada invalida. Intenta de nuevo.");
    }
    string nombre = esEnemigo ? ("Otro" + base) : base;

    switch (tipo) {
        case 1: return new Guerrero(nombre);
        case 2: return new Arquero(nombre);
        case 3: return new Mago(nombre);
        case 4: return new Tanque(nombre);
        case 5: return new Asesino(nombre);
        default: throw invalid_argument("Entrada invalida. Intenta de nuevo.");
    }
    
}

void mostrarOpciones() {
    
    vector<Unidad*> mostrar;
    for (int i = 0; i < 5; ++i) {
        int k = i+1;
        mostrar.push_back(crearPersonaje(k, false));
    }

    size_t i = 0;
    
    cout << "Personajes:\n";
        for (size_t k = i; k < mostrar.size(); ++k){
            mostrar[k]->getNombre().erase(0,2);
            mostrar[k]->mostrarInfo(++k);
            k--;
        }
    /*
   
    cout << "1. *Guerrero* - Vida alta, daño medio, Ult: golpe fuerte\n";
    cout << "2. Arquero  - Vida baja, daño alto, Ult: doble flecha\n";
    cout << "3. Mago     - Vida media, daño medio, Ult: explosión mágica\n";
    cout << "4. Tanque   - Vida muy alta, daño bajo, Ult: se cura\n";
    cout << "5. Asesino  - Vida muy baja, daño muy alto, Ult: crítico\n";
    */
}

vector<Unidad*> elegirEquipoJugador() {
    vector<Unidad*> equipo;
    for (int i = 0; i < 5; ++i) {
        int eleccion;
        cout << "\nElige tu personaje #" << (i + 1) << ":\n";
        mostrarOpciones();
        try{
        if (!(cin >> eleccion) || eleccion < 1 || eleccion > 5) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
           throw invalid_argument("Entrada inválida. Intenta de nuevo. ");
        }
        equipo.push_back(crearPersonaje(eleccion, false));
       }catch (const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
        --i;
        this_thread::sleep_for(chrono::seconds(1));
       }
    }
    return equipo;
}

vector<Unidad*> generarEquipoEnemigo() {
    vector<Unidad*> equipo;
    for (int i = 0; i < 5; ++i) {
        int tipo = rand() % 5 + 1;
        equipo.push_back(crearPersonaje(tipo, true));
    }
    return equipo;
}
/*
void mostrarEjercito(const vector<Unidad*>& ejercito, const string& nombre) {
    cout << "\nEjército de " << nombre << ":\n";
    for (auto u : ejercito) {
        mostrarEstado(u);
    }
}
*/
void combate(vector<Unidad*>& jugador, vector<Unidad*>& enemigo) {
    int turno = 1;
    size_t i = 0, j = 0;
    
    cout << "Tu equipo:\n";
        for (size_t k = i; k < jugador.size(); ++k)
            //if (jugador[k]->estaVivo()) mostrarEstado(jugador[k]);
            jugador[k]->mostrarInfo();
    cout << "\nEquipo enemigo:\n";
        for (size_t k = j; k < enemigo.size(); ++k)
           // if (enemigo[k]->estaVivo()) mostrarEstado(enemigo[k]);
            enemigo[k]->mostrarInfo();
   
       
    
    while (i < jugador.size() && j < enemigo.size()) {

        this_thread::sleep_for(chrono::seconds(3));

        cout << "\n--- TURNO #" << turno << " ---\n";
        mostrarEstado(jugador[i]);
        mostrarEstado(enemigo[j]);

        this_thread::sleep_for(chrono::milliseconds(1500));
        
        cout << "\n" << jugador[i]->getNombre() << " ataca primero.\n";
        jugador[i]->intentarUsarUltima(*enemigo[j]);
        if (!enemigo[j]->estaVivo()) j++;

        if (j >= enemigo.size()) break;
        
        this_thread::sleep_for(chrono::milliseconds(500));

        cout << enemigo[j]->getNombre() << " contraataca.\n";
        enemigo[j]->intentarUsarUltima(*jugador[i]);
        if (!jugador[i]->estaVivo()) i++;

        turno++;
    }

    cout << "\n====== RESULTADO FINAL ======\n";

    this_thread::sleep_for(chrono::milliseconds(500));

    if (i >= jugador.size()) {
        cout << "¡Perdiste! El enemigo ganó.\n";
        cout << "Sobrevivientes del enemigo:\n";
        for (size_t k = j; k < enemigo.size(); ++k)
            if (enemigo[k]->estaVivo()) mostrarEstado(enemigo[k]);

    } else {
        cout << "¡Ganaste! Derrotaste al enemigo.\n";
        cout << "Sobrevivientes del jugador:\n";
        for (size_t k = i; k < jugador.size(); ++k)
            if (jugador[k]->estaVivo()) mostrarEstado(jugador[k]);
    }

    cout << "FIN DEL JUEGO" << endl;
    cout << "Gracias por jugar!!";
}
