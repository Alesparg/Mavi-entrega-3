#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "Cuadro Dividido en Cuatro");


    window.clear(sf::Color(0, 255, 0));


    sf::Texture textureRojo;
    sf::Texture textureAmarillo;
    sf::Texture textureAzul;
    sf::Texture textureNegro;


    if (!textureRojo.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\cuad_red.png") ||
        !textureAmarillo.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\cuad_yellow.png") ||
        !textureAzul.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\cuad_blue.png") ||
        !textureNegro.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\chessb.png")) {
        return -1;
    }


    sf::Sprite spriteRojo(textureRojo);
    sf::Sprite spriteAmarillo(textureAmarillo);
    sf::Sprite spriteAzul(textureAzul);
    sf::Sprite spriteNegro(textureNegro);


    spriteRojo.setScale(300.0f / textureRojo.getSize().x, 300.0f / textureRojo.getSize().y);
    spriteAmarillo.setScale(300.0f / textureAmarillo.getSize().x, 300.0f / textureAmarillo.getSize().y);
    spriteAzul.setScale(300.0f / textureAzul.getSize().x, 300.0f / textureAzul.getSize().y);
    spriteNegro.setScale(300.0f / textureNegro.getSize().x, 300.0f / textureNegro.getSize().y);


    spriteRojo.setPosition(100, 100);
    spriteAmarillo.setPosition(400, 100);
    spriteAzul.setPosition(100, 400);
    spriteNegro.setPosition(400, 400);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear(sf::Color(0, 255, 0));


        window.draw(spriteRojo);
        window.draw(spriteAmarillo);
        window.draw(spriteAzul);
        window.draw(spriteNegro);


        window.display();
    }

    return 0;
}
