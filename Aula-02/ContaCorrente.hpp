#ifndef CONTA_CORRENTE_HPP
#define CONTA_CORRENTE_HPP

class ContaCorrente
{

private:
    double saldo;
    int numero;

public:
    ContaCorrente(double saldo, int numero);
    void depositar(double valor);
    bool retirar(double valor);
    bool transferir(ContaCorrente& contaDestino, double valor);
    virtual void imprimir() const;
    double getSaldo() const;

    short compararContas(const ContaCorrente& outraConta) const;

};

#endif