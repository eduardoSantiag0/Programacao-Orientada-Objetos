

#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Animal 
{
private: 
    string nome;
    double peso;

public:

    Animal(string nome, double peso);
    virtual ~Animal();
    // string getNome();
    // void setNome();
    // double getPeso();
    // void setPeso();
    virtual string getEspecie() const = 0;
    virtual void imprime();

    static string STATIC() { return "static"; };
    
};

#endif