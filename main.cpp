#include "Headers.h"

int main()
{
    Engine myEngine(new RenderWindow(VideoMode(300,300), "SFML works!"));
    myEngine.Update();
    return 0;
}
/*
 RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
*/