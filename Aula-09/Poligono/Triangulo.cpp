#include "Triangulo.h"
#include <math.h>

Triangulo::Triangulo(vector<double>& vetor) : Poligono(vetor)
{
}

double Triangulo::getArea() const
{
    double p = this->getPerimetro() / 2;

    return sqrt(p * (p - getLado(0)) * (p - getLado(1)) * (p - getLado(2)));
}
