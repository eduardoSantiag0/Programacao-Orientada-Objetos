#include "Jogo.h"

Jogo::Jogo(string nome, string genero, float preco)
{
    this->nome = nome;
    this->genero = genero;
    this->preco = preco;
}

Jogo::~Jogo()
{
}


void Jogo::Setnome(string nome)
{
    this->nome = nome;
}
void Jogo::Setgenero(string nome)
{
    this->genero = nome;
}
void Jogo::Setpreco(float preco)
{
    this->preco = preco;
}
string Jogo::Getnome()const
{
    return this->nome;
}
string Jogo::Getgenero()const
{
    return this->genero;
}
float Jogo::Getpreco()const
{
    return this->preco;
}

void Jogo::imprime()const
{
    cout << "Nome: "<<  this->nome << ", Genero: " << this->genero << ",  Preco: " << this->preco; 
}