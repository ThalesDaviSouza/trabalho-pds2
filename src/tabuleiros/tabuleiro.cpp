#include <iostream>
#include "./../../include/tabuleiros/tabuleiro.hpp"

using namespace std;

Tabuleiro::Tabuleiro(int colunas_, int linhas_)
{
    this->colunas = colunas_;
    this->linhas = linhas_;

    tabuleiro_ = vector<vector<Cor>>(linhas, vector<Cor>(colunas, Vazio));

}

void Tabuleiro::printTabuleiro()
{
    for (int i = 0; i < this->linhas; i++)
    {

        cout << "| ";
        for (int j = 0; j < this->colunas; j++)
        {
            cout << static_cast<char>(tabuleiro_[i][j]) << " | ";
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
    if (x != Vazio || y != Vazio)
    {
        return false;
    }

    // jogada permitida
    return true;
};

void Tabuleiro::fazerJogada(int linha, int coluna, Cor cor)
{
    if (verificarJogada(linha, coluna, cor))
    {
        tabuleiro_[linha][coluna] = cor;
    }

    linhaUltimaJogada = linha;
    colunaUltimaJogada = coluna;
}

int Tabuleiro::getLinhaUltimaJogada(){
    return this->linhaUltimaJogada;
}

int Tabuleiro::getColunaUltimaJogada(){
    return this->colunaUltimaJogada;
}


//Verificar horizontal para a direita
bool Tabuleiro::verificarHorizontal(int linha, int coluna, int quantParaVitoria){
    Cor cor_atual = tabuleiro_[linha][coluna];
    int contador = 0; 
    int colunaAtual;
    
    // Verificando até 4 casas
    for (int i = 0; i < quantParaVitoria; i++)
    { 
        colunaAtual = coluna + i;
        if (colunaAtual < this->colunas && tabuleiro_[linha][colunaAtual] == cor_atual)
        {
            contador++;
        }
        else
        {
            return false;
        }
    }

    if (contador >= quantParaVitoria)
        return true;
    
    return false;

}

//Verificar vertical para baixo
bool Tabuleiro::verificarBaixo(int linha, int coluna, int quantParaVitoria){
    Cor cor_atual = tabuleiro_[linha][coluna];
    int contador = 0; 
    int linhaAtual;
    
    // Verificando até 4 casas
    for (int i = 0; i < quantParaVitoria; i++)
    { 
        linhaAtual = linha + i;

        if (linhaAtual < this->linhas && tabuleiro_[linhaAtual][coluna] == cor_atual)
        {
            contador++;
        }
        else
        {
            return false;
        }
    }
    if (contador >= quantParaVitoria)
        return true;
    return false;

}

bool Tabuleiro::posicaoEhValida(int linha, int coluna){
    return (linha >= 0 && linha < this->linhas) && (coluna >= 0 && coluna < this->colunas);
}

//Verificar diagonal principal (\) para baixo e direita
bool Tabuleiro::verificarDiagonalBaixo(int linha, int coluna, int quantParaVitoria){
    Cor cor_atual = tabuleiro_[linha][coluna];
    int contador = 0; 
    int linhaAtual;
    int colunaAtual;
    
    // Verificando até 4 casas
    for (int i = 0; i < quantParaVitoria; i++)
    { 
        linhaAtual = linha + i;
        colunaAtual = coluna + i;
        
        if (posicaoEhValida(linhaAtual, colunaAtual) && tabuleiro_[linhaAtual][colunaAtual] == cor_atual)
        {
            contador++;
        }
        else
        {
            return false;
        }
    }

    if (contador >= quantParaVitoria)
        return true;
    return false;

}

//Verificar diagonal secundária (/) para cima e direita
bool Tabuleiro::verificarDiagonalCima(int linha, int coluna, int quantParaVitoria){
    Cor cor_atual = tabuleiro_[linha][coluna];
    int contador = 0; 
    int linhaAtual;
    int colunaAtual;
    
    // Verificando até 4 casas
    for (int i = 0; i < quantParaVitoria; i++)
    { 
        linhaAtual = linha - i;
        colunaAtual = coluna + i;
        
        if (posicaoEhValida(linhaAtual, colunaAtual) && tabuleiro_[linhaAtual][colunaAtual] == cor_atual)
        {
            contador++;
        }
        else
        {
            return false;
        }
    }

    if (contador >= quantParaVitoria)
        return true;
    return false;

}
