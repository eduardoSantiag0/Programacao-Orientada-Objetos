#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

bool comp (int& n1, int& n2) {
    return n1 > n2;
}

int main (void)
{
    ifstream ifs("2534.txt");

    int habitantes, consultas;
    string header;
    getline(ifs, header);

    stringstream ss (header);
    ss >> habitantes;
    ss >> consultas;

    string linha;
    vector<int> notas;
    for (int i = 0; i < habitantes; i++) {
        getline(ifs, linha);
        notas.push_back(stoi(linha));
    }

    sort(notas.begin(), notas.end(), comp);

    for (int i = 0; i < consultas; i++) {
        // Posição para cuja nota deve ser consultada
        int pos;
        ifs >> pos;
        // Nota correspondente à posição consultada
        cout << notas[pos - 1] << endl; 
    }

    
    return 0;
}