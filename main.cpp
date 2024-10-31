#include <SFML/Graphics.hpp>
#include "menu.h"
#include "1.h"

int main() {
    // Crear una ventana SFML
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Menu Example");
    window.setFramerateLimit(60);

    // Estado principal
    short int mainState = 0;

    // Crear una instancia del menú
    Menu* menuPrincipal = new Menu(&window, mainState);

    EnemigoTipoA enemigoA(100, 100); 
    EnemigoTipoB enemigoB(200, 200); 

    // Bucle principal de la ventana
    while (window.isOpen()) {
        sf::Event event;

        // Manejo del estado principal
        switch (mainState) {
        case -1: // Salir del programa
            window.close();
            break;

        case 0: // Mostrar el menú principal
            menuPrincipal->mainMenu();
            break;

        case 1:
            enemigoA.Actualizar(0.1f);
            enemigoB.Actualizar(0.1f);
            break;
        }

        // Manejo de eventos
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana y dibujar el contenido del menú
        window.clear(sf::Color(24, 24, 24)); // Color de fondo

        if (mainState == 1) {
            enemigoA.dibujarEnemigo(&window);
            enemigoB.dibujarEnemigo(&window);
        }
        window.display();
    }


    delete menuPrincipal;

    return 0;
}