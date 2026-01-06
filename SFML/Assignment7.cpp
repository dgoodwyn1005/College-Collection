// Course: CSCI 286
//Assignment: Assignment 7
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: September 20, 2024
// Synopsis: This displays how many times "C" is pressed

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

int main()
{
    VideoMode vm(800, 600);

    RenderWindow window(vm, "Press C!", Style::Default);

    // Initialize the text
    Text pressText;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    pressText.setString("Number of clicks: 0");
    pressText.setCharacterSize(45);
    pressText.setFillColor(Color::White);
    pressText.setFont(font);

    int pressed_count = 0;

    // Position the text
    FloatRect textRect = pressText.getLocalBounds();
    pressText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    pressText.setPosition(800 / 2.0f, 600 / 2.0f);

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            pressed_count++;
            
            std::stringstream ss;
            ss << "Number of clicks: " << pressed_count;
            pressText.setString(ss.str());
        }

        window.clear();

        window.draw(pressText);

        window.display();
    }

    return 0;
}
