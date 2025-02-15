#include <iostream>
using namespace std;

int main() {

    int N;

    int maior, valor;

    cout << "Insira quantos numeros serão comparados: : " << endl;
    
    cin >> N;
    
    cin >> maior;
    
    for (int i = 0; i < N - 1; i++) {
        cout << "Insira: : ";
        
        cin >> valor;
        if (valor > maior) {
            maior = valor;
        }
    }

    cout << maior << endl;

    return 0;
}