#include "ContaMestre.hpp"
#include <iostream>

ContaMestre::ContaMestre(double saldo, int numero) : ContaCorrente (saldo, numero)
{
}

void ContaMestre::imprimir() const
{
    ContaCorrente::imprimir();
    std::cout << "Conta Mestre!!" << std::endl; 
}