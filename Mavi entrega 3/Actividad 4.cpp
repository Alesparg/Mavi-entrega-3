#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego de plataformas");


    int platformWidth = 50;
    int platformHeight = 50;
    int gap = 30;


    std::vector<sf::RectangleShape> platforms;


    for (int i = 0; i < 7; ++i) {
        sf::RectangleShape platform(sf::Vector2f(platformWidth, platformHeight * (i + 1)));
        platform.setFillColor(sf::Color(150, 75, 0));


        platform.setPosition(100 + i * (platformWidth + gap), 600 - platform.getSize().y);
        platforms.push_back(platform);
    }


    sf::RectangleShape horizontalPlatform(sf::Vector2f(200, 50));
    horizontalPlatform.setFillColor(sf::Color(150, 75, 0));
    horizontalPlatform.setPosition(650, 250);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        window.clear(sf::Color::Cyan);


        for (auto& platform : platforms) {
            window.draw(platform);
        }


        window.draw(horizontalPlatform);


        window.display();
    }

    return 0;
}
