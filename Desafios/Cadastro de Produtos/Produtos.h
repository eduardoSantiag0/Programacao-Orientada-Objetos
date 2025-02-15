#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string>
#include <iostream>

using namespace std;

class Produtos
{
private:
    string titulo;
    double preco;
    int ano;
public:
    Produtos();
    Produtos(string titulo, double preco, int ano);
    virtual ~Produtos();

    string getTitulo() const;
    double getPreco() const;
    int getAno() const;

    void setTitulo(string titulo);
    void setPreco(double preco);
    void setAno(int ano);

    virtual string getClass() const = 0;

    static bool comparaProdutos (const Produtos* p1, const Produtos* p2);

    virtual void imprime() const;

};




#endif