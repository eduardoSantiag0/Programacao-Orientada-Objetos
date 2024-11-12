#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

class Pessoa 
{
protected:
    std::string nome;
    int idade;
public:

    Pessoa();
    Pessoa(std::string nome, int idade);
    ~Pessoa();
    int getIdade();
    std::string getNome();
    void imprime();

};


#endif