#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fondo de Pantalla");


    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\fondo.jpg")) {
        return -1;
    }


    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);


    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear();


        window.draw(backgroundSprite);


        window.display();
    }

    return 0;
}
