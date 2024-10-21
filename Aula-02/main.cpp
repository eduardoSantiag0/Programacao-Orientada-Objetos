#include "ContaCorrente.hpp"
#include "ContaMestre.hpp"


int main (void)
{
    ContaCorrente conta1 = ContaCorrente(100,1);
    ContaCorrente conta2 = ContaCorrente(10,2);

    conta1.transferir(conta2, 20);

    conta1.imprimir();
    conta2.imprimir();

    ContaMestre mestre = ContaMestre(2000, 3);
    mestre.imprimir();

}