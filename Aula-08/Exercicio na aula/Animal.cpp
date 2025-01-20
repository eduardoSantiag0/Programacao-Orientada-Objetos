#include  "Animal.h"

Animal::Animal(string nome, double peso):nome(nome), peso(peso)
{
};

Animal::~Animal()
{
}

void Animal::imprime ()
{
    cout << "Nome: " << this->nome << endl;
    cout << "Peso: " << this->peso << endl;
}
