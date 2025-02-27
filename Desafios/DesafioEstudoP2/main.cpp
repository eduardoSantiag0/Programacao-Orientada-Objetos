#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

template<typename T>
class Player
{
private:
    string nome;
    T score;
public: 
    Player(string nome, T score) : nome(nome),  score(score) 
    {}

    string getNome() const { return this->nome;};

    T getScore() const { return this->score;};

    static bool compararPontuacao(const Player& p1, const Player& p2) 
    {
        return p1.score > p2.score;
    }

    friend ostream& operator<< (ostream& o, const Player<T>& p)
    {
        return o << p.nome << " -> " << p.score << endl;
    }
    
    friend T operator+(const Player<T>& p1, const Player<T>& p2) 
    {
        return p1.score + p2.score;   
    }
    
}
;




int main (void)
{

    Player p1 ("Joao", 1000);
    Player p2 ("Maria", 100);
    Player p3 ("Fernando", 500);

    vector<Player<float>> players = {
        {"Joao", 1000.5},
        {"Maria", 100.1},
        {"Fernando", 500.2}
    };

    for (auto& p : players) {
        cout << p;
    }
    cout << players[0] + players[1] << endl;

    sort(players.begin(), players.end(), Player<float>::compararPontuacao);


    cout << endl;
    for (auto& p : players) {
        cout << p;
    }

    cout << players[0] + players[1] << endl;

    return 0;
}