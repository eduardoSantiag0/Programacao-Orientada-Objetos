#ifndef RETANGULO_H
#define RETANGULO_H

#include "Poligono.h"

class Retangulo : public Poligono
{
public:
    Retangulo(vector<double>& vetor);
    double getArea() const;
};

#endif