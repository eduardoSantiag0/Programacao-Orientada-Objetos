#include "CRUD.h"
#include <sstream>

using namespace std;


CRUD::CRUD(string nomeArquivo) : nomeArquivo(nomeArquivo)
{
    cout << "BEM-VINDO AO REGISTRO DE PRODUTOS!" << endl;
    carregarTxt();
}

CRUD::~CRUD()
{
    for (long unsigned int i = 0; i < produtosRegistrados.size(); i++) {
        delete produtosRegistrados[i];
    }

}

// Class, Titulo, Preço, Ano, Autor/Plataforma
void CRUD::lerLinha(Produtos* produto, string linha) 
{
    stringstream ss(linha);
    string atributo;

    getline(ss, atributo, CRUD::delimittador);

    if (atributo == "[JOGO]") {
        Jogo* jogo = dynamic_cast<Jogo*>(produto);

        getline(ss, atributo, CRUD::delimittador);
        produto->setTitulo(atributo); 
        
        getline(ss, atributo, CRUD::delimittador);
        produto->setPreco(stod(atributo)); 
    
        getline(ss, atributo, CRUD::delimittador);
        produto->setAno(stoi(atributo));
        
        getline(ss, atributo, CRUD::delimittador);
        jogo->setPlataforma(atributo);

    } else if (atributo == "[EBOOK]") {
        Ebook* ebook = dynamic_cast<Ebook*>(produto);

        getline(ss, atributo, CRUD::delimittador);
        produto->setTitulo(atributo);
        
        getline(ss, atributo, CRUD::delimittador);
        produto->setPreco(stod(atributo)); 
    
        getline(ss, atributo, CRUD::delimittador);
        produto->setAno(stoi(atributo));
        
        getline(ss, atributo, CRUD::delimittador);
        ebook->setAutor(atributo);
    }
}


void CRUD::grava()
{
    ofstream ofs (nomeArquivo);

    int ebooksCadastrados = 0;
    int jogosCadastrados = 0;

    for (auto p : produtosRegistrados) {
        if (p->getClass() == "E") 
            ebooksCadastrados++;
        else if (p->getClass() == "J")
            jogosCadastrados++;
    }

    ofs << ebooksCadastrados << " e-books foram cadastrados" << endl;
    ofs << jogosCadastrados << " jogos foram cadastrados" << endl;

    for (long unsigned int i = 0; i < produtosRegistrados.size(); i++) {
        if (produtosRegistrados[i]->getClass() == "J") {
            ofs << "[JOGO]" << CRUD::delimittador;
        } else { 
            ofs << "[EBOOK]" << CRUD::delimittador;
        }

        ofs << produtosRegistrados[i]->getTitulo() << CRUD::delimittador;
        ofs << produtosRegistrados[i]->getPreco() << CRUD::delimittador;
        ofs << produtosRegistrados[i]->getAno() << CRUD::delimittador;

        Jogo* jogo = dynamic_cast<Jogo*>(produtosRegistrados[i]);
        Ebook* ebook = dynamic_cast<Ebook*>(produtosRegistrados[i]);

        if (jogo) 
            ofs << jogo->getPlataforma() ;
        else 
            ofs << ebook->getAutor();

        ofs << endl;
    }

    ofs.close();

}


Produtos* CRUD::procurarPorNome(string nome) const
{
    for (long unsigned int i = 0; i < produtosRegistrados.size() ; i++) {
        if (produtosRegistrados[i]->getTitulo() == nome) {
            Produtos* p = produtosRegistrados[i];
            return p;
        }
    } 

    return nullptr;
}



void CRUD::create(int tipo) 
{
    string titulo;
    double preco;
    int ano;
    Produtos* p;

    
    cin.ignore();
    cout << "Titulo? " << endl;
    getline(cin, titulo);
    
    cout << "Preco? " << endl;
    cin >> preco;
    
    cout << "Ano? " << endl;
    cin >> ano;

    string autor;
    switch (tipo)
    {
    case 1: // Jogo
        cout << "Plataforma? (0 - PLAYSTATION, 1 - XBOX, 2 - PC)" << endl;
        int num;
        cin >> num;
        p = new Jogo(titulo, preco, ano, static_cast<Plataforma> (num));
        break;
    
    case 2: // Ebook
        cin.ignore();
        cout << "Autor? " << endl;
        getline(cin, autor);
        cin.ignore();
        p = new Ebook(titulo, preco, ano, autor);
        break;

    default:
        cout << "Tipo inválido!" << endl;
        return;  
    }

    produtosRegistrados.push_back(p);
    grava();
}


void CRUD::createParams(Produtos* novoProduto) 
{
    produtosRegistrados.push_back(novoProduto);
    grava();  
}

void CRUD::read(string nomePesquisar) const
{
    Produtos* p = procurarPorNome(nomePesquisar);

    if (!p) {
        cout << nomePesquisar << " NAO esta registrado no nosso banco" << endl; 
    } else {
        p->imprime();
    }

}

bool CRUD::update(string nomeAtualizar)
{
    Produtos* p = procurarPorNome(nomeAtualizar);

    if (!p) return false;

    double novoPreco;

    cout << "Qual o novo preco de: " << p->getTitulo() << " ( preco atual: " << p->getPreco() << " ) " << endl;
    cin >> novoPreco;

    p->setPreco(novoPreco);
    grava();
    return true;

}

bool CRUD::deletar(string nomeDeletar) 
{
    for (long unsigned int i = 0; i < produtosRegistrados.size() ; i++) {
        if (produtosRegistrados[i]->getTitulo() == nomeDeletar) {
            Produtos* p = produtosRegistrados[i];
            produtosRegistrados.erase(produtosRegistrados.begin() + i);
            delete p;
            grava();
            imprime();
            return true;
        }
    }


    
    return false;
}

void CRUD::carregarTxt()
{
    ifstream ifs(nomeArquivo);
    if (!ifs.is_open()) {
        cerr << "Erro ao abrir o arquivo para leitura!" << endl;
        return;
    }

    string linha;
    getline(ifs, linha);
    getline(ifs, linha);

    while (getline(ifs, linha)) {
        
        stringstream ss (linha);
        string tipoProduto;
        getline(ss, tipoProduto, CRUD::delimittador);
        
        Produtos* p = nullptr;
        if (tipoProduto == "[JOGO]") {
            p = new Jogo("", 0, 0, PLAYSTATION);
        } else if (tipoProduto == "[EBOOK]") {
            p = new Ebook("", 0, 0, "");
        }
        
        
        if (p) {
            lerLinha(p, linha);
            produtosRegistrados.push_back(p);
        }
    }

    ifs.close();
}

void CRUD::imprime()
{
    for (auto p : produtosRegistrados) {
        p->imprime();
        cout << endl;
    }
}
