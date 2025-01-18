#include <iostream>
#include "tabuleiro.hpp"

using namespace std;

Tabuleiro::Tabuleiro(int colunas_, int linhas_)
{
    this->colunas = colunas_;
    this->linhas = linhas_;

    tabuleiro_ = vector<vector<int>>(linhas, vector<int>(colunas, 0));
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

bool Tabuleiro::verificarJogada(int x, int y, Cor cor)
{
    // verificar se jogada está nos limites do tabuleiro
    if (x < 0 || x >= linhas || y < 0 || y >= colunas)
    {
        return false;
    }
    // verificar se o espaço está disponível
    if (x != 0 || y != 0)
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

