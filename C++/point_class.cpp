// Classwork 10-22-24 pt.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;
public:
    void set(double x_coord, double y_coord);
    void move(double dx, double dy);
    void rotate();
    double get_x() const;
    double get_y() const;

};

int main()
{
    cout << "Create point 1:" << endl;
    Point p1;
    double p1_x, p1_y;
    cout << "X coord: ";
    cin >> p1_x;
    cout << "Y coord: ";
    cin >> p1_y;

    cout << "Point 1 (" << p1_x << ", " << p1_y << ")" << endl;
    p1.set(p1_x, p1_y);

    cout << "Create point 2:" << endl;
    Point p2;
    double p2_x, p2_y;
    cout << "X coord: ";
    cin >> p2_x;
    cout << "Y coord: ";
    cin >> p2_y;

    cout << "Point 2 (" << p2_x << ", " << p2_y << ")" << endl;
    p2.set(p2_x, p2_y);

    p1.move(20, 20);
    p2.rotate();

    cout << "Point 1 (" << p1.get_x() << ", " << p1.get_y() << ")" << endl;
    cout << "Point 2 (" << p2.get_x() << ", " << p2.get_y() << ")" << endl;

    return 0;
}

void Point::set(double x_coord, double y_coord)
{
    x = x_coord;
    y = y_coord;
}

void Point::move(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Point::rotate()
{
    double temp = x;
    x = y;
    y = -temp;
}

double Point::get_x() const
{
    return x;
}

double Point::get_y() const
{
    return y;
}