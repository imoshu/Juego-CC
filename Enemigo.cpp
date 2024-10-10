#include "Enemigo.h"
#include <iostream>

// constructor clase enemigo inicializa la vida, la posición en el mapa y coloca el sprite en la pos inicial
Enemigo::Enemigo(int fila, int columna) {
    vida = 100;  
    posicionMapa.x = columna;  
    posicionMapa.y = fila;  
    sprite.setPosition(posicionMapa.x * 64, posicionMapa.y * 64);  // sprite en el mapa
}

// metodo que mueve al enemigo. simplemente aumenta su posicion en el eje X
void Enemigo::mover() {
    posicionMapa.x += 1;  // Mueve al enemigo una casilla hacia la derecha en el eje X
    sprite.setPosition(posicionMapa.x * 64, posicionMapa.y * 64);  // Actualiza la posicion del sprite
    std::cout << "Enemigo movido a: " << posicionMapa.x << ", " << posicionMapa.y << std::endl;  
}

// metodo que devuelve la vida actual del enemigo
int Enemigo::obtenerVida() {
    return vida;  
}

// metodo que establece la posición del enemigo en el mapa
void Enemigo::establecerPosicionMapa(int fila, int columna) {
    posicionMapa.x = columna;  
    posicionMapa.y = fila;  
}

// metodo obtiene la pos del enemigo
sf::Vector2u Enemigo::obtenerPosicionMapa() {
    return posicionMapa;  
}


void Enemigo::dibujarEnemigo(sf::RenderWindow &ventana) {
    ventana.draw(sprite); 
}