#include "1.h"
#include <iostream>

Enemigo::Enemigo() :vida(100), atacando(false), direccion(1), velocidad(2) {}

void Enemigo::Actualizar(float tiempo) {
	mover();
}
void Enemigo::atacar() {
	atacando = true;
}
void Enemigo::dibujarEnemigo(sf::RenderWindow* ventana) {
	ventana->draw(sprite);
}
void Enemigo::establecerPosicion(int x, int y) {
	sprite.setPosition(x, y);
}
void Enemigo::mover() {
	sprite.move(velocidad, 0);
}
int Enemigo::obtenerVida() {
	return vida;
}
////////////////////////////////////////////////////////////

EnemigoTipoA::EnemigoTipoA(int x, int y) {
    establecerPosicion(x, y);
    vida = 150; 
}
void EnemigoTipoA::mover() {
    sprite.move(velocidad, 0);
}

void EnemigoTipoA::Actualizar(float tiempo) {
    atacar();
    mover();  
}

void EnemigoTipoA::atacar() {
    atacando = true;
}


EnemigoTipoB::EnemigoTipoB(int x, int y) {
    establecerPosicion(x, y);
    velocidad = 3;  
}

void EnemigoTipoB::mover() {
    sprite.move(-velocidad, 0);
}

void EnemigoTipoB::Actualizar(float tiempo) {
    mover();
    atacar();
}

void EnemigoTipoB::atacar() {
    atacando = true;
}