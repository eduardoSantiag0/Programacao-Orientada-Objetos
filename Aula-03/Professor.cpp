#include "Professor.hpp"
#include <iostream>

Professor::Professor(std::string nome, int idade, float salario) : Pessoa(nome, idade)
{
    //! POLIMORFISMO
    this->salario = salario;
    std::cout << "Professor Criado!" << std::endl;
}

Professor::~Professor()
{
    std::cout << "Professor Destruida!" << std::endl;
}

float Professor::getSalario() const
{
    return this->salario;
}

void Professor::imprime() 
{
    Pessoa::imprime();
    std::cout << "SALARIO: " << salario <<  std::endl;
}