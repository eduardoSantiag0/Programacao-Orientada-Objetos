#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

    int valor;
    long unsigned int i;

    vector<int> valores;

    while (cin >> valor) {
        i = 0;
        while (i < valores.size() && valor > valores[i]) {
            i++;
        }
        valores.emplace(valores.begin() + i, valor);
    }

    for (i = 1; i <= valores.size(); i++) {
        cout << setw(3) << setfill(' ') << valores[i - 1] << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}