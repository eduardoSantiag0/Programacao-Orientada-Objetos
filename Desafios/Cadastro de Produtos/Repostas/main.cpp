#include "Catalogo.h"
#include "EBook.h"
#include "Jogo.h"

int main() {

    int N, ano;
    char tipo;
    string titulo, autor, genero;
    double preco;
    Catalogo catalogo;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tipo >> titulo >> preco >> ano;
        if (tipo == EBOOK) {
            cin >> autor;
            catalogo.adicionaProduto(new EBook(titulo, preco, ano, autor));
        } else {
            cin >> genero;
            catalogo.adicionaProduto(new Jogo(titulo, preco, ano, genero));
        }
    }

    cout << catalogo.qtdeEBooks() << " e-books foram cadastrados." << endl;
    cout << catalogo.qtdeJogos() << " jogos foram cadastrados." << endl;
    
    catalogo.imprime();

    return 0;
}