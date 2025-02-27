#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//// - A lista deve ser organizada em ordem descendente de idade;
//// - Caso dois duendes possuírem a mesma idade, deve se organizar por ordem ascendente de nome;
// - Os primeiros 1/3 dos duendes (os mais velhos), serão os líderes dos times;
// - A ordem dos duendes entregadores e pilotos seguem a mesma lógica dos líderes. 

// Ex) Se há 6 duendes na lista, haverá dois times, onde o duende mais velho é líder do time 1, e o segundo mais velho é líder do time 2. 
// O terceiro mais velho é entregador do time 1 e o quarto mais velho é entregador do time 2. 
// O quinto é piloto de trenó do time 1 e o último é piloto do time 2

struct Duende
{
    string nome;
    int idade;
    
    Duende (string nome, int idade) 
    : nome(nome), idade(idade)
    {
    }

};

bool comparadorIdade(const Duende& d1,const Duende& d2)
{
    if (d1.idade == d2.idade) return d1.nome > d2.nome;
    return d1.idade > d2.idade;
}

int main (void)
{
    ifstream ifs("3176.txt");

    int numeroDuendes;
    ifs >> numeroDuendes;
    int numeroDeTimes = numeroDuendes / 3;

    string nome;
    int idade;
    vector<Duende> duendes;
    

    for (int i = 0; i < numeroDuendes; i++) {
        ifs >> nome >> idade;
        duendes.push_back(Duende(nome, idade));
    }

    sort(duendes.begin(), duendes.end(), comparadorIdade);

    vector<Duende> lideres, entregadores, pilotos;

    for (int i = 0; i < numeroDuendes; i++) {
        if (i < numeroDeTimes)
            lideres.push_back(duendes[i]);
        else if (i < 2 * numeroDeTimes)
            entregadores.push_back(duendes[i]);
        else
            pilotos.push_back(duendes[i]);
    }

    for (int i = 0; i < numeroDeTimes; i++) {
        cout << "Time " << i + 1 << endl;
        cout << "Lider: " << lideres[i].nome << " (" << lideres[i].idade << " anos)" << endl;
        cout << "Entregador: " << entregadores[i].nome << " (" << entregadores[i].idade << " anos)" << endl;
        cout << "Piloto: " << pilotos[i].nome << " (" << pilotos[i].idade << " anos)" << endl;
        cout << endl;
    }

    return 0;
}