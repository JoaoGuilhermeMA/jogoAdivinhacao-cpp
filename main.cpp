#include<iostream>

using namespace std;

void msgBemVindo();
string dadosPlayer();
int dificuldade();

int main()
{
    msgBemVindo();
    dadosPlayer();
    dificuldade();

}

void msgBemVindo()
{
    cout << "*****************************************" << endl;
    cout << "* Seja bem vindo ao jogo da adivinhacao *" << endl;
    cout << "*****************************************" << endl;
}

string dadosPlayer()
{
    string nome;
    cout << "Por favor digite seu nome: " << endl;
    cin >> nome;
    cout << "Ola " << nome << endl;
    return nome;
}

int dificuldade()
{
    int dificuldade;
    cout << "Esolha a dificuldade do jogo" << endl;
    cout << "1 - facil   2 - medio   3 - dificil" << endl;
    cin >> dificuldade;
    
    while (dificuldade < 1 || dificuldade > 3)
    {
        cout << "Por favor digite o numero certo!!!!!" << endl;
        cin >> dificuldade;
    }
    
    cout << dificuldade << endl;
    return dificuldade; 
}