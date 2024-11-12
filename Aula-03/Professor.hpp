#ifndef PROFESSSOR_H
#define PROFESSSOR_H

#include "Pessoa.hpp"

class Professor : public Pessoa
{
private:
    float salario;
public:
    Professor(std::string nome, int idade, float salario);
    ~Professor();
    float getSalario() const;
    void imprime();

};


#endif