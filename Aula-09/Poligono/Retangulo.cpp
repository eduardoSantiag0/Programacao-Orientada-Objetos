#include "Retangulo.h"

Retangulo::Retangulo(vector<double>& vetor) : Poligono(vetor)
{
}

double Retangulo::getArea() const
{
    return getLado(1) * getLado(2); 
}