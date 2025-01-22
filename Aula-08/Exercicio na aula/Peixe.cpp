#include "Peixe.h"

Peixe::Peixe(string nome, double peso, string habitat) 
    : Animal(nome, peso), habitat(habitat)
{
}

Peixe::~Peixe()
{
    // cout << "Destruindo Peixe"<< endl;

}

string Peixe::getEspecie() const
{
    
    return "Peixe";
}

void Peixe::imprime()
{
    Animal::imprime();
    cout << "Habitat: " << this->habitat<< endl;
}