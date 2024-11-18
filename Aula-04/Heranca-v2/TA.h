//// string departamento
//// getDepartamento
//// get setDepartamento
//// Imprimir
//// Criar um TA no main
//// Comparar com outras classes na main

#ifndef TA_H
#define TA_H

#include "Pessoa.h"

class TA : public Pessoa 
{
public: 

    TA(std::string nome, int idade, std::string departamento);
    std::string getDepartamento() const;
    void setDepartamento(std::string d);
    virtual void imprime() const;

private:
    std::string departamento;
};

#endif