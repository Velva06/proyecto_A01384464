#ifndef TIPOS_HPP
#define TIPOS_HPP

#include "Unidad.hpp"

class Guerrero : public Unidad {
public:
    Guerrero(string n);
    void usarUltima(Unidad& objetivo) override;
};

class Arquero : public Unidad {
public:
    Arquero(string n);
    void usarUltima(Unidad& objetivo) override;
};

class Mago : public Unidad {
public:
    Mago(string n);
    void usarUltima(Unidad& objetivo) override;
};

class Tanque : public Unidad {
public:
    Tanque(string n);
    void usarUltima(Unidad& objetivo) override;
};

class Asesino : public Unidad {
public:
    Asesino(string n);
    void usarUltima(Unidad& objetivo) override;
};

#endif
