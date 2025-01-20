#include "Pessoa.hpp"
#include "Professor.hpp"
#include "Coordenador.hpp"
#include <iostream>
using namespace std;

void imprimeReferencia (Pessoa& p) {
    // Uma referência é passada para a função
    p.imprime();
}

void imprimeValor (Pessoa p) {
    // Uma cópia é passada para a função
    p.imprime();
}

int main() {
    
    //? Como um ponteiro para pessoa guarda o salario (float) 
    //? se Pessoa não possui esse atributo? 
    Pessoa* p = new Professor("Fulano", "12345678-9", 5000);

    p->imprime();

    // Pessoa* pessoas[3];
    
    // Pessoa p1("Fulano", "12345");
     
    // Professor p2("Sincrano", "54321", 1000);
    
    // Coordenador p3("Beltrano", "13579", 2000, "BCC");

    // cout << endl << "----------------------------- " << endl << endl;

    // pessoas[0] = &p1;
    // pessoas[1] = &p2;
    // pessoas[2] = &p3;
    
    // for (int i = 0; i < 3; i++) {
    //     pessoas[i]->imprime();
    //     cout << endl;
    // }

    // cout << "----------------------------- " << endl << endl;

    // imprimeValor(p1);
    // cout << endl;
    // imprimeValor(p2);
    // cout << endl;
    // imprimeValor(p3);
    // cout << endl;
    
    // cout << "----------------------------- " << endl << endl;
    
    // imprimeReferencia(p1);
    // cout << endl;
    // imprimeReferencia(p2);
    // cout << endl;
    // imprimeReferencia(p3);
    // cout << endl;

    // cout << "----------------------------- " << endl << endl;

    return 0;
}

