#include "Equilatero.hpp"

Equilatero::Equilatero(float lado)
:Triangulo(lado)
{
}


float Equilatero::getArea() const
{
    return ( sqrt(3) * (lados[0]*lados[0]) ) / 4;
}