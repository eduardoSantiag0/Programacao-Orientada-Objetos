#ifndef ESTUDANTE_H //* Evita o compilador incluir o mesmo arquivo mais de uma vez 
#define ESTUDANTE_H


#include <string>
#include <stdio.h>
#include <iostream>


class Estudante 
{

public:
    Estudante(int RA, std::string nome, std::string curso, int idade);

    void setRA(int RA);
    int getRA();
    
    void imprime();
    bool temMaiorRA (Estudante outroEstudante);

private: 

    int RA;
    std::string nome;
    std::string curso;
    int idade;

};

#endif