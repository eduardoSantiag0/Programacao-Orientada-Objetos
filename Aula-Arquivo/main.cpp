#include <iomanip>  
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

typedef int Tempo;
typedef string Jogo;

class CRUD
{

private: 
    vector<Jogo> jogosCadastrados;
    fstream streamDeDados;

public: 

    CRUD(string nomeArquivo)
    {
        streamDeDados.open(nomeArquivo);
    }

    void create(Jogo jogo);
    Jogo read();
    bool update(Jogo jogo);
    bool deletar(Jogo jogo);
};

class  Nivel
{
public: 

    //* Atributos da Fase 
    int numeroFase;
    bool coletaveis[5];
    Tempo menorTempoEmSegundos;

    Nivel(int fase, bool* c, Tempo tempo) 
    : numeroFase(fase), menorTempoEmSegundos(tempo)
    {
        for (int i = 0; i < 5; i++) {
            coletaveis[i] = c[i];
        }
    }
};

void criarHeaderr(ofstream& arquivoSalvamento)
{
    string header = "Numero da Fase, Menor Tempo, Colecionaveis";
    arquivoSalvamento << header;
    arquivoSalvamento << endl;
    arquivoSalvamento << endl;
}

void salvarDados (ofstream& arquivoSalvamento, Nivel& nivel)
{
    arquivoSalvamento << nivel.numeroFase << ", ";
    arquivoSalvamento << nivel.menorTempoEmSegundos << ", ";

    for (int i = 0; i < 5; i++) {
        arquivoSalvamento << nivel.coletaveis[i] << " ";
    }

    arquivoSalvamento << endl;
}


int main (void)
{
    ofstream arquivoSalvamento("salvamento.txt");
    criarHeaderr(arquivoSalvamento);


    bool itemColecionados[]  = { 0, 1, 1, 0, 1 };
    bool itemColecionados2[]  = { 1, 0, 1, 0, 0 };
    bool itemColecionados3[]  = { 0, 0, 0, 1, 1 };
    bool itemColecionados4[]  = { 0, 1, 1, 0, 1 };


    Nivel niveis[4] = {
        Nivel(1, itemColecionados2, 60),
        Nivel(2, itemColecionados, 100),
        Nivel(3, itemColecionados, 120),  
        Nivel(4, itemColecionados2, 140)  
    };

    for (auto& n : niveis) {
        salvarDados(arquivoSalvamento, n);
    }


    arquivoSalvamento.close();
    return 0;
}