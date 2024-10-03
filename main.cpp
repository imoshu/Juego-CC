#include <SFML/Graphics.hpp>
#include "menu.h"

int main() {
    // Crear una ventana SFML
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Menu Example");
    window.setFramerateLimit(60);

    // Estado principal
    short int mainState = 0;

    // Crear una instancia del menú
    Menu* menuPrincipal = new Menu(&window, mainState);

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

            // Puedes agregar más estados aquí según tus necesidades
        }

        // Manejo de eventos
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana y dibujar el contenido del menú
        window.clear(sf::Color(24, 24, 24)); // Color de fondo
        // Aquí puedes agregar la lógica para dibujar los botones si es necesario
        window.display();
    }

    // Liberar memoria
    delete menuPrincipal;

    return 0;
}
