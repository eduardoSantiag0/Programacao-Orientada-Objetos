#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
using namespace std;

enum Tipo { EBOOK = 'E', JOGO ='J'};

class Produto {
public:
    Produto(string, float, int);
    virtual ~Produto();
    virtual string getTitulo() const;
    virtual char getTipo() const = 0;
    virtual void imprime() const;

    static bool compara(const Produto*, const Produto*);
private:
    string titulo;
    float preco;
    int ano;
};

#endif /* PRODUTO_H */
