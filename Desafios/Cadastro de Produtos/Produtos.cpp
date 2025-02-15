#include "Produtos.h"

Produtos::Produtos(string titulo, double preco, int ano)
: titulo(titulo), preco(preco), ano(ano)
{
}

Produtos::Produtos()
{
}

Produtos::~Produtos()
{
}

void Produtos::imprime() const
{
    cout << "Titulo: " << titulo << ", ";
    cout << " Preco: " << preco << ", ";
    cout << " Preco: " << ano;
}

string Produtos::getTitulo() const 
{
    return this->titulo;
}

double Produtos::getPreco() const 
{
    return this->preco;
}

int Produtos::getAno() const 
{
    return this->ano;
}


void Produtos::setTitulo(string titulo) { this->titulo = titulo; }
void Produtos::setPreco(double preco) { this->preco = preco; }
void Produtos::setAno(int ano) { this->ano = ano; }