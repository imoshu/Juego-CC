#include "Jugador.h"
#include <iostream>


Jugador::Jugador() {
    vida = 100;
    municion = 13;
    cargador = 13;
    posicionMapa = sf::Vector2u(0, 0);
    balas.resize(10, 1);  // Inicializa el vector de balas con 10 elementos de valor 1
}

// posicion del jugador en el mapa
void Jugador::establecerPosicion(sf::Vector2f posicion) {
    posicionMapa = sf::Vector2u(static_cast<unsigned int>(posicion.x), static_cast<unsigned int>(posicion.y));
}

// devuelve la pos
sf::Vector2u Jugador::obtenerPosicionMapa() {
    return posicionMapa;
}

// Actualiza la posicion del jugador en funcion del tiempo transcurrido
void Jugador::actualizarPosicionJugador(float tiempoTranscurrido) {
    posicionMapa.x += static_cast<unsigned int>(tiempoTranscurrido * 10);  // Simula un movimiento simple en el eje X
    std::cout << "Posición del jugador actualizada: " << posicionMapa.x << ", " << posicionMapa.y << std::endl;
}

// Devuelve el vector de balas
std::vector<int>& Jugador::obtenerBalas() {
    return balas;
}
