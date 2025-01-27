#include "Poligono.h"

//! NÃO SEI
Poligono::Poligono (vector<double>& l) : lados(l)
{
}

//! NÃO SEI
Poligono::~Poligono() 
{
    lados.clear();
}

double Poligono::getLado(unsigned long int lado) const
{
    return lados[lado-1];

}


unsigned long int Poligono::getNroLados() const
{
    return lados.size(); 
}

double Poligono::getPerimetro() const 
{
    double soma = 0;
    for (double& l : lados) {
        soma += l;
    }

    return soma;
}

void Poligono::imprime() const
{
    for (const double& l : lados) 
        cout << l << " ";
    
    cout << endl;
    
}

bool Poligono::comparaArea(const Poligono* p1, const Poligono* p2)
{
    return p1->getArea() > p2->getArea();
}

bool Poligono::comparaNroLados(const Poligono* p1, const Poligono* p2)
{
    return p1->getNroLados() > p2->getNroLados();
}

//! REVISAR
ostream& operator<<(ostream& os, const Poligono& p) 
{
    p.imprime();

    os << "Numero de lados: " << p.getNroLados() << endl;
    os << "Area: " << p.getArea() << endl;
    os << "Perimetro: " << p.getPerimetro() << endl;
    return os;
}
