#include "Professor.hpp"

using namespace std;

class Coordenador : public Professor
{
private:
    string curso;
public:
    Coordenador(string nome, string CPF, double salario, string curso);
    string getCurso() const;

    //? Pode colocar override?
    double getSalario() const override;
    
    void imprime() const;
};

Coordenador::Coordenador(string nome, string CPF, double salario, string curso) 
: Professor(nome, CPF, salario), curso(curso)
{
};

double Coordenador::getSalario () const 
{
    return Professor::getSalario() + 2000;
}

string Coordenador::getCurso() const { return this->curso; };