#ifndef TABULEIRO_H
#define TABULEIRO_H
#include "Jogo.h"


class Tabuleiro: public Jogo{

    public:
       Tabuleiro(string nome, string genero, float preco, string material);
        virtual ~Tabuleiro();
        // void Setnome(string nome);
        // void Setgenero(string genero);
        // void Setpreco(float preco);
        // string Getnome()const;
        // string Getgenero()const;
        // float Getpreco()const;
        void SetMaterial(string material);
        string Getmaterial()const;
        void imprime()const;
        int getTipo()const override;


    private:
        // string nome, genero, material;
        // float preco;
        string material;
};

#endif 

