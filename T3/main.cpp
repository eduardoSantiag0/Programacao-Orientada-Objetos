#include "Executar.h"
#include "Jogo.h"
#include "Digital.h"
#include "Tabuleiro.h"

#include <iostream>

using namespace std;

void menu(Executar& executar)
{
    int opcao;
    string nome;
    do {
        cout << "\nMenu:\n";
        cout << "1. Adicionar jogo digital\n";
        cout << "2. Adicionar jogo de tabuleiro\n";
        cout << "3. Exibir um jogo\n";
        cout << "4. Deletar um jogo\n";
        cout << "5. Atualizar preço de um jogo\n";
        cout << "6. Sair\n";
        cout << "7. Exibir todo o catalogo\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                executar.create(DIGITAL);
                break;
            case 2:
                executar.create(TABULEIRO);
                break;
            case 3: {
                cout << "Nome do jogo a exibir: ";
                getline(cin, nome);
                executar.read(nome);
                break;
            }
            case 4: {
                cout << "Nome do jogo a deletar: ";
                getline(cin, nome);
                if (executar.deletar(nome)) {
                    cout << "Jogo deletado com sucesso!\n";
                } else {
                    cout << "Jogo nao encontrado.\n";
                }
                break;
            }
            case 5: 
                cout << "Nome do jogo: ";
                getline(cin, nome);
                executar.update(nome);
                break;
            case 6:
                cout << "Saindo...\n";
                break;
            case 7: 
                executar.imprimirTodos();
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 6);
}

int main() {

    Executar executar("jogos.dat");
    

    Digital* d1 = new Digital("Mario", "Aventura", 200, "Nintendo");    
    Tabuleiro* t1 = new Tabuleiro("Go", "Estrategia", 40, "Madeira");
    executar.createPorParametro(d1);
    executar.createPorParametro(t1);

    menu(executar);


    executar.imprimirTodos();


    return 0;
}
