#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>
#include <iomanip>

#include <stdio.h>

class Racional 
{
private:
    int numerador;
    int denominador;
    double valor;
    // int valor;

    static int mdc ( int a, int b );

public:
    Racional (int numerador, int denominador);

    int getDenominador() const;
    int getNumerador() const;
    double getValor() const;

    // int compare(const Racional& outro) const;
    bool operator==(const Racional& r) const;
    bool operator>(const Racional& r) const;
    bool operator>=(const Racional& r) const;
    bool operator<(const Racional& r) const;
    bool operator<=(const Racional& r) const;
    bool operator!=(const Racional& r) const;

    //todo: 
    Racional operator+(const Racional& r) const;
    Racional operator-(const Racional& r) const;
    Racional operator*(const Racional& r) const;
    Racional operator/(const Racional& r) const;


    friend std::ostream &operator<<(std::ostream &os, const Racional& r);


};

#endif