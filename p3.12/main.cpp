/*
 ••• P3.12
 Write a program that reads in the x- and y-coordinates of four corner points of a quadrilateral and prints out whether it is a square, a rectangle, a trapezoid, a rhombus, or none of those shapes.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "coordinate A: ";
    float x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1;
    cout << "coordinate B: ";
    cin >> x2 >> y2;
    cout << "coordinate C: ";
    cin >> x3 >> y3;
    cout << "coordinate D: ";
    cin >> x4 >> y4;
    
    float sideAB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // distance formula
    float sideBC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float sideCD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    float sideDA = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
    float diagonalAC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    float diagonalBD = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));
    float angleB = acos((pow(sideAB, 2) + pow(sideBC, 2) - pow(diagonalAC, 2)) / (2 * sideAB * sideBC)) * 180/M_PI;
    cout << angleB << endl;

    
    if (sideAB == sideCD && sideDA == sideBC)
    {
        if (angleB == 90 && sideAB == sideDA)
        {
            cout << "square";
        }
        else if (diagonalAC != diagonalBD)
        {
            cout << "rhombus";
        }
        else
        {
            cout << "rectangle";
        }
    }
    else if ((y1 == y2 && y3 == y4 && x1 != x2 && x3 != x4) || (x1 == x2 && x3 == x4 && y1 != y2 && y3 != y4) || (x1 == y2 && y1 == x2 && x3 == y4 && y3 == x4)) // definition of trapezoid
    {
        cout << "trapezoid";
    }
    else
    {
        cout << "coordinates do not match square, rectangle, trapezoid, or rhombus";
    }
    cout << endl;
}
