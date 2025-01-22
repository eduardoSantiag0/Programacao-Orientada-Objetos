/*******************************************************************/
/*              Eduardo Santiago Rosalin - 802539                  */
/*                                ._                               */
/*                               |* ;                              */
/*             `*-.              |"":                              */
/*              \  \             |""                               */
/*               .  \            |   :                             */
/*               `   \           |                                 */
/*                \   \          |    ;               +.           */
/*                 .   \         |                   *._`-.        */
/*                 `    \        |     :          .-*'  `. `.      */
/*                 _\    \.__..--**--...L_   _.-*'      .'`*'      */
/*                /  `*-._\   -.       .-*"*+._       .'           */
/*               :        ``*-._*.     \      _J.   .'             */
/*           .-*'`*-.       ;     `.    \    /   `.'               */
/*       .-*'  _.-*'.     .-'       `-.  `-.:   _.'`-.             */
/*    +*' _.-*'      `..-'             `*-. `**'      `-.          */
/*     `*'          .-'      ._            `*-._         `.        */
/*               .-'         `.`-.____..+-**""'         .*"`.      */
/*          ._.-'          _.-*'':$$$;._$              /     `.    */
/*       .-'  `.      _.-*' `*-.__      `"**--..__    :        `.  */
/* .'..-'       \_.-*'                            `"**--..___.-*'  */
/* `. `.    _.-*'                                                  */
/*   `. `:*'                                                       */
/*     `. `.                                                       */
/*       `*                                                        */
/*******************************************************************/


#include <iostream>

using namespace std;

namespace poo
{
    class Pessoa
    {
    private:
        string nome;
        string cpf;
        
    public:
        Pessoa(string nome, string cpf) : nome(nome), cpf(cpf){};
        virtual ~Pessoa() {};
        string getCPF() const { return this->cpf;};
        string getNome() const { return this->nome;};
        
        virtual void imprime() const 
        {
            cout << "Nome: " << this->nome << endl;
            cout << "CPF: " << this->cpf << endl; 
        };
    };



    class Estudante : public Pessoa 
    {
    private:
        int ra;
        double prova1, prova2;
        double trabalho1, trabalho2;

        bool sac() const
        {
            return this->media() >= 5.5 && this->media() < 6; 
        }

    public: 
        Estudante(string nome, string cpf, int ra, double prova1, double prova2, 
        double trabalho1, double trabalho2) 
        : Pessoa(nome, cpf), ra(ra), prova1(prova1), prova2(prova2), 
        trabalho1(trabalho1), trabalho2(trabalho2) {};

        int getRA () const { return this->ra;};

        double media() const
        {
            double mp = (this->prova1 + this->prova2) / 2.0;
            double mt = (this->trabalho1 + this->trabalho2) / 2.0;
            return (mp * 8 + mt * 2) / 10.0;
        }

        bool aprovado() const
        {
            return this->media() >= 6.0;
        }


        double notaSAC()
        {
            if (this->sac()) return 12 - this->media();
            else return 0.0;
        }


        void imprime() const override
        {
            Pessoa::imprime();
            cout << "Media: " << this->media() << endl;
        }
    };


    class Professor : public Pessoa
    {
    private:
        string universidade;
    public: 
        Professor(string nome, string cpf, string universidade) 
        : Pessoa(nome, cpf), universidade(universidade){};
        
        string getUniversidade() const { return this->universidade;};

        void imprime() const override
        {
            Pessoa::imprime();
            cout << "Universidade: " << getUniversidade() << endl;
        }
    };


    class DataHorario {
    private: 
        int dia, mes, ano, hora, minuto, segundo;

        bool validarData(int dia, int mes, int ano) 
        {
            return ano > 0 && mes >= 1 && mes <= 12 && dia >= 1;
        }

        bool validarHorario (int hora, int min, int seg) 
        {
            return hora >= 0 && hora <= 23 
            && minuto >= 0 && minuto <= 59 
            && segundo >= 0 && segundo <= 59;    
        }

    public: 


        DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) 
        : dia(1), mes(1), ano(1), hora(0), minuto(0), segundo(0) 
        {
            if (validarData(dia, mes, ano) && validarHorario(hora, minuto, segundo)) 
            {
                this->dia = dia;
                this->mes = mes;
                this->ano = ano;
                this->hora = hora;
                this->minuto = minuto;
                this->segundo = segundo;
            } 
        }

        DataHorario() {}

        ~DataHorario() {}


        int getDia() const { return dia; }
        int getMes() const { return mes; }
        int getAno() const { return ano; }
        int getHora() const { return hora; }
        int getMinuto() const { return minuto; }
        int getSegundo() const { return segundo; }

        void imprime(bool formato12hrs) const 
        {
            if (formato12hrs) {
                int horaAtualizada = this->hora % 12;
                if (horaAtualizada == 0) horaAtualizada = 12;
                string periodo = (hora < 12 ? "AM" : "PM");

                printf("%d/%d/%d - %d:%d:%d %s\n", this->dia, this->mes, this->ano, 
                horaAtualizada, this->minuto, this->segundo, periodo.c_str());
                
            } else {
                printf("%d/%d/%d - %d:%d:%d\n", this->dia, this->mes, this->ano, 
                this->hora, this->minuto, this->segundo);
            }
        }

        void imprimePorExtenso() const
        {
            string mes;
            switch (this->mes)
            {
                case 1: mes = "Janeiro"; break;
                case 2: mes = "Fevereiro"; break;
                case 3: mes = "Março"; break;
                case 4: mes = "Abril"; break;
                case 5: mes = "Maio"; break;
                case 6: mes = "Junho"; break;
                case 7: mes = "Julho"; break;
                case 8: mes = "Agosto"; break;
                case 9: mes = "Setembro"; break;
                case 10: mes = "Outubro"; break;
                case 11: mes = "Novembro"; break;
                case 12: mes = "Dezembro"; break;
                default: break;
            }

            cout << this->dia << " de " << mes << " de " << this->ano << " - " 
            << this->hora << " horas, " << minuto << " minutos  e "<< this->segundo << " segundos" << endl; 
        }
    };

    
    class Sessao
    {
    private:
        string nome;
        DataHorario data;
        static constexpr int TAM_MAX = 210;
        Pessoa* poltronas[TAM_MAX];

        /**
         * @param s recebe uma string no formato [A-O][1-14]
         * 
         * @return posição equivalente no vetor poltronas
         */
        int converte(string s) const 
        {
            int linha = s[0] - 'A'; // s[0] é a 1a letra da string [A-0]
            // A função stoi converte de string para int.
            // [stoi] string => int (substring formada apenas pela 2a letra)
            int coluna = stoi(s.substr(1)) - 1;
            return linha * 14 + coluna;
        }


        /**
         * @param recebe um integer que corresponde a uma poltrona
         * 
         * @return posição equivalente em string no formato [A-O][1-14]
         */
        string convertePoltronaString(int pos) const 
        {
            char linha = 'A' + pos / 14;
            int coluna = (pos % 14) + 1;
            return string(1, linha) + to_string(coluna);
        }


    public:
        Sessao(string nome, DataHorario& data) : nome(nome), data(data) 
        {
            for (int i = 0; i < TAM_MAX; i++) poltronas[i] = nullptr;
        };

        ~Sessao() 
        {
            for (int i = 0; i < TAM_MAX; ++i) delete poltronas[i]; 
        };

        bool verifica(string poltrona) const 
        {
            int pos = converte(poltrona);
            if (pos >= TAM_MAX || pos < 0) return false;
            return poltronas[pos] != nullptr;
        }

        string proximoLivre() 
        {
            for (int i = 0; i < TAM_MAX; i++) {
                if (poltronas[i] == nullptr) {
                    return convertePoltronaString(i);
                }
            }
            return "CHEIO";
        }

        bool ocupa(string poltrona, Pessoa& pessoa) 
        {
            if (verifica(poltrona))  
            {
                cout << "Poltrona ocupada." << endl;
                return false;
            }

            int pos = converte(poltrona);
            poltronas[pos] = &pessoa;
            return true;
        }

        bool desocupa(string poltrona) 
        {
            if (!verifica(poltrona)) return false;
            int pos = converte(poltrona);
            poltronas[pos] = nullptr;
        }

        int vagas() const 
        {
            int contador =0;
            for (int i = 0; i < TAM_MAX; i++) {
                if (poltronas[i] != nullptr) {
                    contador++;
                }
            }
            return contador;
        }

        void imprime() const 
        {
            cout << "Nome da Sessão: " << this->nome << endl;
            bool formato12hrs = false;
            data.imprime(formato12hrs);

            for (int i = 0; i < TAM_MAX; i++) {
                if (poltronas[i] != nullptr) {
                    cout << endl;
                    cout << "Poltrona: " << convertePoltronaString(i) << endl;
                    poltronas[i]->imprime();
                    cout << endl;
                }
            }

        }


    };
    
}