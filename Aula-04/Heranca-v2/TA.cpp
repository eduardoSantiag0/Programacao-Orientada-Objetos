#include "TA.h"

TA::TA(std::string nome, int idade, std::string departamento)
: Pessoa(nome, idade), departamento(departamento) 
{}


std::string TA::getDepartamento() const
{
    return this->departamento;
}


void TA::setDepartamento(std::string d)
{
    this->departamento = d;
}


void TA::imprime() const
{
    Pessoa::imprime();
    std::cout << "Departamento: " << this->departamento << std::endl;
}