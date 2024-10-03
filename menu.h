#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

class Menu {
private:
    sf::RenderWindow* window;
    short int& mainState;
    sf::Font* f;
    std::vector<Button> mbt;  // Botones del menú
public:
    Menu(sf::RenderWindow*, short int&);
    sf::Vector2f getMousePos();
    void loadMenu();
    void mainMenu();  // Mostrar el menú principal
};

Menu::Menu(sf::RenderWindow* _window, short int& _state) : mainState(_state), mbt(6, Button(sf::Color(24, 24, 24))) {
    window = _window;
    loadMenu();
}

void Menu::loadMenu() {
    // Cargar fuente
    f = new sf::Font();
    if (!f->loadFromFile("C:/Users/user/Desktop/font/SixtyfourConvergence-Regular.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
    }

    // Configurar los botones del menú
    mbt[0].setString("CONTINUAR");
    mbt[1].setString("NUEVA PARTIDA");
    mbt[2].setString("PUNTAJES");
    mbt[3].setString("SALIR");

    for (int i = 0; i < 4; i++) {
        mbt[i].setFont(*f);
        mbt[i].setTextSize(32);
        mbt[i].setColor('t', sf::Color::White);  // Color de texto
        mbt[i].setAutoSize(1.4f, 1.2f);
        mbt[i].centrar();
        mbt[i].setPosition(100 + mbt[i].getBounds(true).width / 2, 120 + i * 100);  // Colocar botones
    }
}

sf::Vector2f Menu::getMousePos() {
    return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void Menu::mainMenu() {
    float time = 0;
    sf::Clock reloj;
    sf::Clock sReloj;
    sf::Event event;
    sf::Vector2f mPos;

    while (mainState == 0) {
        time = reloj.restart().asSeconds();
        mPos = getMousePos();

        // Manejo de eventos del menú
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mainState = -1;
        }

        // Configurar interactividad de los botones
        if (mbt[0].getBounds(true).contains(mPos)) {
            mbt[0].setColor('t', sf::Color::Red);
            mbt[0].setTextSize(35);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && time > 0.2) {
                // Continuar la partida
            }
        }
        else {
            mbt[0].setTextSize(32);
            mbt[0].setColor('t', sf::Color::White);
        }

        if (mbt[1].getBounds(true).contains(mPos)) {
            mbt[1].setColor('t', sf::Color::Red);
            mbt[1].setTextSize(35);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && time > 0.2) {
                mainState = 1;  // Nueva partida
            }
        }
        else {
            mbt[1].setTextSize(32);
            mbt[1].setColor('t', sf::Color::White);
        }

        if (mbt[3].getBounds(true).contains(mPos)) {
            mbt[3].setColor('t', sf::Color::Red);
            mbt[3].setTextSize(35);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && time > 0.5) {
                mainState = -1;  // Salir
            }
        }
        else {
            mbt[3].setTextSize(32);
            mbt[3].setColor('t', sf::Color::White);
        }

        // Dibujar los botones en la ventana
        window->clear(sf::Color(24, 24, 24));  // Fondo negro
        for (int i = 0; i < 4; i++) {
            mbt[i].drawButton(window);  // Dibujar cada botón
        }
        window->display();
    }
}

#endif // MENU_H_INCLUDED
