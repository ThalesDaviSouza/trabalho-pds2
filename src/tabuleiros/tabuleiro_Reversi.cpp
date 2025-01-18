#include <iostream>
#include <map>
#include "./../../include/tabuleiros/tabuleiro.hpp"

using namespace std;

Tabuleiro_Reversi::Tabuleiro_Reversi() : Tabuleiro(COLUNAS_REVERSI, LINHAS_REVERSI) {
  int linhaInicialCentro = (LINHAS_REVERSI/2) - 1;
  int colunaInicialCentro = (COLUNAS_REVERSI/2) - 1;

  tabuleiro_[linhaInicialCentro][colunaInicialCentro] = Preto;
  tabuleiro_[linhaInicialCentro+1][colunaInicialCentro] = Branco;
  tabuleiro_[linhaInicialCentro+1][colunaInicialCentro+1] = Preto;
  tabuleiro_[linhaInicialCentro][colunaInicialCentro+1] = Branco;

};

bool Tabuleiro_Reversi::formaLinhaHorizontal(int linha, int coluna, Cor cor){
  // Valida para direita
  int contador = 0;

  for(int colunaAtual = (coluna + 1); colunaAtual < this->linhas; colunaAtual++){
    bool ehPosicaoValida = this->posicaoEhValida(linha, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linha][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }
  
  // Valida para esquerda
  contador = 0;

  for(int colunaAtual = (coluna - 1); colunaAtual < this->linhas; colunaAtual--){
    bool ehPosicaoValida = this->posicaoEhValida(linha, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linha][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }

  return false;
}

bool Tabuleiro_Reversi::formaLinhaVertical(int linha, int coluna, Cor cor){
  // Valida para cima
  int contador = 0;

  for(int linhaAtual = (linha + 1); linhaAtual < this->linhas; linhaAtual++){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, coluna);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][coluna];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }
  
  // Valida para baixo
  contador = 0;

  for(int linhaAtual = (linha - 1); linhaAtual < this->linhas; linhaAtual--){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, coluna);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][coluna];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }

  return false;
}

bool Tabuleiro_Reversi::formaLinhaDiagonal(int linha, int coluna, Cor cor){
  // Valida diagonal direita para baixo
  int contador = 0;

  for(int linhaAtual = (linha + 1), colunaAtual = (coluna + 1); linhaAtual < this->linhas; linhaAtual++, colunaAtual++){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }
  
  // Valida diagonal direita para cima
  contador = 0;

  for(int linhaAtual = (linha - 1), colunaAtual = (coluna + 1); linhaAtual < this->linhas; linhaAtual--, colunaAtual++){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }
  
  // Valida diagonal esquerda para cima
  contador = 0;

  for(int linhaAtual = (linha - 1), colunaAtual = (coluna - 1); linhaAtual < this->linhas; linhaAtual--, colunaAtual--){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }
  
  // Valida diagonal esquerda para baixo
  contador = 0;

  for(int linhaAtual = (linha + 1), colunaAtual = (coluna - 1); linhaAtual < this->linhas; linhaAtual++, colunaAtual--){
    bool ehPosicaoValida = this->posicaoEhValida(linhaAtual, colunaAtual);

    if(ehPosicaoValida){
      Cor corPosicaoAtual = tabuleiro_[linhaAtual][colunaAtual];

      if(corPosicaoAtual == Vazio){
        break;
      }
      else if(corPosicaoAtual == cor && contador == 0){
        break;
      }
      else if(corPosicaoAtual == cor && contador > 0){
        return true;
      }
      else if(corPosicaoAtual != cor){
        contador++;
      }
    }
  }

  return false;
}


bool Tabuleiro_Reversi::verificarJogada(int linha, int coluna, Cor cor)
{
  if (this->posicaoEhValida(linha, coluna) && tabuleiro_[linha][coluna] == Vazio){
    if(formaLinhaVertical(linha, coluna, cor)){
      return true;
    }
    else if(formaLinhaHorizontal(linha, coluna, cor)){
      return true;
    }
    else if(formaLinhaDiagonal(linha, coluna, cor)){
      return true;
    }
  }

  return false;
}

void Tabuleiro_Reversi::fazerJogada(int linha, int coluna, Cor cor) {
  if(this->verificarJogada(linha, coluna, cor)){
    tabuleiro_[linha][coluna] = cor;

    linhaUltimaJogada = linha;
    colunaUltimaJogada = coluna;
    corUltimaJogada = cor;

    if(formaLinhaHorizontal(linha, coluna, cor)){
      int colunaAtual = coluna-1;
      Cor corAtual = tabuleiro_[linha][colunaAtual];
      
      // Para Esquerda
      while(posicaoEhValida(linha, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linha][colunaAtual] = cor;
        colunaAtual--;
        corAtual = tabuleiro_[linha][colunaAtual];
      }
      
      // Para Direita
      colunaAtual = coluna+1;
      corAtual = tabuleiro_[linha][colunaAtual];
      while(posicaoEhValida(linha, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linha][colunaAtual] = cor;
        colunaAtual++;
        corAtual = tabuleiro_[linha][colunaAtual];
      }
    }
    
    if(formaLinhaVertical(linha, coluna, cor)){
      int linhaAtual = linha-1;
      Cor corAtual = tabuleiro_[linhaAtual][coluna];
      
      // Para cima
      while(posicaoEhValida(linhaAtual, coluna) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][coluna] = cor;
        linhaAtual--;
        corAtual = tabuleiro_[linhaAtual][coluna];
      }
      
      // Para baixo
      linhaAtual = linha+1;
      corAtual = tabuleiro_[linhaAtual][coluna];
      while(posicaoEhValida(linhaAtual, coluna) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][coluna] = cor;
        linhaAtual++;
        corAtual = tabuleiro_[linhaAtual][coluna];
      }
    }
    
    if(formaLinhaDiagonal(linha, coluna, cor)){
      int linhaAtual = linha-1;
      int colunaAtual = coluna-1;
      Cor corAtual = tabuleiro_[linhaAtual][coluna];
      
      // Diagonal esquerda para cima
      while(posicaoEhValida(linhaAtual, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][colunaAtual] = cor;
        linhaAtual--;
        colunaAtual--;
        corAtual = tabuleiro_[linhaAtual][colunaAtual];
      }
      
      // Para direita para baixo
      linhaAtual = linha+1;
      colunaAtual = coluna+1;
      corAtual = tabuleiro_[linhaAtual][colunaAtual];
      
      while(posicaoEhValida(linhaAtual, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][colunaAtual] = cor;
        linhaAtual++;
        colunaAtual++;
        corAtual = tabuleiro_[linhaAtual][colunaAtual];
      }

      // Para esquerda para baixo
      linhaAtual = linha+1;
      colunaAtual = coluna-1;
      corAtual = tabuleiro_[linhaAtual][colunaAtual];
      
      while(posicaoEhValida(linhaAtual, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][colunaAtual] = cor;
        linhaAtual++;
        colunaAtual--;
        corAtual = tabuleiro_[linhaAtual][colunaAtual];
      }
      
      // Para esquerda para cima
      linhaAtual = linha-1;
      colunaAtual = coluna+1;
      corAtual = tabuleiro_[linhaAtual][colunaAtual];
      
      while(posicaoEhValida(linhaAtual, colunaAtual) && corAtual != cor && corAtual != Vazio){
        tabuleiro_[linhaAtual][colunaAtual] = cor;
        linhaAtual--;
        colunaAtual++;
        corAtual = tabuleiro_[linhaAtual][colunaAtual];
      }
    }

  }
}

bool Tabuleiro_Reversi::verificarVitoria(){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      if(tabuleiro_[i][j] == Vazio){
        return false;
      }
    }
  }

  return true;
}

pair<Cor, int> Tabuleiro_Reversi::retornarGanhador()
{
  map<Cor, int> quantidadePecas;
  Cor corAtual = Vazio;

  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      corAtual = tabuleiro_[i][j];

      if(corAtual != Vazio){
        // Se já existir no map
        if(quantidadePecas.find(corAtual) != quantidadePecas.end()){
          quantidadePecas[corAtual]++;
        }
        else{
          quantidadePecas.insert(make_pair(corAtual, 1));
        }
      }
    }
  }

  int aux = 0;
  pair<Cor, int> maioQuantidade;

  for(auto& par : quantidadePecas){
    if(aux == 0 || par.second > maioQuantidade.second){
      maioQuantidade.first = par.first;
      maioQuantidade.second = par.second;

      if(aux == 0){
        aux++;
      }
    }
  }

  return maioQuantidade;
}