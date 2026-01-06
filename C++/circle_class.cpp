// Classwork 10-22-24 pt.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Circle
{
private:
    double m_radius;
public:
    double getRadius() const;
    void setRadius(double radius);
    double getArea() const;
    double getCircumference() const;
    double getDiameter() const;
};

int main()
{
    Circle c1;
    c1.setRadius(1);
    cout << c1.getRadius() << endl;
    cout << c1.getArea() << endl;
    cout << c1.getCircumference() << endl;
    cout << c1.getDiameter() << endl;

    return 0;
}

double Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}

double Circle::getArea() const
{
    return 3.14159 * m_radius * m_radius;
}

double Circle::getCircumference() const
{
    return 2 * 3.14159 * m_radius;
}

double Circle::getDiameter() const
{
    return 2 * m_radius;
}