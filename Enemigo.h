
#include <SFML/Graphics.hpp>
#include <vector>

class Enemigo {
private:
    sf::Sprite sprite;  
    sf::Vector2u posicionMapa;  
    int vida;  

public:
    Enemigo(int fila, int columna);  // Constructor que inicializa la posición y vida del enemigo
    void mover();  
    int obtenerVida();  
    void establecerPosicionMapa(int fila, int columna);  
    sf::Vector2u obtenerPosicionMapa();  // Devuelve la posición actual del enemigo en el mapa
    void dibujarEnemigo(sf::RenderWindow *ventana);  
};

