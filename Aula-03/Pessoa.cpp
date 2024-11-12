#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa()
{
}

Pessoa::Pessoa(std::string nome, int idade)
{
    this->nome = nome;
    this->idade = idade;
    std::cout << "Pessoa Criada!" << std::endl;
}

Pessoa::~Pessoa()
{
    std::cout << "Pessoa Destruida!" << std::endl;
}

int Pessoa::getIdade()
{
    return this->idade;
}

std::string Pessoa::getNome() 
{
    return this->nome;
}

void Pessoa::imprime()
{
    std::cout << "Nome: " << nome <<  std::endl;
    std::cout << "Idade: " << idade <<  std::endl;
}