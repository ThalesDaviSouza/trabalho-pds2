#include <iostream>
#include "./../../include/tabuleiros/tabuleiro.hpp"

using namespace std;

Tabuleiro_JogoDaVelha::Tabuleiro_JogoDaVelha() : Tabuleiro(COLUNAS_VELHA, LINHAS_VELHA) {};

bool Tabuleiro_JogoDaVelha::verificarJogada(int linha, int coluna, Cor cor)
{
  if (this->posicaoEhValida(linha, coluna) && tabuleiro_[linha][coluna] == Vazio){
    return true;
  }
  else{
    return false;
  }
}

void Tabuleiro_JogoDaVelha::fazerJogada(int linha, int coluna, Cor cor) {
  if(this->verificarJogada(linha, coluna, cor)){
    tabuleiro_[linha][coluna] = cor;

    linhaUltimaJogada = linha;
    colunaUltimaJogada = coluna;
    corUltimaJogada = cor;
  }
}

bool Tabuleiro_JogoDaVelha::verificarVitoria()
{
  int countVazios = 0;
  // Ler o tabuleiro inteiro para validar se houve vitória ou não
    for(int linha = 0; linha < this->linhas; linha++){
      for(int coluna = 0; coluna < this->colunas; coluna++){
        
        if(tabuleiro_[linha][coluna] == Vazio){
          countVazios++;
          continue;
        }

        if(verificarHorizontal(linha, coluna, QTD_VITORIA_VELHA)){
          return true;
        }
        else if(verificarBaixo(linha, coluna, QTD_VITORIA_VELHA)){
          return true;
        }
        else if(verificarDiagonalBaixo(linha, coluna, QTD_VITORIA_VELHA)){
          return true;
        }
        else if(verificarDiagonalCima(linha, coluna, QTD_VITORIA_VELHA)){
          return true;
        }
      }
    }

    if(countVazios == 0){
      throw runtime_error("Deu velha");
    }
    // Se nenhuma vitória foi encontrada
    return false;
}