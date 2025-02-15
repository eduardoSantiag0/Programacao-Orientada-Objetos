#include "Jogo.h"


Jogo::Jogo(string titulo, double preco, int ano, Plataforma plataforma)
: Produtos(titulo, preco, ano), plataforma(plataforma)
{
}

Jogo::~Jogo()
{
}

Plataforma Jogo::getPlataforma() const
{
    return this->plataforma;
}

string Jogo::getClass() const
{
    return "J";
}

void Jogo::setPlataforma(string plataforma)
{
    if (plataforma == "PLAYSTATION") 
        this->plataforma = PLAYSTATION;
    else if (plataforma == "XBOX")
        this->plataforma = XBOX;
    else 
        this->plataforma = PC;
        
}

void Jogo::imprime() const
{
    Produtos::imprime();
    cout <<  ", " << " Plataforma: ";
    switch (plataforma) {
        case PLAYSTATION:
            cout << "PLAYSTATION";
            break;
        case XBOX:
            cout << "XBOX";
            break;
        case PC:
            cout << "PC";
            break;
        default:
            cout << "Unknown";
            break;
    }
}