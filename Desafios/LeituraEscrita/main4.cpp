#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//// ler do arquivo
//todo ordenar em ordem crescente 
//? usar método emplace
//todo escrever em um novo arquivo

void swap (int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int main (void)
{
    ifstream arqEntrada ("entrada05-meu.txt");
    

    vector<int> vetorOrdenado;  
    
    long unsigned int pos;
    int valor;

    while (arqEntrada >> valor)
    {
        pos = 0;
        while (pos < vetorOrdenado.size() && valor > vetorOrdenado[pos])
        {
            pos++;
        }

        vetorOrdenado.emplace(vetorOrdenado.begin() + pos, valor);
        
    }

    arqEntrada.close();

    for (const auto& num : vetorOrdenado) {
        cout << num;
        if (num < vetorOrdenado.size() ) 
            cout  << ", ";
    }

    ofstream arqSaida ("entrada06-meu-ordenado.txt");
    
    for (long unsigned int i = 0 ; i < vetorOrdenado.size(); i++) {
        arqSaida << vetorOrdenado[i] << endl;

    }
    
    arqSaida.close();



}