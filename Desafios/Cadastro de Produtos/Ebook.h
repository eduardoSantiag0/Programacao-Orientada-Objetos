#ifndef EBOOK_H
#define EBOOK_H

#include "Produtos.h"

class Ebook : public Produtos
{
private:
    string autor;
public:
    Ebook(string titulo, double preco, int ano, string autor);

    ~Ebook();
    string getAutor() const;
    string getClass() const override;
    void setAutor(string autor);
    void imprime() const;

};



#endif