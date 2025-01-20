#include <iostream>
#include <math.h>

class Triangulo 
{
private:
    double a, b, c;

public:
    Triangulo(double a, double b, double c) : a(a), b(b), c(c) {};
    double getPerimetro() const { return a+b+c; }

    virtual double getArea() const {
        double p = getPerimetro() / 2;
        
        return sqrt(p * ( p - a ) * (p - b) * (p - c)); 
    }

    bool operator>(const Triangulo& t2) const {
        return this->getArea() > t2.getArea();
    };

    bool operator==(const Triangulo& t2) const {
        return this->getArea() == t2.getArea();
    }

    bool operator!= (const Triangulo& t2) const {
        return this->getArea() != t2.getArea();    
    } 

    Triangulo operator+ (const int inc) const {
        return Triangulo (this->a + inc, this->b + inc, this->c + inc);
    }

    friend std::ostream& operator ^ (std::ostream& os, const Triangulo& triangulo);

    friend std::istream& operator | (std::istream& is, Triangulo& triangulo);
};

std::ostream& operator ^ (std::ostream& os, const Triangulo& triangulo) {
    os << "A: " << triangulo.a << " B: " << triangulo.b << " C: " << triangulo.c << std::endl;
    return os;
}

std::istream& operator | (std::istream& is, Triangulo& triangulo) {
    std::cout << "Mude A: ";
    is >> triangulo.a;
    std::cout << "Mude B: ";
    is >> triangulo.b;
    std::cout << "Mude C: ";
    is >> triangulo.c;
    return is;
}


int main (void) 
{
    Triangulo t1 (3, 4, 5);
    std::cout ^ t1;

    Triangulo t2 (3, 3, 3);
    std::cout ^ t2;

    if (t1>t2) std::cout << "T1 é maior" << std::endl;
    else std::cout << "T2 é maior" << std::endl;

    std::cout << "Area de T1: " << t1.getArea() << std::endl;
    std::cout << "Area de T2: " << t2.getArea() << std::endl;

    std::cin | t1;
    std::cout ^ t1;

    Triangulo t3 = t1 + 10;
    std::cout ^ t3;
    

}