#include "Estudante.hpp"

Estudante::Estudante(int RA, std::string nome, std::string curso, int idade)
{
    this->RA = RA;
    this->nome = nome;
    this->curso = curso;
    this->idade = idade;
}

void Estudante::setRA (int RA)
{
    this->RA = RA;
}

int Estudante::getRA ()
{
    return this->RA;
}

void Estudante::imprime() 
{
    std::cout << "\nNome do Aluno: " << this->nome  << std::endl;  
    std::cout << "\nRA do Aluno: " << this->RA << std::endl;  
}

bool Estudante::temMaiorRA (Estudante outroEstudante) 
{
    if (this->RA > outroEstudante.RA) {
        std::cout << this->nome << " tem um RA maior " << std::endl;
        return true;
    }

    std::cout << "\nRA do " << this->nome << " é menor" << std::endl;
    return false;
}
