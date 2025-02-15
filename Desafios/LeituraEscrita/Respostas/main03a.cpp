#include <iostream>
using namespace std;

int main() {

    int maior, valor;

    cin >> maior;

    while (cin >> valor) {
        if (valor > maior) {
            maior = valor;
        }
    }

    cout << maior << endl;

    return 0;
}