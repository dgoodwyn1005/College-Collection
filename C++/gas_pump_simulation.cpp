// Assignment15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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
    void use_pump(double money);

    double get_CPG() const;
    double get_amount_dispensed() const;
    void set_dispense_amount(double a);
};

int main()
{
    //Initialize new gas pump
    GasPump p;
    p.display_cpg();
    
    //Amount of cash put into the pump
    double cash = 30.00;

    cout << "Using Pump..." << endl;
    p.use_pump(cash);
}

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
    cout << "Gallons: " << get_amount_dispensed() << endl;
}

void GasPump::display_cpg()
{
    cout << "Cost Per Gallon: " << get_CPG() << endl;
}

void GasPump::display_total(double total)
{
    cout << "This Sale: " << total << endl;
}

void GasPump::set_dispense_amount(double a)
{
    amount_dispensed = a;
}

void GasPump::reset_pump()
{
    set_dispense_amount(0);
}

void GasPump::use_pump(double max)
{
    reset_pump();
    double money = 0;
    while (money < max)
    {
        double cost_per_cent = round(1 / get_CPG());
        if ((money + cost_per_cent < max))
        {
            set_dispense_amount(get_amount_dispensed() + 0.1);
            money += cost_per_cent;

            cout << "$" << money << endl;
            display_dispense_amount();
            cout << endl;
        }
        else
        {
            break;
        }
    }

    display_total(money);
}

double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}