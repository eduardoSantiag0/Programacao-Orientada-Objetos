#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.hpp"

class Aluno : public Pessoa
{
private:
    int RA;
public:
    Aluno(std::string nome, int idade, int RA);
    ~Aluno();
    int getIdade();
    std::string getNome();
    int getRA();
    void imprime();
};


#endif