#include "ContaCorrente.hpp"
#include <iostream>

ContaCorrente::ContaCorrente(double saldo, int numero)
{
    this->saldo = saldo;
    this->numero = numero;
}

void ContaCorrente::depositar(double valor)
{
    this->saldo += valor;
}

bool ContaCorrente::retirar (double valor)
{
    if (this->saldo < valor)
        return false;
    
    this->saldo -= valor;
    return true;
}

bool ContaCorrente::transferir (ContaCorrente& contaDestino, double valor)
{
    if (this->retirar(valor)) {
        contaDestino.depositar(valor);
        return true;
    }

    std::cout << "Não foi possível transferir" << std::endl;
    return false;
}

void ContaCorrente::imprimir() const
{
    std::cout << "Conta: " << this->numero << std::endl;
    std::cout << "Saldo: " << this->saldo << std::endl;
    std::cout<< std::endl;
}

double ContaCorrente::getSaldo() const
{
    return this->saldo;
}

short ContaCorrente::compararContas (const ContaCorrente& outraConta) const
{
    return this->saldo - outraConta.saldo;
}


