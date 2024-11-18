#include "Triangulo.hpp"
#include "Equilatero.hpp"

int main ()
{
    Triangulo t (3, 4, 5);

    Equilatero e (3);

    t.imprime();

    printf("\n");

    e.imprime();

}