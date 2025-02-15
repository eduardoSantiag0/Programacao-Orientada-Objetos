#ifndef CRUD_H
#define CRUD_H

#include "Produtos.h"
#include"Jogo.h"
#include"Ebook.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class CRUD
{

public:
    CRUD(string nomeArq);
    ~CRUD();

    void create(int tipo);
    void read(string nomePesquisar) const;
    bool update(string nomeAtualizar); 
    bool deletar(string nomeDeletar);
    void createParams(Produtos* novoProduto);

    void imprime();

private:
    void grava();
    void lerLinha(Produtos* produto, string linha);
    Produtos* procurarPorNome(string nome) const;

    void carregarTxt();
    
    string nomeArquivo;
    vector<Produtos *> produtosRegistrados;
    const static char delimittador = ',';



};


#endif