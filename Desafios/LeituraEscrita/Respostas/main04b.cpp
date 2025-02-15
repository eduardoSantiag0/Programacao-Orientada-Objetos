#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {

    ifstream in("entrada04.txt");
    ofstream out("saida04.txt");

    int valor;
    long unsigned int i;

    vector<int> valores;

    while (in >> valor) {
        i = 0;
        while (i < valores.size() && valor > valores[i]) {
            i++;
        }
        valores.emplace(valores.begin() + i, valor);
    }

    for (i = 1; i <= valores.size(); i++) {
        out << setw(3) << setfill(' ') << valores[i - 1] << " ";
        if (i % 10 == 0) {
            out << endl;
        }
    }

    in.close();
    out.close();

    return 0;
}