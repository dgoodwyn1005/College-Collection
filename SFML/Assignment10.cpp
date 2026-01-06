// Course: CSCI 286
//Assignment: Assignment 10
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: October 3, 2024
// Synopsis: This displays a randomly placed red square

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
    VideoMode vm(300, 300);

    RenderWindow window(vm, "Mysterious Red Square...", Style::Default);

    //Create red square
    RectangleShape red_square(Vector2f(100, 100));
    red_square.setFillColor(Color::Red);

    //Random seed
    srand((int)time(0));
    int location = rand() % 9 + 1;
    std::cout << location;

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();

        switch (location)
        {
        case 1:
            red_square.setPosition(Vector2f(0, 0));
            break;
        case 2:
            red_square.setPosition(Vector2f(100, 0));
            break;
        case 3:
            red_square.setPosition(Vector2f(200, 0));
            break;
        case 4:
            red_square.setPosition(Vector2f(0, 100));
            break;
        case 5:
            red_square.setPosition(Vector2f(100, 100));
            break;
        case 6:
            red_square.setPosition(Vector2f(200, 100));
            break;
        case 7:
            red_square.setPosition(Vector2f(0, 200));
            break;
        case 8:
            red_square.setPosition(Vector2f(100, 200));
            break;
        case 9:
            red_square.setPosition(Vector2f(200, 200));
            break;
        }

        window.draw(red_square);

        window.display();
    }

    return 0;
}
