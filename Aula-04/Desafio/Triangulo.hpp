#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include <cmath>

class Triangulo 
{

protected:
    float lados[3];
    Triangulo(float e);

public:
    Triangulo(float a, float b, float c);

    virtual float getPerimetro() const;
    virtual float getArea() const;
    virtual void imprime() const;
    int compare(Triangulo t) const;

};


#endif