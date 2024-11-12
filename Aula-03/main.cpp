#include "Pessoa.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include <iostream>

int main (void) 
{
    Pessoa p1 ("Fulano", 18);
    Pessoa p2 ("Sicrano Andrade", 19);
    Pessoa p3 ("Beltrano dos Santos", 21);
    Aluno a1 ("Aluno Teste", 18,987654);
    Professor prof1  ("Professor Teste", 42, 5000);

    Pessoa* cadastro[5];

    cadastro[0] = &p1;
    cadastro[1] = &p2;
    cadastro[2] = &p3;
    cadastro[3] = &a1;
    cadastro[4] = &prof1;

    std::cout << "\n"  << std::endl;

    prof1.imprime();


    std::cout << "\n"  << std::endl;
    cadastro[4]->imprime(); 

    std::cout << "\n"  << std::endl;

    return 0;
}