#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotar Sprite en SFML");


    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\chessw.png")) {
        return -1;
    }


    sf::Sprite sprite;
    sprite.setTexture(texture);


    sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);


    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        sprite.rotate(1.0f);


        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
