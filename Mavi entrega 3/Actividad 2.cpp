#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero de Ajedrez");


    sf::Texture whiteTexture;
    sf::Texture blackTexture;

    if (!whiteTexture.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\chessw.png")) {
        return -1;
    }

    if (!blackTexture.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\chessb.png")) {
        return -1;
    }


    sf::Sprite whiteSquare(whiteTexture);
    sf::Sprite blackSquare(blackTexture);


    whiteSquare.setScale(100.0f / whiteTexture.getSize().x, 100.0f / whiteTexture.getSize().y);
    blackSquare.setScale(100.0f / blackTexture.getSize().x, 100.0f / blackTexture.getSize().y);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear();


        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {

                if ((row + col) % 2 == 0) {
                    whiteSquare.setPosition(col * 100, row * 100);
                    window.draw(whiteSquare);
                }
                else {
                    blackSquare.setPosition(col * 100, row * 100);
                    window.draw(blackSquare);
                }
            }
        }


        window.display();
    }

    return 0;
}
