#ifndef POLIGONO_H
#define POLIGONO_H
#include <iostream>
#include <vector>

using namespace std;

class Poligono 
{
public:    
    Poligono(vector<double>&);    
    virtual ~Poligono();    
    double getLado(unsigned long int lado) const;    
    double getPerimetro() const;    
    unsigned long int getNroLados() const;    
    virtual double getArea() const = 0;    
    virtual void imprime() const;    
    friend ostream& operator<<(ostream& os, const Poligono& p);
    static bool comparaArea(const Poligono* p1, const Poligono* p2);    
    static bool comparaNroLados(const Poligono* p1, const Poligono* p2);
    
private:    
    vector<double>& lados;

};

#endif /* POLIGONO_H */

// Desafios:
// 1. Poligono.cpp (com as implementações dos métodos da classe Poligono)
// 2. Implemente a classe Retangulo (Retangulo.h e Retangulo.cpp)
// Área do Retângulo => (base x altura)/2
// 3. Implemente a classe Triangulo (Triangulo.h e Triangulo.cpp)
