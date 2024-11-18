#ifndef EQUILATERO_H
#define EQUILATERO_H

#include "Triangulo.hpp"

class Equilatero: public Triangulo
{
public:
    Equilatero(float lado);
    float getArea() const;
};

#endif 