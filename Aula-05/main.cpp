#include <iostream>
using namespace std;


class Automovel {

public:
    Automovel(string marca, int ano) : marca(marca), ano(ano){};
    void setAno(int ano) { this->ano = ano; };
    void imprime() { cout << "Marca " << marca << " do ano " << ano << endl;}
    string getDescricao() { return "Marca " + marca + " do ano " + to_string(ano);}
private:
    string marca;
    int ano;

};

class Pessoa {
public:
    Pessoa (std::string nome, int idade, Automovel* carrao): nome(nome), idade(idade), carrao(carrao) {};
    void imprime() { cout << "\t" << nome << " tem o carro: < " << carrao->getDescricao() << " > " << endl; }
private:
    std::string nome; 
    int idade;
    Automovel* carrao;

};

int main (void)
{
    Automovel fuscao ("FUSCA", 1977);
    Pessoa fulano ("FULANO", 40, &fuscao);

    fulano.imprime();

}