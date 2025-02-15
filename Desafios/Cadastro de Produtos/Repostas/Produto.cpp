#include "Produto.h"
#include "EBook.h"
#include "Jogo.h"

Produto::Produto(string titulo, float preco, int ano) :
titulo(titulo), preco(preco), ano(ano) {
}

Produto::~Produto() {
}

string Produto::getTitulo() const {
    return titulo;
}

void Produto::imprime() const {
    cout << "[" << (this->getTipo() == EBOOK ? "EBook" : "Jogo") << "] ";
    cout << this->titulo << " ";
    cout << this->preco << " ";
    cout << this->ano << " ";
}

bool Produto::compara(const Produto* p1, const Produto* p2) {
    char t1 = p1->getTipo();
    char t2 = p2->getTipo();

    if (t1 == t2) {
        if (t1 == EBOOK) {
            return EBook::compara(dynamic_cast<const EBook*>(p1), dynamic_cast<const EBook*>(p2));
        } else {
            return Jogo::compara(dynamic_cast<const Jogo*>(p1), dynamic_cast<const Jogo*>(p2));
        }
    } else {
        return t1 < t2;
    }
}
