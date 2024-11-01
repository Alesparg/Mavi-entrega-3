#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Círculos Centrales y Esquinas");


    sf::Texture textureAzul;
    sf::Texture textureRojo;


    if (!textureAzul.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\cuad_blue.png") ||
        !textureRojo.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\rcircle.png")) {
        return -1;
    }


    sf::CircleShape circleAzul(150);
    circleAzul.setTexture(&textureAzul);
    circleAzul.setTextureRect(sf::IntRect(0, 0, textureAzul.getSize().x, textureAzul.getSize().y));
    circleAzul.setOrigin(150, 150);
    circleAzul.setPosition(400, 400);


    sf::CircleShape circleRojo(100);
    circleRojo.setTexture(&textureRojo);

    sf::CircleShape topLeftRed(circleRojo);
    sf::CircleShape topRightRed(circleRojo);
    sf::CircleShape bottomLeftRed(circleRojo);
    sf::CircleShape bottomRightRed(circleRojo);


    topLeftRed.setPosition(0, 0);
    topRightRed.setPosition(800 - topRightRed.getRadius() * 2, 0);
    bottomLeftRed.setPosition(0, 800 - bottomLeftRed.getRadius() * 2);
    bottomRightRed.setPosition(800 - bottomRightRed.getRadius() * 2, 800 - bottomRightRed.getRadius() * 2);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear(sf::Color::White);


        window.draw(topLeftRed);
        window.draw(topRightRed);
        window.draw(bottomLeftRed);
        window.draw(bottomRightRed);


        window.draw(circleAzul);


        window.display();
    }

    return 0;
