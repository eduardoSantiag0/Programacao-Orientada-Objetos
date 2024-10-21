#ifndef CONTA_MESTRE_HPP
#define CONTA_MESTRE_HPP

#include "ContaCorrente.hpp"

class ContaMestre : public ContaCorrente
{
public:
    ContaMestre(double saldo, int numero);
    void imprimir() const;
};

#endif