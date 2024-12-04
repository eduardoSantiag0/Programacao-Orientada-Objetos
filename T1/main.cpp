#include "POO.cpp"

using namespace poo;

int main (void)
{
    // Criando objetos de DataHorario e Pessoa para testes
    DataHorario dh1(10, 12, 2024, 18, 30, 0); // Data e horário da sessão
    Pessoa pessoa1("João Silva", "123.456.789-00");
    Pessoa pessoa2("Maria Oliveira", "987.654.321-00");

    // Criando uma sessão
    Sessao sessao("Cinema: A Volta dos que Não Foram", dh1);

    // Imprimindo estado inicial da sessão
    cout << "Estado inicial da sessão:" << endl;
    sessao.imprime();
    cout << endl;

    // Testando ocupação de poltronas
    cout << "Ocupando poltrona A1 com João Silva:" << endl;
    if (sessao.ocupa("A1", pessoa1)) {
        cout << "Poltrona A1 ocupada com sucesso!" << endl;
    } else {
        cout << "Falha ao ocupar poltrona A1." << endl;
    }

    cout << "Ocupando poltrona B5 com Maria Oliveira:" << endl;
    if (sessao.ocupa("B5", pessoa2)) {
        cout << "Poltrona B5 ocupada com sucesso!" << endl;
    } else {
        cout << "Falha ao ocupar poltrona B5." << endl;
    }
    cout << endl;

    // Verificando número de vagas
    cout << "Número de poltronas ocupadas: " << sessao.vagas() << endl;

    // Imprimindo estado final da sessão
    cout << "Estado final da sessão:" << endl;
    sessao.imprime();



    return 0;
}