#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

void rect_move (int n,int &x, int &y, sf::RectangleShape rect, RenderWindow &app)
{
    switch (n)
    {
        case 1://up
        y -= 1;
        rect.setPosition(x,y);
        break;

        case 2://left
        x -= 1;
        rect.setPosition(x,y);
        break;

        case 3://down
        y += 1;
        rect.setPosition(x,y);
        break;

        case 4://right
        x += 1;
        rect.setPosition(x,y);
        break;
    }
    app.draw(rect);
}


int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "ANT v0.0");

    int x=400,y=300, n=1;

    bool **arr = new bool* [801];
    for(int i=0; i< 801; i++)
    {
        arr[i] = new bool[601];
    }



    sf::RectangleShape _rectangle;
    _rectangle.setSize(sf::Vector2f(1,1));
    _rectangle.setFillColor(Color::Green);


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

        if(arr[x][y] != true) {arr[x][y] = true; n++; if(n == 5) n=1;} // Если квадратик пустой или красный, то 1
        else                  {arr[x][y] = false; n--; if(n == 0) n=4; }// Если квадратик 1, то 0

        if(arr[x][y] == false) _rectangle.setFillColor(Color::Red); //Если 0, то красный
        else                   _rectangle.setFillColor(Color::Green);// Если 1, то зелёный

        //_rectangle.setPosition(x*10,y*10);
        rect_move(n,x, y,_rectangle, app);

        //app.draw(_rectangle);
        app.display();
        sf::sleep(sf::milliseconds(1));
        cout << "\n\n\n\nX : "<< x <<"\n\nY: " << y << "\n\n\n\nX+400 : "<< x <<"\n\nY+400: " << y;
    }

    return EXIT_SUCCESS;
}
