#include "CRightTriangle.h"

#include <iostream>
#include <cmath>

using namespace std;

RightTriangle::RightTriangle() : Shape()   // chiamo costruttore base shape
{
    cout << "RightTriangle - default constructor" << endl;
}

RightTriangle::RightTriangle(float px, float py, float w, float h)
    : Shape(px, py, w, h)                  // inizializza shape
{
    cout << "RightTriangle - constructor" << endl;
}

RightTriangle::~RightTriangle()
{
    cout << "RightTriangle - destructor" << endl;
}

float RightTriangle::GetArea()
{
    return (width * height) / 2.0;      // area triangolo
}

float RightTriangle::GetPerimeter()
{
    return width + height + sqrt(width * width + height * height); // somma cateti + ipotenusa
}

void RightTriangle::Dump()
{
    cout << endl;
    cout << "RightTriangle Dump:" << endl;

    Shape::Dump();                         // stampa la parte ereditata

    cout << "Area: " << GetArea() << endl;        // stampa area calcolata
    cout << "Perimeter: " << GetPerimeter() << endl; // stampa perimetro
}