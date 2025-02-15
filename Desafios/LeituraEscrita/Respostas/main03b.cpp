#include <fstream>
using namespace std;

int main() {

    ifstream in("entrada03.txt");
    ofstream out("saida03.txt");

    int maior, valor;

    in >> maior;

    while (in >> valor) {
        if (valor > maior) {
            maior = valor;
        }
    }

    out << maior << endl;

    in.close();
    out.close();

    return 0;
}