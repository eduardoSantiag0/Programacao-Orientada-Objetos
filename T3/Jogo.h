#ifndef JOGO_H
#define JOGO_H

#include <string>
#include <iostream>
using namespace std;

enum TIPO { TABULEIRO, DIGITAL };

class Jogo
{
public:
    Jogo(string nome, string genero, float preco);
    virtual ~Jogo();
    void Setnome(string nome);
    void Setgenero(string nome);
    void Setpreco(float preco);
    string Getnome()const;
    string Getgenero()const;
    float Getpreco()const;

    virtual void imprime()const;

    virtual int getTipo() const=0;


private:
    string nome, genero;
    float preco;
};

#endif // JOGO_H
