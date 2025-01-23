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
    cout << "   ";
    for(int i = 1; i <= this->colunas; i++){
        cout << " " << i << "  ";
    }
    cout << endl;

    for (int i = 0; i < this->linhas; i++)
    {
        cout << (i+1);
        cout << " | ";
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

    return true;
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

    return true;
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

    return true;
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

    return true;
}

Cor Tabuleiro::getCorUltimaJogada(){
    return this->corUltimaJogada;
}

int Tabuleiro::getQuantidadeLinhas(){
  return linhas;
}

int Tabuleiro::getQuantidadeColunas(){
  return colunas;
}

vector<vector<Cor>> Tabuleiro::getTabuleiro(){
  return tabuleiro_;
}
vector<vector<Cor>>& Tabuleiro::getTabuleiroRef(){
  return tabuleiro_;
}
