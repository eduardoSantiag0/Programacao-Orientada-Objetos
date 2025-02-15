#include "EBook.h"

EBook::EBook(string titulo, float preco, int ano, string autor) :
Produto(titulo, preco, ano), autor(autor) {
}

EBook::~EBook() {
}

char EBook::getTipo() const{
    return EBOOK;
}

void EBook::imprime() const {
    Produto::imprime();
    cout << this->autor << endl;
}

bool EBook::compara(const EBook* e1, const EBook* e2) {
    if (e1->autor == e2->autor) {
        return e1->getTitulo() < e2->getTitulo();
    } else {
        return e1->autor < e2->autor;
    }
}