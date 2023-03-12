#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void msgBemVindo();
string dadosPlayer();
int dificuldade();
int sorteiaNumero(int dificuldade);
void limparTela();

int main()
{
    msgBemVindo();
    dadosPlayer();
    int dificuladade = dificuldade();
    int maximoNumero = sorteiaNumero(dificuladade);

    limparTela();
    cout << dificuladade << endl;
    cout << maximoNumero << endl;
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

    return dificuldade; 
}

int sorteiaNumero(int dificuldade){
    int maximoNumeros = 0;
    switch (dificuldade)
    {
    case 1:
        maximoNumeros = 20;
        break;
    case 2:
        maximoNumeros = 50;
        break;
    case 3:
        maximoNumeros = 100;
    default:
        break;
    }

    cout << "sorteando um numero secreto entre 1 e " << maximoNumeros << endl;
    unsigned seed = time(0);

    srand(seed);
    int numeroSortado = 1 + rand() % maximoNumeros;
    return numeroSortado;
}

void limparTela()
{
    cout << "\e[H\e[2J";
}


