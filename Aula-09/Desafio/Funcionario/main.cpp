#include "Funcionario.h"
#include "Medico.h"
#include "Enfermeiro.h"
#include <vector>
#include <iostream>

int main (void)
{
    Medico m1 ("345678901-23", "DrHouse", "Neurologista");
    Medico* m2 = new Medico ("145678901-23", "Dr Xavier", "Cardiologista");

    Enfermeiro e1 ("245678901-12", "Enfermeira", 12345);
    Enfermeiro* e2 = new Enfermeiro ("445678901-12", "Outra Enfermeira", 54321);


    vector<Funcionario*> funcionarios;

    funcionarios.push_back(&m1);
    funcionarios.push_back(m2);
    funcionarios.push_back(&e1);
    funcionarios.push_back(e2);

    for (Funcionario* f : funcionarios) {
        f->imprime();
        std::cout << std::endl;
    }

    std::cout << Funcionario::comparaCPF(&m1, m2) << std::endl;

    // sort(funcionarios.begin(), funcionarios.end());

    delete m2;
    delete e2;

    return 0;
}