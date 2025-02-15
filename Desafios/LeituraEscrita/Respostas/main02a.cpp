#include <iostream>
using namespace std;

int main() {

    int maior = 0;
    int valor;

    cin >> valor;

    while (valor != 0) {
        if (valor > maior) {
            maior = valor;
        }
        cin >> valor;
    }

    cout << maior << endl;

    return 0;
}