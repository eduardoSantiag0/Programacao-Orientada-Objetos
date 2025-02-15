#include "Racional.h"

int Racional::mdc(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Racional::Racional(int numerador, int denominador)
{
    int menorDivisor = mdc(numerador, denominador);    
    this->numerador = numerador / menorDivisor;
    this->denominador = denominador / menorDivisor;

    if (this->denominador < 0) {
        this->numerador = -this->numerador;
    }

    this->valor = static_cast<double>(this->numerador) / this->denominador;

}

int Racional::getNumerador() const
{ 
    return this->numerador; 
}

int Racional::getDenominador() const
{ 
    return this->denominador; 
}

double Racional::getValor() const
{ 
    return this->valor; 
}



std::ostream &operator<<(std::ostream &os, Racional const  &r) 
{
    if (r.numerador % r.denominador == 0) {
        os << r.valor;

    } else {
        os << r.numerador << "/" << r.denominador;
    }

    return os;
}

bool Racional::operator==(const Racional &outro) const
{
    return this->numerador * outro.denominador == this->denominador * outro.numerador;

}

bool Racional::operator>=(const Racional &outro) const
{
    return (this->valor > outro.valor || this->valor == outro.valor);
}

bool Racional::operator>(const Racional &outro) const
{
    return !(this->valor <= outro.valor);
}

bool Racional::operator<=(const Racional &outro) const
{
    return (this->valor < outro.valor || this->valor == outro.valor);
}

bool Racional::operator<(const Racional &outro) const
{
    return this->numerador * outro.denominador < this->denominador * outro.numerador;
}

bool Racional::operator!=(const Racional &outro) const
{
    return !(this->valor == outro.valor);
}


Racional Racional::operator+(const Racional& r) const
{
    int novoNumerador = this->numerador * r.denominador + this->denominador * r.numerador;
    int novoDenominador = this->denominador * r.denominador;
    return Racional(novoNumerador, novoDenominador);
}

Racional Racional::operator-(const Racional& r) const {
    int novoNumerador = this->numerador * r.denominador - this->denominador * r.numerador;
    int novoDenominador = this->denominador * r.denominador;
    return Racional(novoNumerador, novoDenominador);
}


Racional Racional::operator*(const Racional& r) const
{
    int novoNumerador = this->numerador * r.numerador;
    int novoDenominador = this->denominador * r.denominador;
    return Racional(novoNumerador, novoDenominador);
}

Racional Racional::operator/(const Racional& r) const
{
    int novoNumerador = this->numerador * r.denominador;
    int novoDenominador = this->denominador * r.numerador;
    return Racional(novoNumerador, novoDenominador);
}