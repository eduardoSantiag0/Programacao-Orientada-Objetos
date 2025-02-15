#include <algorithm>

#include "Catalogo.h"

Catalogo::Catalogo() {
}

Catalogo::~Catalogo() {
}

bool Catalogo::adicionaProduto(Produto* p) {
    produtos.push_back(p);
    return true;
}

void Catalogo::imprime() const {
    vector<Produto*> copia = produtos;

    sort(copia.begin(), copia.end(), Produto::compara);

    for (unsigned long int i = 0; i < copia.size(); i++) {
        copia[i]->imprime();
    }
}

int Catalogo::qtdeProdutos() const  {
    return produtos.size();
}

int Catalogo::qtde(Tipo tipo) const {
    int contador = 0;
    for (unsigned long int i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getTipo() == tipo) {
            contador++;
        }
    }
    return contador;
}

int Catalogo::qtdeEBooks() const {
    return qtde(EBOOK);
}

int Catalogo::qtdeJogos() const {
    return qtde(JOGO);
}