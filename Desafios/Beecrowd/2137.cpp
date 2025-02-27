#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define CODE_SIZE 4

// bool comparadorString (string& s1, string& s2) 
// {
//     for (int i = 0; i <  CODE_SIZE; i++) {
//         if (s1[i] >= s2[i]) return true;
//     }
//     return false;
// }

int main (void)
{
    ifstream ifs ("2137.txt");

    vector<string> codigos;

    string linha;
    while (getline(ifs, linha))
    {
        if (linha.size() == 4) {
            codigos.push_back(linha);
        }
    }

    // Ordenar por primeiro caracter
    // sort(codigos.begin(), codigos.end(), comparadorString);
    sort(codigos.begin(), codigos.end());

    for (const auto& s : codigos) 
        cout << s << endl;
    


    return 0;
}