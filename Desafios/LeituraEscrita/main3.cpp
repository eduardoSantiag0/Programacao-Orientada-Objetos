#include <iostream>
#include <fstream>

using namespace std;

//todo Imprimir o maior valor lido

int main (void) 
{

    ifstream arquivoEntrada("entrada02.txt");


    int out = 0;
    int walk;

    while (arquivoEntrada >> walk)
    {
        if (walk > out) {
            out = walk;
        }
    }
    

    cout << "\n Maior numero: " << endl;
    cout << out << endl;


    return 0;
}