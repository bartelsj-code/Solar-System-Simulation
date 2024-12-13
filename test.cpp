#include <SFML/Graphics.hpp>
#include <iostream>


//  g++ test.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Changed Title", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::CircleShape shape(50.f);

    int y = 0;

    shape.setFillColor(sf::Color::Green);
        
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved)
            {
                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
                shape.setPosition(event.mouseMove.x, event.mouseMove.y);
            }
        }

        
        // window.setPosition(sf::Vector2i(10, 50));

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(shape);

        window.display();

    }

    return 0;
}