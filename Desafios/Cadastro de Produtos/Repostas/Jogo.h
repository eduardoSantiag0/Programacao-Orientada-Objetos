#ifndef JOGO_H
#define JOGO_H

#include "Produto.h"

class Jogo : public Produto {
public:
    Jogo(string, float, int, string);
    virtual ~Jogo();
    virtual void imprime() const;
    virtual char getTipo() const;

    bool static compara(const Jogo* j1, const Jogo* j2);
private:
    string genero;
};

#endif /* JOGO_H */

