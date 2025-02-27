#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct carne 
{
    string nome;
    int data;

    carne (string nome, int data) {
        this->nome = nome;
        this->data = data;
    }

};

bool comp (const carne& c1, const carne&c2) 
{
    return c1.data < c2.data;
}

int main (void)
{
    ifstream ifs("2633.txt");
    
    int numeroPecasDeCarne;

    ifs >> numeroPecasDeCarne;

    vector<carne> carnes;

    string nome;
    int dataValidade;
    for (unsigned long int i = 0 ; i < numeroPecasDeCarne; i++) {
        ifs >> nome;
        ifs >> dataValidade;
        carnes.push_back(carne(nome, dataValidade));
    }

    sort(carnes.begin(), carnes.end(), comp);

    for (const auto& c : carnes) {
        cout << c.nome << " ";
    }

    return 0;
}