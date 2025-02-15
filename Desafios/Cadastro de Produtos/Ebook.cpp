#include "Ebook.h"

Ebook::Ebook (string titulo, double preco, int ano, string autor)
: Produtos(titulo, preco, ano), autor(autor)
{
}

Ebook::~Ebook()
{
}

string Ebook::getAutor() const 
{
    return this->autor;
}


string Ebook::getClass() const
{
    return "E";
}


void Ebook::setAutor(string autor)
{
    this->autor = autor;
}


void Ebook::imprime() const
{
    Produtos::imprime();
    cout <<  ", " << " Autor: " << autor;
}