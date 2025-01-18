#include <iostream>
#include "./../../include/tabuleiro.hpp"

using namespace std;

Tabuleiro::Tabuleiro(int colunas_, int linhas_)
{
    this->colunas = colunas_;
    this->linhas = linhas_;

    tabuleiro_ = vector<vector<Cor>>(linhas, vector<Cor>(colunas));
}

void Tabuleiro::printTabuleiro()
{
    for (int i = 0; i < this->linhas; i++)
    {
        for (int j = 0; j < this->colunas; j++)
        {
            cout << tabuleiro_[i][j] << " ";
        }
        cout << endl;
    }
};

bool foraDoLimite(int x, int max)
{
    return (x < 0 || x >= max);
}

bool Tabuleiro::verificarJogada(int x, int y, Cor cor)
{
    // verificar se jogada está nos limites do tabuleiro
    if (foraDoLimite(x, this->linhas) || foraDoLimite(y, this->colunas))
    {
        return false;
    }
    
    // verificar se o espaço está disponível
    if (x != Nenhuma || y != Nenhuma)
    {
        return false;
    }

    // jogada permitida
    return true;
};

void Tabuleiro::fazerJogada(int x, int y, Cor cor)
{
    if (verificarJogada(x, y, cor))
    {
        tabuleiro_[x][y] = cor;
    }
}
