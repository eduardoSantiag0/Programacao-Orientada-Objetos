#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "Produto.h"

using namespace std;

class Catalogo {
public:
    Catalogo();
    virtual ~Catalogo();
    bool adicionaProduto(Produto*);
    void imprime() const;
    int qtdeProdutos() const; 
    int qtdeEBooks() const;
    int qtdeJogos() const;
private:
    vector<Produto*> produtos;
    int qtde(Tipo tipo) const;
};

#endif /* CATALOGO_H */