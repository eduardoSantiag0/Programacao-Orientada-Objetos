#include <fstream>
using namespace std;

int main() {

    ifstream in("entrada02.txt");
    ofstream out("saida02.txt");

    int maior = 0;
    int valor;

    in >> valor;

    while (valor != 0) {
        if (valor > maior) {
            maior = valor;
        }
        in >> valor;
    }

    out << maior << endl;

    in.close();
    out.close();

    return 0;
}