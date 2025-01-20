#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>

using namespace std;

class Pessoa {
private: 
    string nome;
    string CPF;

public: 
    Pessoa (string nome, string CPF);
    string getNome();
    string getCPF();
    virtual void imprime() const;

};


Pessoa::Pessoa(string nome, string CPF) 
: nome(nome), CPF(CPF) {}

string Pessoa::getNome() { return this->nome; };
string Pessoa::getCPF() { return this->CPF; };

void Pessoa::imprime() const 
{
    cout << "Nome" << this->nome;
    cout << "CPF" << this->CPF;
};

#endif
