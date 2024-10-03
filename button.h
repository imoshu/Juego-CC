#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape button;  // Declaración de button
    sf::Text text;  // Declaración de text
public:
    Button(sf::Color, sf::Vector2f = sf::Vector2f(0, 0));
    void setString(const char*);
    void setTextSize(int);
    void setColor(const char, sf::Color);  // Declaración de la función setColor
    void setSize(sf::Vector2f);
    void setPosition(float, float);
    sf::FloatRect getBounds(bool);
    void drawButton(sf::RenderWindow*);
    void setFont(sf::Font&);
    void setAutoSize(float, float);
    void centrar();
};

#endif // BUTTON_H_INCLUDED
