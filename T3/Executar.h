#ifndef EXECUTAR_H
#define EXECUTAR_H

#include "Jogo.h"
#include <vector>
using namespace std;

class Executar {
public:
    Executar(string arquivo);
    virtual ~Executar();

    void create(int tipo);
    void createPorParametro(Jogo* novoProduto);
    void read(string nomePesquisar) const;
    bool update(string nomeAtualizar); 
    bool deletar(string nomeDeletar);

    void imprimirTodos() const;

private:

    void grava();

    int encontrarIndice(string nomePesquisar)const;

    string arquivo;
    vector<Jogo *> jogos;
};

#endif 
