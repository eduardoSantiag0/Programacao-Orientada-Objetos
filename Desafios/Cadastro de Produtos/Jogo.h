#ifndef JOGO_H
#define JOGO_H

#include "Produtos.h"

enum Plataforma {
    PLAYSTATION = 0,
    XBOX = 1,
    PC = 2
};

class Jogo : public Produtos
{
private:
    Plataforma plataforma;
public:
    Jogo(string titulo, double preco, int ano, Plataforma plataforma);
    
    ~Jogo();
    Plataforma getPlataforma() const;
    string getClass() const override;

    void setPlataforma(string plataforma);
    void imprime() const;

};



#endif