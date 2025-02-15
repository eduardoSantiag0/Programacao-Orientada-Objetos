#include "Produtos.h"
#include"Jogo.h"
#include"Ebook.h"
#include "CRUD.h"


#include <iostream>


int main (void)
{
    CRUD bd ("RegistroProdutos.txt");


    // cout << "Adicione jogos e ebooks na nossa plataforma." << endl;
    
    // int escolha;
    // do
    // {
    //     cout << "Insire 1 para Jogo" << endl;
    //     cout << "2 para Ebook" << endl;
    //     cout << "0 para <PARAR>" << endl;
    //     cin >> escolha;

    //     cin.ignore();

    //     if (escolha != 0)
    //         bd.create(escolha); 
    // }while (escolha != 0);


    Jogo* j1 = new Jogo("Astro Bot", 440, 2024, PLAYSTATION);
    bd.createParams(j1);
    
    
    bd.imprime();

    // string nome;    
    // cout << "Digite o nome de um produto para buscar: ";
    // getline(cin, nome);
    // bd.read(nome);

    return 0;
}