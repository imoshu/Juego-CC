
#include <SFML/Graphics.hpp>
#include <vector>

class Jugador {
private:
    int vida;  
    int municion;  
    int cargador;  
    sf::Vector2u posicionMapa;  // posicion del jugador en el mapa
    std::vector<int> balas;  // Vector de balas

public:
    Jugador();  
    void establecerPosicion(sf::Vector2f posicion);  // posicion del jugador
    sf::Vector2u obtenerPosicionMapa();  // Devuelve la posición del jugador en el mapa
    void actualizarPosicionJugador(float tiempoTranscurrido);  
    std::vector<int>& obtenerBalas();  // Devuelve el vector de balas
};


