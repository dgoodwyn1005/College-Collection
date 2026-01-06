// Course: CSCI 286
//Assignment: Assignment 5
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: September 12, 2024
// Synopsis: This displays four images using SFML

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Texture pic1;
Texture pic2;
Texture pic3;
Texture pic4;

int main()
{
    VideoMode vm(600, 620);

    RenderWindow window(vm, "Pic Collage!", Style::Fullscreen);

    pic1.loadFromFile("pictures/pic1.jfif");
    pic2.loadFromFile("pictures/pic2.jfif");
    pic3.loadFromFile("pictures/pic3.jfif");
    pic4.loadFromFile("pictures/pic4.jfif");

    Sprite spritePic1;
    spritePic1.setTexture(pic1);
    Sprite spritePic2;
    spritePic2.setTexture(pic2);
    Sprite spritePic3;
    spritePic3.setTexture(pic3);
    Sprite spritePic4;
    spritePic4.setTexture(pic4);

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();

        spritePic1.setPosition(0, 0);
        spritePic2.setPosition(300, 300);
        spritePic3.setPosition(600, 600);
        spritePic4.setPosition(950, 900);

        window.draw(spritePic1);
        window.draw(spritePic2);
        window.draw(spritePic3);
        window.draw(spritePic4);

        window.display();
    }


    return 0;
}
