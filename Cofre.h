
#include <SFML/Graphics.hpp>

class Cofre {
private:
    int tipo;  // Tipo de cofre 4 peor 7 mejor
    int recompensa;  
    sf::Vector2u posicion;  // Posición del cofre en el mapa
    void establecerCofre(int tipo = 0);  //meotodo establece 

public:
    Cofre(int fila, int columna);  // Constructor que inicializa el cofre
    int obtenerRecompensa();  // Devuelve la recompensa del cofre
    void desactivar();  
};


