#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Imágenes en las esquinas");


    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Equipo\\Desktop\\Unidad3_Assets\\rcircle.png"))
    {
        return -1;
    }


    sf::Sprite topLeft(texture);
    sf::Sprite topRight(texture);
    sf::Sprite bottomLeft(texture);
    sf::Sprite bottomRight(texture);


    sf::Vector2u textureSize = texture.getSize();


    topLeft.setPosition(0, 0);
    topRight.setPosition(800 - textureSize.x, 0);
    bottomLeft.setPosition(0, 600 - textureSize.y);
    bottomRight.setPosition(800 - textureSize.x, 600 - textureSize.y);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::White);


        window.draw(topLeft);
        window.draw(topRight);
        window.draw(bottomLeft);
        window.draw(bottomRight);


        window.display();
    }

    return 0;
}
