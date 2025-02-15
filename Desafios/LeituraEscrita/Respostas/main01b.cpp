#include <fstream>
using namespace std;

int main() {
    
    ifstream in("entrada01.txt");
    ofstream out("saida01.txt");

    int N;

    int maior, valor;
    
    in >> N;

    in >> maior;

    for (int i = 0; i < N - 1; i++) {
        in >> valor;
        if (valor > maior) {
            maior = valor;
        }
    }

    out << maior << endl;

    in.close();
    out.close();

    return 0;
}