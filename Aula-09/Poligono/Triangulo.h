#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Poligono.h"


class Triangulo : public Poligono
{
public:
    Triangulo(vector<double>& vetor);
    double getArea() const;
};

#endif