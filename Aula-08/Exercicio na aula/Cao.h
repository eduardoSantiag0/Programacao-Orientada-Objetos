#ifndef CAO_H
#define CAO_H

#include "Animal.h"

using namespace std;

class Cao : public Animal 
{
private:
    string raca;
public:
    Cao (string nome, double peso, string raca);
    virtual ~Cao();
    // string getRaca();
    // void setRaca();
    virtual string getEspecie() const;
    virtual void imprime();

};

#endif