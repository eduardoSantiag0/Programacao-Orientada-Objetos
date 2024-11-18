
#include "Pessoa.h"

int Pessoa::contador = 0;

Pessoa::Pessoa(string nome, int idade) :
nome(nome), idade(idade) {
    Pessoa::incrementa();
}

Pessoa::~Pessoa() {
    Pessoa::decrementa();
}

string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

int Pessoa::getIdade() const {
    return idade;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

void Pessoa::imprime() const {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
}

int Pessoa::compare(const Pessoa& p) const {
    return idade - p.idade;
}

int Pessoa::getContador() {
    return Pessoa::contador;
}

void Pessoa::incrementa() {
    Pessoa::contador++;
}

void Pessoa::decrementa() {
    Pessoa::contador--;
}

