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
        cout << "Jogada fora do tabuleiro" << endl;
        return false;
    }
    // verificar se o espaço está disponível
    if (x != 0 || y != 0)
    {
        cout << "Espaço indisponível" << endl;
        return false;
    }
    // jogada permitida
    return true;
};

void Tabuleiro::fazerJogada(int x, int y, int cor)
{
    if (verificarJogada(x, y, cor))
    {
        tabuleiro_[x][y] = cor;
    }
}

// LIG4

//TODO: colocar cada tabuleiro em arquivo separado

// usar o construtor da abstrata e so passar parametros
Tabuleiro_Lig4::Tabuleiro_Lig4() : Tabuleiro(6, 7) {};

bool Tabuleiro_Lig4::verificarJogada(int x, Cor cor) //TODO: Mudar cor nos outros
{
    /* REGRAS
    o tabuleiro é preenchido de cima para baixo
    se uma peça foi colocada embaixo, a outra vai em cima
    só podem espaços vazios
    */

    // verifica se a jogada foi feita nos limites do tabuleiro
    if (y < 0 || y >= 7)
    {
        cout << "Jogada fora do tabuleiro" << endl;
        return false;
    }

    // verifica qual a posição disponível na coluna escolhida
    for (int i = 5; i >= 0; i--)
    {
        if (tabuleiro_[i][y] == 0)
            return true;
    }
   
    throw invalid_argument("jogada inválida");

    //TODO: Lançar excessão
}

void Tabuleiro_Lig4::fazerJogada(int x, int y, int cor)
{
    if (verificarJogada(x, y, cor))
    {
        tabuleiro_[x][y] = cor;
    }
};

//verificar direção
//enum igual o de cor
//norte =1
//sul=2

bool verificarVitoria(Cor tabuleiro_[6][7])//TODO: Mudar no hpp
//verificar apenas uma jogada 
{

    // Horizontal
    for (int x = 0; x < 6; x++)
    {
        int cor_igual = 0;
        Cor cor_atual = tabuleiro_[x][y];

        for (int y = 0; y < 7; y++)
        {
            if (tabuleiro_[x][y] == cor_atual && cor_atual != 0)
            {
                cor_igual++;
            }
            else
            {
                cor_atual = tabuleiro_[x][y];         // atribui cor atual ao tabuleiro
                cor_igual = (cor_atual != 0) ? 1 : 0; // ver se cor atual é diferente de 0
            }
            if (cor_igual >= 4)
            {
                return true; // jogador venceu
            }
        }

        return false; // Ninguém venceu na coluna
    }

    // vertical
    // Verificar se tem algum valor diferente de 0 na coluna
    // Se sim, verificar se ele se repete 4 vezes, se não, passar para próxima coluna e repetir até a última

    for (int y = 0; y < 7; y++)
    {
        int cor_igual = 0;
        int cor_atual = 0;

        for (int x = 5; x >= 0; x--)
            if (tabuleiro_[x][y] == cor_atual && cor_atual != 0)
            {
                cor_igual++;
            }
            else
            {
                cor_atual = tabuleiro_[x][y];         // atribui cor atual ao tabuleiro
                cor_igual = (cor_atual != 0) ? 1 : 0; // ver se cor atual é diferente de 0
            }
        if (cor_igual >= 4)
        {
            return true; // jogador venceu
        }
    }

    return false; // Ninguém venceu na coluna

    // diagonal

    

    

}
