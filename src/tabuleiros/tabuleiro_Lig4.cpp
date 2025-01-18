#include <iostream>
#include "./../../include/tabuleiros/tabuleiro.hpp"

using namespace std;

Tabuleiro_Lig4::Tabuleiro_Lig4() : Tabuleiro(COLUNAS_LIG4, LINHAS_LIG4) {};

bool Tabuleiro_Lig4::verificarJogada(int /*linha*/, int coluna, Cor cor) 
{
    /* REGRAS
    -o tabuleiro é preenchido de cima para baixo
    -se uma peça foi colocada embaixo, a outra vai em cima
    -só podem em espaços vazios
    */

    // verifica se a jogada foi feita nos limites do tabuleiro
    if (coluna < 0 || coluna >= COLUNAS_LIG4)
    {
        throw invalid_argument("jogada invalida");
    }

    // verifica qual a posição disponível na coluna escolhida
    for (int i = (LINHAS_LIG4-1); i >= 0; i--)
    {
        if (tabuleiro_[i][coluna] == Vazio)
            return true;
    }

    return false;

}

int Tabuleiro_Lig4::getLinhaVazia(int coluna){
    for(int i = (LINHAS_LIG4-1); i >= 0; i--){
        if(tabuleiro_[i][coluna] == Vazio){
            return i;
        }
    }

    throw invalid_argument("Essa coluna esta cheia");
}

void Tabuleiro_Lig4::fazerJogada(int /* linha */, int coluna, Cor cor)
{
    fazerJogada(coluna, cor);
};

void Tabuleiro_Lig4::fazerJogada(int coluna, Cor cor)
{
    int linha = 0;
    if (verificarJogada(0, coluna, cor))
    {
        linha = getLinhaVazia(coluna);
        tabuleiro_[linha][coluna] = cor;

        linhaUltimaJogada = linha;
        colunaUltimaJogada = coluna;
        corUltimaJogada = cor;
    }
    else{
        throw invalid_argument("Essa coluna esta cheia");
    }
};

bool Tabuleiro_Lig4::verificarVitoria() 
{   
    // Ler o tabuleiro inteiro para validar se houve vitória ou não
    for(int linha = 0; linha < this->linhas; linha++){
        for(int coluna = 0; coluna < this->colunas; coluna++){
            
            if(tabuleiro_[linha][coluna] == Vazio) continue;

            if(verificarHorizontal(linha, coluna, QTD_VITORIA_LIG4)){
                return true;
            }
            else if(verificarBaixo(linha, coluna, QTD_VITORIA_LIG4)){
                return true;
            }
            else if(verificarDiagonalBaixo(linha, coluna, QTD_VITORIA_LIG4)){
                return true;
            }
            else if(verificarDiagonalCima(linha, coluna, QTD_VITORIA_LIG4)){
                return true;
            }
        }
    }
   
    // Se nenhuma vitória foi encontrada
    return false;
}