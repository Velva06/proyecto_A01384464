#ifndef UNIDAD_HPP
#define UNIDAD_HPP

#include <string>
using namespace std;

class Unidad {
protected:
    string nombre;
    int saludMax, salud, ataque;
    int cargaUltima, cargaMaxima;
    bool vivo;

public:
    Unidad(string n, int hp, int atk, int cargaUlt);
    virtual ~Unidad();

    virtual void usarUltima(Unidad& objetivo) = 0;
    virtual void atacar(Unidad& objetivo);
    void recargarUltima();
    void intentarUsarUltima(Unidad& objetivo);
    virtual void recibirDanio(int danio);

    bool estaVivo() const;
    string getNombre() const;
    int getSalud() const;
    int getSaludMax() const;
    int getCargaUltima() const;
    int getCargaMaxima() const;
};

#endif
