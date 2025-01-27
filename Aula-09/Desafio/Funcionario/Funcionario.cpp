#include "Funcionario.h"

Funcionario::Funcionario(string CPF, string nome) :
CPF(CPF), nome(nome) {
}

Funcionario::~Funcionario() {
}

void Funcionario::imprime() const {
    cout << "Nome : " << nome << endl;
    cout << "CPF : " << CPF << endl;
    cout << "Profissão : " << getProfissao() << endl;
}

bool Funcionario::comparaCPF(Funcionario* f1,Funcionario* f2)
{
    return f1->CPF < f2->CPF;
}