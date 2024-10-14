#include <stdio.h>
#include "Estudante.cpp"

int main (void)
{

    Estudante e1 = Estudante (123456, "Delano", "CC", 21);
    Estudante e2 = Estudante (10000, "Cassandro", "CC", 21);

    e1.temMaiorRA(e2);
    e2.temMaiorRA(e1);


    return 0;
}