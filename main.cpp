#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;
int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "ANT v0.0");

    int x=0,y=0;

    bool **arr = new bool* [81];
    for(int i=0; i< 81; i++)
    {
        arr[i] = new bool[61];
    }



    sf::RectangleShape _rectangle;
    _rectangle.setSize(sf::Vector2f(10,10));
    _rectangle.setFillColor(Color::Green);
    //_rectangle.setPosition(x+400, y+300);


    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {
                    for(int i=0; i<80; i++)
                    delete[] arr[i];
                    delete[] arr;
                    app.close();
                }
        }

        //app.clear();
        if(arr[x][y] != true)
        arr[x][y] = true;
        else
        arr[x][y] = false;
        if(arr[x][y] == false) _rectangle.setFillColor(Color::Red);
        else _rectangle.setFillColor(Color::Green);
        _rectangle.setPosition(x*10,y*10);
        if(x == 8){ x = 0; y+= 1;}
        if(y == 6) {x=0;y=0;}
        x+= 1;
        app.draw(_rectangle);
        app.display();
        sf::sleep(sf::milliseconds(10));
    }

    return EXIT_SUCCESS;
}
