#ifndef EBOOK_H
#define EBOOK_H

#include "Produto.h"

class EBook : public Produto {
public:
    EBook(string, float, int, string);
    virtual ~EBook();
    virtual void imprime() const;
    virtual char getTipo() const;

    bool static compara(const EBook* e1, const EBook* e2);
private:
    string autor;
};

#endif /* EBOOK_H */

