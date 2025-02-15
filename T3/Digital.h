#ifndef DIGITAL_H
#define DIGITAL_H
#include "Jogo.h"

class Digital: public Jogo{

    public:
       Digital(string nome, string genero, float preco, string plataforma);
        virtual ~Digital();
        // void Setnome(string nome);
        // void Setgenero(string genero);
        // void Setpreco(float preco);
        // void Setplataforma(string plataforma);
        // string Getnome()const;
        // string Getgenero()const;
        // float Getpreco()const;

        string getPlataforma()const;
        void setPlataforma(string plataforma);
        void imprime()const;

        int getTipo() const override;



    private:
        // string nome, genero;
        string plataforma;
        // float preco;
};

#endif 
