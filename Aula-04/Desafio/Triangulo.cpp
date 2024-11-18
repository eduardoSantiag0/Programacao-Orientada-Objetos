#include "Triangulo.hpp"
#include <cmath>

Triangulo::Triangulo(float ladoA, float ladoB, float ladoC)
{
    lados[0] = ladoA;
    lados[1] = ladoB;
    lados[2] = ladoC;
}


Triangulo::Triangulo(float e) 
{
    lados[0] = e;
    lados[1] = e;
    lados[2] = e;
}

float Triangulo::getPerimetro() const
{
    float soma = 0;
    for (float i : lados)
        soma += i;
    return soma; 
}

float Triangulo::getArea() const
{
    float s = getPerimetro() / 2;
    float produto = s;

    for (float i :  lados)
        produto*=(s-i);
    
    return sqrt(produto);
}

void Triangulo::imprime() const 
{
    for(float i : lados) 
        std::cout << "Lado: " << i << std::endl;

    std::cout << "Perimetro: " << getPerimetro() << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}

int Triangulo::compare(Triangulo t) const
{
    if (this->getArea() > t.getArea()) 
        return 1;
    else if (t.getArea() > this->getArea()) 
        return -1 ; 
    else 
        return 0;
}