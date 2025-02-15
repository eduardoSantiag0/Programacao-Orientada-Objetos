#include "Executar.h"
#include "Digital.h"
#include "Tabuleiro.h"
#include <algorithm>
#include <fstream>
using namespace std;

Executar::Executar(string arquivo) : arquivo(arquivo) {
    int tipo, tam;
    float preco;
    string nome, genero, material, plataforma;

    ifstream entrada(arquivo, ios::binary);

    if (entrada.is_open()) {

        jogos.clear();

        // Lendo o tipo

        entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

        while (entrada.good()) {
            
            //* Lendo o nome
            
            // Lendo o tamanho da string (nome)
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            nome.resize(tam);
            // Lendo os caracteres da string (nome)
            entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

            // cout << nome << ", ";
            
            //* Lendo o genero
            
            // Lendo o tamanho da string (genero)
            entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            genero.resize(tam);
            // Lendo os caracteres da string (genero)
            entrada.read(reinterpret_cast<char *>(&genero[0]), tam);
            // cout << genero << ", ";
            
            
            //* Lendo o preço
            entrada.read(reinterpret_cast<char *>(&preco), sizeof(preco));
            // cout << preco << ", ";


            switch (tipo) {
                case DIGITAL: {
                    //* Lendo a plataforma

                    // Lendo o tamanho da string (plataforma)
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    plataforma.resize(tam);

                    // Lendo os caracteres da string (plataforma)
                    entrada.read(reinterpret_cast<char *>(&plataforma[0]), tam);

                    jogos.push_back(new Digital (nome, genero, preco, plataforma));
                    break;
                }
                case TABULEIRO: {

                    // Lendo o material

                    // Lendo o tamanho da string (material)
                    entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    material.resize(tam);

                    // Lendo os caracteres da string (material)
                    entrada.read(reinterpret_cast<char *>(&material[0]), tam);

                    jogos.push_back(new Tabuleiro(nome, genero, preco, material));
                    break;
                }

                default:
                    cerr << "Tipo desconhecido encontrado." << endl;
                    break;
            }

            // Lendo o tipo
            entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        }
    }
    entrada.close();

    // imprimirTodos();

}

Executar::~Executar() {
    for (long unsigned int i = 0; i < jogos.size(); i++)  {
        delete jogos[i];
    }
}


void Executar::grava()
{
    int tipo, tam;
    string nome, genero;
    float preco;

    Digital* d1;
    Tabuleiro* t1;

    ofstream saida(arquivo, ios::binary);


    for (long unsigned int i = 0; i < jogos.size(); i++)  {

        //1. Tipo
        tipo = jogos[i]->getTipo();
        saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));
        
        //2. Nome
        nome = jogos[i]->Getnome();
        tam = static_cast<int>(nome.size());
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&nome[0]), tam);
        
        
        //3. Genero
        genero = jogos[i]->Getgenero();
        tam = static_cast<int>(genero.size());
        saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        saida.write(reinterpret_cast<char *>(&genero[0]), tam);
        
        
        //4. Preço
        preco = jogos[i]->Getpreco();
        saida.write(reinterpret_cast<char *>(&preco), sizeof(preco));
        
        //5. OutroAtributo
        string outroAtributo;
        switch (tipo)
        {
        case DIGITAL:
            d1 = dynamic_cast<Digital*>(jogos[i]);
            outroAtributo = d1->getPlataforma();
            tam = static_cast<int>(outroAtributo.size());
            saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
            saida.write(reinterpret_cast<char *>(&outroAtributo[0]), tam);

        break;
            
        case TABULEIRO:
            
            t1 = dynamic_cast<Tabuleiro*>(jogos[i]);
            outroAtributo = t1->Getmaterial();
            tam = static_cast<int>(outroAtributo.size());
            saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));
            saida.write(reinterpret_cast<char *>(&outroAtributo[0]), tam);
        
        default:
            break;
        }


    }

    saida.close();
}

void Executar::create(int tipo)
{
    string nome, genero;
    float preco;

    Jogo* novoJogo;

    cout << "Titulo? " << endl;
    getline(cin, nome);
    
    cout << "Genero? " << endl;
    cin >> genero;
    
    cout << "Preco? " << endl;
    cin >> preco;
    cin.ignore();

    string outroAtributo;
    switch (tipo)
    {
    case TABULEIRO:
        cout << "Material? " << endl;
        getline(cin, outroAtributo);
        novoJogo = new Tabuleiro(nome, genero, preco, outroAtributo);        
    break;
    
    case DIGITAL:
        cout << "Plataforma? " << endl;
        getline(cin, outroAtributo);
        novoJogo = new Digital(nome, genero, preco, outroAtributo);        
    break;

    default:
        break;
    }

    if (novoJogo) {
        jogos.push_back(novoJogo);
        grava();
    }
}

void Executar::createPorParametro(Jogo* novoProduto) 
{
    jogos.push_back(novoProduto);
    grava();
}

int Executar::encontrarIndice(string nomePesquisar)const
{
    for (int i = 0; i < jogos.size() ; i++) {
        if (jogos[i]->Getnome() == nomePesquisar) {
            return i;
        }
    }

    return -1;

}

bool Executar::deletar(string nomeDeletar) {
    int posicao = encontrarIndice(nomeDeletar);
    
    if (posicao == -1) return false;

    Jogo* jogoDeletar = jogos[posicao];
    jogos.erase(jogos.begin() + posicao);
    delete jogoDeletar;
    
    grava();
    return true;
} 


void Executar::read(string nomePesquisar) const
{
    int pos = encontrarIndice(nomePesquisar);
    if (pos == -1) {
        cout << "O seguinte jogo NAO esta cadastrado no nosso banco -> " << nomePesquisar << endl;
        return;
    }

    Jogo* jogoEncontrado = jogos[pos];
    
    jogoEncontrado->imprime();
}


void Executar::imprimirTodos() const
{
    cout << "\t Nosso catalogo: " << endl;
    for (unsigned long int i = 0; i < jogos.size() ; i++) {
        jogos[i]->imprime();
    }
}




bool Executar::update(string nomeAtualizar)
{
    int pos = encontrarIndice(nomeAtualizar);

    if (pos == - 1 ) return false;

    Jogo* jogoParaAtualizar = jogos[pos];

    float novoPreco;

    cout << "Qual o novo preco de: " << jogoParaAtualizar->Getnome() << " ( preco atual: " << jogoParaAtualizar->Getpreco() << " ) " << endl;
    cin >> novoPreco;

    jogoParaAtualizar->Setpreco(novoPreco);
    grava();
    return true;

}