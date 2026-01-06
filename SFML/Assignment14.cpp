// Course: CSCI 286
//Assignment: Assignment 14
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: October 22, 2024
// Synopsis: Hangman!

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//Method initialization
bool check_guess(char letter);

//Edit these for the word to be guessed
char answer[] = "plugs";
const int answer_size = 5;

//Number of lives until lose
int lives = 8;

//Game Event handler
Event e;

int main()
{
    VideoMode vm(1200, 800);

    RenderWindow window(vm, "Hangman!", Style::Default);

    //Initialize all SFML variables
    Text gamelabel;
    Text word;
    Text gameOver;
    //Choose a font
    Font font;
    font.loadFromFile("fonts/Moon Flower.ttf");
    //Set the font to our message
    gamelabel.setFont(font);
    word.setFont(font);
    gameOver.setFont(font);
    //Assign the actual message
    gamelabel.setString("HANGMAN!!!");
    word.setString("_____");
    gameOver.setString("GAMEOVER");
    //Make it really big
    gamelabel.setCharacterSize(75);
    word.setCharacterSize(100);
    gameOver.setCharacterSize(200);
    //Set color
    gamelabel.setFillColor(Color::White);
    word.setFillColor(Color::White);
    gameOver.setFillColor(Color::White);
    //Position the text
    FloatRect textRect = gamelabel.getLocalBounds();
    FloatRect textRect2 = word.getLocalBounds();
    FloatRect textRect3 = gameOver.getLocalBounds();
    gamelabel.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    word.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
    gameOver.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
    gamelabel.setPosition(1200 / 2.0f, textRect.height);
    word.setPosition(1200 / 2.0f, 800 - textRect2.height);
    gameOver.setPosition(1200 / 2.0f, textRect3.height - 20);

    //Sets a char array of the word length into "_"
    char hidden_word[answer_size] = {};
    for (int i = 0; i < answer_size; i++)
    {
        hidden_word[i] = char(95);
    }

    while (window.isOpen())
    {
        //Player Input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (lives > 0)
        {
            while (window.pollEvent(e))
            {
                if (e.type == Event::TextEntered)
                {
                    if (e.text.unicode < 128)
                    {
                        char s = static_cast<char>(e.text.unicode);

                        //Checks if the letter guessed is in the word
                        if (check_guess(s))
                        {
                            string str = "";
                            for (int i = 0; i < answer_size; i++)
                            {
                                if (answer[i] == s)
                                {
                                    hidden_word[i] = s;
                                }

                                str += hidden_word[i];
                            }
                            //Will update the string
                            word.setString(str);
                        }
                        else
                        {
                            //Add to the hanging man
                            lives -= 1;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(word);

        RectangleShape post(Vector2f(10, 500));
        RectangleShape hanging_post(Vector2f(200, 10));

        CircleShape head(50);

        RectangleShape body(Vector2f(10, 200));
        RectangleShape left_arm(Vector2f(100, 10));
        RectangleShape right_arm(Vector2f(100, 10));
        RectangleShape left_leg(Vector2f(100, 10));
        RectangleShape right_leg(Vector2f(100, 10));

        RectangleShape noose(Vector2f(10, 75));

        post.setPosition(800, 200);
        hanging_post.setPosition(600, 200);
        head.setPosition(550, 275);
        body.setPosition(595, 375);
        left_arm.setPosition(495, 400);
        right_arm.setPosition(595, 400);
        left_leg.setPosition(500, 575);
        right_leg.setPosition(600, 575);

        noose.setPosition(595, 200);

        //Switch statement to draw all of the hangman parts
        switch (lives)
        {
        case 8:
            window.draw(gamelabel);
            window.draw(post);
            break;
        case 7:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            break;
        case 6:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            break;
        case 5:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            break;
        case 4:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            break;
        case 3:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            window.draw(right_arm);
            break;
        case 2:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            window.draw(right_arm);
            window.draw(left_leg);
            break;
        case 1:
            window.draw(gamelabel);
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            window.draw(right_arm);
            window.draw(left_leg);
            window.draw(right_leg);
            break;
        case 0:
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            window.draw(right_arm);
            window.draw(left_leg);
            window.draw(right_leg);
            window.draw(noose);
        default:
            window.draw(post);
            window.draw(hanging_post);
            window.draw(head);
            window.draw(body);
            window.draw(left_arm);
            window.draw(right_arm);
            window.draw(left_leg);
            window.draw(right_leg);
            window.draw(noose);

            window.draw(gameOver);
        }

        window.display();
    }

    return 0;
}

//Returns bool for the guessed letter
bool check_guess(char letter)
{
    int index = 0;
    while (index < answer_size)
    {
        if (letter == answer[index])
        {
            return true;
        }

        index += 1;
    }
    return false;
}