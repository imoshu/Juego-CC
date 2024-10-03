#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape button;  // Declaraci�n de button
    sf::Text text;  // Declaraci�n de text
public:
    Button(sf::Color, sf::Vector2f = sf::Vector2f(0, 0));
    void setString(const char*);
    void setTextSize(int);
    void setColor(const char, sf::Color);  // Declaraci�n de la funci�n setColor
    void setSize(sf::Vector2f);
    void setPosition(float, float);
    sf::FloatRect getBounds(bool);
    void drawButton(sf::RenderWindow*);
    void setFont(sf::Font&);
    void setAutoSize(float, float);
    void centrar();
};

#endif // BUTTON_H_INCLUDED
