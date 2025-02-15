#include "Jogo.h"

Jogo::Jogo(string titulo, float preco, int ano, string genero) :
Produto(titulo, preco, ano), genero(genero) {
}

Jogo::~Jogo() {
}

char Jogo::getTipo() const{
    return JOGO;
}

void Jogo::imprime() const {
    Produto::imprime();
    cout << this->genero << endl;
}

bool Jogo::compara(const Jogo* j1, const Jogo* j2) {
    if (j1->genero == j2->genero) {
        return j1->getTitulo() < j2->getTitulo();
    } else {
        return j1->genero < j2->genero;
    }
}