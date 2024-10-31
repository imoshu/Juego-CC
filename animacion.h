#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <SFML/Graphics.hpp>



class Animacion {
public:
    Animacion(sf::Texture* textura, int filaInicial, sf::Vector2u numImagenes, float tiempoPorCuadro, bool modoPingPong);
    void Actualizar(float tiempoDelta);
    void establecerTiempoPorCuadro(float tiempo);
    void establecerFila(int fila);
    void establecerModoPingPong(bool modo);
    sf::IntRect rectanguloTextura;

private:
    sf::Vector2u numImagenes;
    sf::Vector2u imagenActual;
    float tiempoTotal;
    float tiempoPorCuadro;
    bool pingPong;
    bool finCiclo;
};

class DialogoGui {
public:
    DialogoGui(char* texto, sf::Font& fuente, sf::Vector2f posicion, sf::Color color, unsigned int tamanioCaracter = 0, float tiempo = 0);
    void Actualizar(float tiempoDelta);
    void Dibujar(sf::RenderWindow* ventana);
    sf::Vector2f obtenerPosicion();
    void habilitar(bool estado);
    bool estaHabilitado();

private:
    bool habilitado;
    sf::Text dialogo;
    float tiempoMostrar;
    float tiempoTotal;
};

class PropAnimacion {
protected:
    sf::Sprite* sprite;
    float tiempoTotal;
    float duracion;
    bool fin;

public:
    PropAnimacion(sf::Sprite* sprite, float duracion);
    virtual void Actualizar(float tiempoDelta);
    bool estaFinalizado();
    void Reiniciar();
};

class AnimacionPosicion : public PropAnimacion {
public:
    AnimacionPosicion(sf::Sprite* sprite, sf::Vector2f posicionInicial, sf::Vector2f posicionFinal, float duracion);
    void Actualizar(float tiempoDelta);

private:
    sf::Vector2f posicionMovimiento;
    float velocidadX, velocidadY;
};

class AnimacionRotacion : public PropAnimacion {
public:
    AnimacionRotacion(sf::Sprite* sprite, float rotacionInicial, float rotacionFinal, float duracion);
    void Actualizar(float tiempoDelta);

private:
    float rotacion, velocidad;
};

class Animaciontamanio : public PropAnimacion {
public:
    Animaciontamanio(sf::Sprite* sprite, sf::Vector2f tamanioInicial, sf::Vector2f tamanioFinal, float duracion);
    void Actualizar(float tiempoDelta);

private:
    sf::Vector2f tamanio, velocidad;
};

class ReproductorAnimacion {
public:
    void agregarAnimacion(PropAnimacion* animacion);
    void Actualizar(float tiempoDelta);

private:
    std::vector<PropAnimacion*> animaciones;
    void Reiniciar();
    int animacionActual = 0;
};

#endif // ANIMACION_H_INCLUIDO
