#include "Tabuleiro.h"

Tabuleiro::Tabuleiro(string nome, string genero, float preco, string material):
    Jogo(nome, genero, preco), material(material)
{
    
}

Tabuleiro::~Tabuleiro()
{
    
}

void Tabuleiro::SetMaterial (string material)
{
    this->material = material;
}

string Tabuleiro::Getmaterial() const
{
    return this->material;
}

void Tabuleiro::imprime()const
{
    Jogo::imprime();
    cout << ", Material: " << this->material << endl;  
}

int Tabuleiro::getTipo() const
{
    return TABULEIRO;
}
