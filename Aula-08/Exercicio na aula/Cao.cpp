#include "Cao.h"

Cao::Cao(string nome, double peso, string raca) 
    : Animal(nome, peso), raca(raca)
{
}

Cao::~Cao()
{
    // cout << "Destruindo Cao "<< endl;
}

string Cao::getEspecie() const
{
    
    return "Cão";
}

void Cao::imprime()
{
    Animal::imprime();
    cout << "Raça: " << this->raca<< endl;
}