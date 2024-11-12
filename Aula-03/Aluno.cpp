#include "Aluno.hpp"
#include <iostream>

// Aluno::Aluno(std::string nome, int idade, int RA)
Aluno::Aluno(std::string nome, int idade, int RA) : Pessoa(nome, idade)
{
    //! POLIMORFISMO
    this->RA = RA;
    std::cout << "Aluno Criado!" << std::endl;
}

Aluno::~Aluno()
{
    std::cout << "Aluno Destruida!" << std::endl;
}

int Aluno::getIdade()
{
    return this->idade;
}

std::string Aluno::getNome() 
{
    return this->nome;
}

void Aluno::imprime()
{
    Pessoa::imprime();
    std::cout << "RA: " << RA <<  std::endl;
}