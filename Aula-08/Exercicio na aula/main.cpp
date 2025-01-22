#include "Animal.h"
#include "Peixe.h"
#include "Cao.h"
#include <vector>

using namespace std;

// template <typename T> string chamandoImprimir( T& obj )
// {
//     return obj.getEspecie();
// }

int main (void)
{
    Cao meuCao ("Cido", 20, "Rott");
    Peixe meuPeixe ("Nemo", 2, "Água Doce");

    vector<Animal*> meusAnimais;

    meusAnimais.push_back(&meuCao);
    meusAnimais.push_back(&meuPeixe);

    for (Animal* a : meusAnimais) {
        a->imprime();
        cout << endl;
    }


    cout << Animal::STATIC() << endl;
    return 0;
}