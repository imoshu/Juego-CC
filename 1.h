
#ifndef UNO_H_INCLUDED
#define UNO_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace std;

class Enemigo {
protected:
    sf::Texture textura;
    sf::Sprite sprite;
    int vida;
    bool atacando;
    int direccion;
    int velocidad;

public:
    Enemigo();
    virtual void Actualizar(float tiempo);
    void dibujarEnemigo(sf::RenderWindow* ventana);
    void establecerPosicion(int x, int y);
    virtual void mover();
    virtual void atacar();
    int obtenerVida();
};

class EnemigoTipoA : public Enemigo {
public:
    EnemigoTipoA(int x, int y);
    void mover() override;
    void atacar() override;
    void Actualizar(float tiempo) override;

};

class EnemigoTipoB : public Enemigo {
public:
    EnemigoTipoB(int x, int y);
    void mover() override;
    void atacar() override;
    void Actualizar(float tiempo) override;
};

#pragma once
#endif
