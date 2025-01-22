#include "Pessoa.hpp"
#include <iostream>

using namespace std;


class Professor : public Pessoa
{
private:
    double salario;
public:
    Professor(string nome, string CPF, double salario);
    virtual double getSalario() const;
    void imprime() const;
};

Professor::Professor(string nome, string CPF, double salario)
: Pessoa(nome, CPF), salario(salario)
{
}

void Professor::imprime() const
{
    Pessoa::imprime();
    cout << "Salario: " << salario << endl;
}

double Professor::getSalario() const
{
    return this->salario;
}