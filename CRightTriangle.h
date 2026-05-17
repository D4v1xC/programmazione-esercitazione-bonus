#ifndef RIGHTTRIANGLE_H      
#define RIGHTTRIANGLE_H

#include "CShape.h"  

class RightTriangle : public Shape   // ereditarietà
{
public:

    RightTriangle();                      // costruttore di default
    RightTriangle(float px, float py, float w, float h);

    ~RightTriangle() override;            // distruttore (override di Shape)

    float GetArea() override;             // calcolo area triangolo
    float GetPerimeter() override;        // calcolo perimetro

    void Dump() override;                 // override: stampa dettagli oggetto
};

#endif
