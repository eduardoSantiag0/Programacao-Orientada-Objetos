#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparador (int& n1, int& n2)
{
    // Par e Impar
    if ((n1 % 2 == 0) && (n2 % 2 != 0)) return true;

    // Impar e Par
    if ((n1 % 2 != 0) && (n2 % 2 == 0)) return false;
    
    // Dentro dos impares e dos pares
    return n1 < n2;
}

int main (void)
{
    int N = 6;
    vector<int> numeros(N);
    numeros = { 1, 2, 3, 4, 5, 6};

    sort(numeros.begin(), numeros.end(), comparador);

    for (const auto& n : numeros) cout << n << endl;
    

    return 0;
}