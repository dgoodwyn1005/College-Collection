// Course: CSCI 286
//Assignment: Assignment 17
// Programmer: Deshawn Goodwyn
// Instructor: Dr. Mirek Mystkowski
// Date: October 31, 2024
// Synopsis: Working gas pump with sfml

#include <SFML/Graphics.hpp>
#include <sstream>;
#include <iostream>

using namespace sf;
using namespace std;

Text sale;
Text gallons;
std::stringstream ss;

class GasPump
{
private:
    double CPG = 3.27; //Average cost per gallon in the us is 3.27
    double amount_dispensed = 0;
public:
    void display_dispense_amount();
    void display_cpg(); //Cost per gallon
    void display_total(double total);

    void reset_pump();
    double use_pump(double money);

    double get_CPG() const;
    double get_amount_dispensed() const;
    void set_dispense_amount(double a);
};

double GasPump::get_CPG() const
{
    return CPG;
}

double GasPump::get_amount_dispensed() const
{
    return amount_dispensed;
}

void GasPump::display_dispense_amount()
{
    ss << get_amount_dispensed();
    gallons.setString(ss.str());
    ss.str("");
    ss.clear();
}

void GasPump::display_cpg()
{
    cout << "Cost Per Gallon: " << get_CPG() << endl;
}

void GasPump::display_total(double total)
{
    ss << "$" << total;
    sale.setString(ss.str());
    ss.str("");
    ss.clear();
}

void GasPump::set_dispense_amount(double a)
{
    amount_dispensed = a;
}

void GasPump::reset_pump()
{
    set_dispense_amount(0);
    sale.setString("$00.00");
    gallons.setString("00.000");
    ss.str("");
    ss.clear();
}

double GasPump::use_pump(double money)
{
    double cost_per_cent = round(1 / get_CPG());
    set_dispense_amount(get_amount_dispensed() + 0.1);
    money += cost_per_cent;

    display_dispense_amount();
    display_total(money);
    return money;
}

double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

int main()
{
    VideoMode vm(1000, 800);

    RenderWindow window(vm, "Gas Pump!", Style::Default);

    Texture pump;
    pump.loadFromFile("gas_pump.jpg");

    Sprite s_pump;
    s_pump.setTexture(pump);
    s_pump.setScale(0.3, 0.3);
    s_pump.setPosition(0, 0);

    //Choose a font
    Font font;
    font.loadFromFile("data-latin.ttf");

    //Initialize new gas pump
    GasPump p;
    p.display_cpg();
    p.reset_pump();

    //Amount of cash put into the pump
    double cash = 0.00;

    //Create pump interface
    RectangleShape white(Vector2f(185, 100));
    white.setFillColor(Color::White);
    white.setPosition(215, 100);

    sale.setPosition(275, 100);
    sale.setFont(font);
    sale.setCharacterSize(35);

    gallons.setPosition(275, 150);
    gallons.setFont(font);
    gallons.setCharacterSize(35);

    sale.setFillColor(Color::Black);
    gallons.setFillColor(Color::Black);

    Text legend_u;
    Text legend_r;
    Text legend_cost;
    legend_u.setString("U: Use the Pump");
    legend_u.setPosition(650, 150);
    legend_u.setFont(font);
    legend_u.setCharacterSize(40);

    legend_r.setString("R: Reset the Pump");
    legend_r.setPosition(650, 300);
    legend_r.setFont(font);
    legend_r.setCharacterSize(40);

    ss << "Cost Per Gallon\n = " << p.get_CPG();
    legend_cost.setString(ss.str());
    ss.str("");
    ss.clear();

    legend_cost.setPosition(650, 450);
    legend_cost.setFont(font);
    legend_cost.setCharacterSize(40);

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //Use Pump
        if (Keyboard::isKeyPressed(Keyboard::U))
        {
            cash = p.use_pump(cash);
        }

        //Reset Pump
        if (Keyboard::isKeyPressed(Keyboard::R))
        {
            cash = 0;
            p.reset_pump();
        }

        window.clear();

        window.draw(s_pump);
        window.draw(legend_u);
        window.draw(legend_r);
        window.draw(legend_cost);

        window.draw(white);
        window.draw(sale);
        window.draw(gallons);

        window.display();
    }


    return 0;
}
