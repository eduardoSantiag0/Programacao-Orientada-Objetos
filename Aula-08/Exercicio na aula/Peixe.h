#ifndef PEIXE_H
#define PEIXE_H

#include "Animal.h"

using namespace std;

class Peixe : public Animal
{
private:
    string habitat;
public:
    Peixe (string nome, double peso, string habitat);
    ~Peixe();
    // string getHabitat();
    // void setHabitat();
    virtual string getEspecie() const;
    void imprime();

};


#endif