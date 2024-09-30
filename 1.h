
#include <SFML/Graphics.hpp>
using namespace std;

class Enemigo {
    private:
        sf::Texture textura;    
        sf::Sprite sprite;      
        int vida;               
        bool atacando;          
        int direccion;          
        int velocidad;          

    public:
        Enemigo(); 
        void Actualizar(float tiempo); 
        void dibujarEnemigo(sf::RenderWindow *ventana); 
        void establecerPosicion(int x, int y); 
        void mover(); 
        void atacar(); 
        int obtenerVida(); 
};

class EnemigoTipoA : public Enemigo {
    public:
        EnemigoTipoA(int x, int y); 
        void Actualizar(float tiempo); 

};

class EnemigoTipoB : public Enemigo {
    public:
        EnemigoTipoB(int x, int y); 
        void Actualizar(float tiempo); 
};

