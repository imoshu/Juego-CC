#include <SFML/Graphics.hpp>
#include "menu.h"

int main() {
    // Crear una ventana SFML
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Menu Example");
    window.setFramerateLimit(60);

    // Estado principal
    short int mainState = 0;

    // Crear una instancia del men�
    Menu* menuPrincipal = new Menu(&window, mainState);

    // Bucle principal de la ventana
    while (window.isOpen()) {
        sf::Event event;

        // Manejo del estado principal
        switch (mainState) {
        case -1: // Salir del programa
            window.close();
            break;

        case 0: // Mostrar el men� principal
            menuPrincipal->mainMenu();
            break;

            // Puedes agregar m�s estados aqu� seg�n tus necesidades
        }

        // Manejo de eventos
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana y dibujar el contenido del men�
        window.clear(sf::Color(24, 24, 24)); // Color de fondo
        // Aqu� puedes agregar la l�gica para dibujar los botones si es necesario
        window.display();
    }

    // Liberar memoria
    delete menuPrincipal;

    return 0;
}
