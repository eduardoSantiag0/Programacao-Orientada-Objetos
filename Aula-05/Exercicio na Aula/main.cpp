#include <iostream>


using namespace std;

class Pessoa
{
public:
    Pessoa (string nome, int cpf) : nome(nome), cpf(cpf) {}; 
protected:
    string nome;
    int cpf;
};

class Universidade
{
public: 
    Universidade(string nome, string sigla) : nome(nome), sigla(sigla) {};

    string getNome() const { return this->nome; };
    string getSigla() const { return this->sigla; };

private:
    string nome;
    string sigla;
};

class Professor : public Pessoa
{
public: 
    Professor( string nome, int cpf, float salario, string nomeUniversidade, string siglaUniversidade ) :
        Pessoa(nome, cpf), 
        salario(salario), 
        universidade(nomeUniversidade, siglaUniversidade) {};

    void imprime() {
        cout << "\nNome: " << this->nome << ", CPF: " << this->cpf << ", Salario: " << this->salario << "\nUniversidade: " << this->universidade.getNome() << " - " << this->universidade.getSigla() << endl << endl;
    }
private: 
    float salario;
    Universidade universidade;

};

int main (void)
{
    Professor p1 ("Fulano", 1234567891, 1100.50, "Universidade Federal de São Carlos", "UFSCAR");
    p1.imprime();

}