#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int tentativas = 5;
void msgBemVindo();
string dadosPlayer();
int dificuldade();
int sorteiaNumero();
void limparTela();
int pedeNumero();
bool verificaAcertou();
void loopGame();
void ganhou();
void perdeu();
int pontuacao();

int main()
{
    loopGame();
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
    return nome;
}

int dificuldade(string nome)
{
    int dificuldade;
    cout << "Ola " << nome << endl;
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

int sorteiaNumero(int dificuldade)
{
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

int pedeNumero(int limiteTentativa)
{
    int numeroDigitado;
    cout << "Tentativa " << limiteTentativa << " de 5" << endl;
    cout << "Digite um numero: " << endl;
    cin >> numeroDigitado;

    cout << "O numero digitado foi: " << numeroDigitado << endl;
    return numeroDigitado;
}

bool verificaAcertou(int numeroDigitado, int numeroSecreto)
{
    if (numeroDigitado == numeroSecreto)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ganhou(string nome)
{
    cout << "Parabens " << nome << " voce ganhou o jogo!!!" << endl;
}

void perdeu(string nome)
{
    cout << "Sinto muito " << nome << " voce perdeu o jogo!!!" << endl;
}

void loopGame()
{
    msgBemVindo();
    string nome = dadosPlayer();
    limparTela();
    int dificuladade = dificuldade(nome);
    int numeroSorteado = sorteiaNumero(dificuladade);
    limparTela();

    int limiteTentativa = 0;
    int numeroDigitado;

    for (int i = 0; i < tentativas; i++)
    {
        limiteTentativa++;
        numeroDigitado = pedeNumero(limiteTentativa);
        if (numeroDigitado < numeroSorteado)
        {
            cout << "O numero sortado e maior" << endl;
        }
        else if (numeroDigitado > numeroSorteado)
        {
            cout << "O numero sortado e menor" << endl;
        }
        cout << endl << endl << endl << endl << endl;

        if (verificaAcertou(numeroDigitado, numeroSorteado))
        {
            ganhou(nome);
            break;
        }
    }

    if (!verificaAcertou(numeroDigitado, numeroSorteado))
    {
        perdeu(nome);
    }
}
