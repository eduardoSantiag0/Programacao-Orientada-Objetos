#include "Digital.h"

Digital::Digital(string nome, string genero, float preco, string plataforma):
    Jogo(nome, genero, preco), plataforma(plataforma)
{
    
}

Digital::~Digital()
{
    
}

string Digital::getPlataforma()const 
{
    return this->plataforma;
}

void Digital::setPlataforma(string plataforma)
{
    this->plataforma = plataforma;
}


void Digital::imprime()const
{
    Jogo::imprime();
    cout << ", Plataforma: " << this->plataforma << endl;  
}


int Digital::getTipo()const
{
    return DIGITAL;
}