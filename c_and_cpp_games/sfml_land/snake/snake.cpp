#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 480), "Snake");

    while(window.isOpen()) {

        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed)
                window.close();
            if(e.type == sf::Event::KeyPressed)
                if(e.key.code == sf::Keyboard::Escape)
                    window.close();


        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}

