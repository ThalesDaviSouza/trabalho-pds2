#include <iostream>
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

bool Tabuleiro_Reversi::formaLinhaHorizontalDireita(int linha, int coluna, Cor cor){
  int contador = 0;

  for(int colunaAtual = (coluna + 1); colunaAtual < this->colunas; colunaAtual++){
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

bool Tabuleiro_Reversi::formaLinhaHorizontalEsquerda(int linha, int coluna, Cor cor){
  int contador = 0;

  for(int colunaAtual = (coluna - 1); colunaAtual >= 0; colunaAtual--){
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

bool Tabuleiro_Reversi::formaLinhaHorizontal(int linha, int coluna, Cor cor){
  if(formaLinhaHorizontalDireita(linha, coluna, cor)){
    return true;
  }
  else if(formaLinhaHorizontalEsquerda(linha, coluna, cor)){
    return true;
  }
  else{
    return false;
  }
}

bool Tabuleiro_Reversi::formaLinhaVerticalInferior(int linha, int coluna, Cor cor){
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
  
  return false;
}

bool Tabuleiro_Reversi::formaLinhaVerticalSuperior(int linha, int coluna, Cor cor){
  // Valida para baixo
  int contador = 0;

  for(int linhaAtual = (linha - 1); linhaAtual >= 0; linhaAtual--){
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

bool Tabuleiro_Reversi::formaLinhaVertical(int linha, int coluna, Cor cor){
  if(formaLinhaVerticalSuperior(linha, coluna, cor)){
    return true;
  }
  else if(formaLinhaVerticalInferior(linha, coluna, cor)){
    return true;
  }
  else{
    return false;
  }
}

bool Tabuleiro_Reversi::formaLinhaDiagonalDireitaInferior(int linha, int coluna, Cor cor){
  // Valida diagonal direita para baixo
  int contador = 0;

  for(int linhaAtual = (linha + 1), colunaAtual = (coluna + 1); (linhaAtual < this->linhas && colunaAtual < this->colunas); linhaAtual++, colunaAtual++){
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

bool Tabuleiro_Reversi::formaLinhaDiagonalDireitaSuperior(int linha, int coluna, Cor cor){
  // Valida diagonal direita para cima
  int contador = 0;

  for(int linhaAtual = (linha - 1), colunaAtual = (coluna + 1); (linhaAtual >= 0 && colunaAtual < this->colunas); linhaAtual--, colunaAtual++){
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

bool Tabuleiro_Reversi::formaLinhaDiagonalEsquerdaInferior(int linha, int coluna, Cor cor){
  // Valida diagonal esquerda para baixo
  int contador = 0;

  for(int linhaAtual = (linha + 1), colunaAtual = (coluna - 1); (linhaAtual < this->linhas && colunaAtual >= 0); linhaAtual++, colunaAtual--){
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

bool Tabuleiro_Reversi::formaLinhaDiagonalEsquerdaSuperior(int linha, int coluna, Cor cor){
  // Valida diagonal esquerda para cima
  int contador = 0;

  for(int linhaAtual = (linha - 1), colunaAtual = (coluna - 1); (linhaAtual >= 0 && colunaAtual >= 0); linhaAtual--, colunaAtual--){
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


bool Tabuleiro_Reversi::formaLinhaDiagonal(int linha, int coluna, Cor cor){
  if(formaLinhaDiagonalDireitaInferior(linha, coluna, cor)){
    return true;
  }
  else if(formaLinhaDiagonalDireitaSuperior(linha, coluna, cor)){
    return true;
  }
  else if(formaLinhaDiagonalEsquerdaInferior(linha, coluna, cor)){
    return true;
  }
  else if(formaLinhaDiagonalEsquerdaSuperior(linha, coluna, cor)){
    return true;
  }
  else{
    return false;
  }
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
      
      if(formaLinhaHorizontalEsquerda(linha, coluna, cor)){
        while(posicaoEhValida(linha, colunaAtual) && (corAtual != cor) && (corAtual != Vazio)){
          tabuleiro_[linha][colunaAtual] = cor;
          colunaAtual--;
          corAtual = tabuleiro_[linha][colunaAtual];
        }
      }
      
      if(formaLinhaHorizontalDireita(linha, coluna, cor)){
        // Para Direita
        colunaAtual = coluna+1;
        corAtual = tabuleiro_[linha][colunaAtual];
        while(posicaoEhValida(linha, colunaAtual) && corAtual != cor && corAtual != Vazio){
          tabuleiro_[linha][colunaAtual] = cor;
          colunaAtual++;
          corAtual = tabuleiro_[linha][colunaAtual];
        }
      }
    }
    
    if(formaLinhaVertical(linha, coluna, cor)){
      int linhaAtual = linha-1;
      Cor corAtual;

      if(formaLinhaVerticalSuperior(linha, coluna, cor)){
        corAtual = tabuleiro_[linhaAtual][coluna];
        
        // Para cima
        while(posicaoEhValida(linhaAtual, coluna) && corAtual != cor && corAtual != Vazio){
          tabuleiro_[linhaAtual][coluna] = cor;
          linhaAtual--;
          corAtual = tabuleiro_[linhaAtual][coluna];
        }
      }
      
      if(formaLinhaVerticalInferior(linha, coluna, cor)){
        // Para baixo
        linhaAtual = linha+1;
        corAtual = tabuleiro_[linhaAtual][coluna];

        while(posicaoEhValida(linhaAtual, coluna) && corAtual != cor && corAtual != Vazio){
          tabuleiro_[linhaAtual][coluna] = cor;
          linhaAtual++;
          corAtual = tabuleiro_[linhaAtual][coluna];
        }
      }
    }
    
    if(formaLinhaDiagonal(linha, coluna, cor)){
      int linhaAtual = linha-1;
      int colunaAtual = coluna-1;
      Cor corAtual;

      if(formaLinhaDiagonalEsquerdaSuperior(linha, coluna, cor)){
        corAtual = tabuleiro_[linhaAtual][colunaAtual];

        // Diagonal esquerda para cima
        while(posicaoEhValida(linhaAtual, colunaAtual) && corAtual != cor && corAtual != Vazio){
          tabuleiro_[linhaAtual][colunaAtual] = cor;
          linhaAtual--;
          colunaAtual--;
          corAtual = tabuleiro_[linhaAtual][colunaAtual];
        }
      }
      

      if(formaLinhaDiagonalDireitaInferior(linha, coluna, cor)){
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
      }


      if(formaLinhaDiagonalEsquerdaInferior(linha, coluna, cor)){
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
      }
      

      if(formaLinhaDiagonalDireitaSuperior(linha, coluna, cor)){
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
}

bool Tabuleiro_Reversi::verificarVitoria(){
  vector<pair<int, int>> espacosVazios;
  vector<Cor> coresTab;
  int qtdEspacosVazios = 0;

  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      if(tabuleiro_[i][j] == Vazio){
        espacosVazios.push_back(make_pair(i, j));
        qtdEspacosVazios++;
      }
      else{
        for(auto& cor : coresTab){
          if(cor == tabuleiro_[i][j]){
            continue;
          }
        }
        coresTab.push_back(tabuleiro_[i][j]);
      }
    }
  }

  if(qtdEspacosVazios == 0){
    return true;
  }

  for(auto& espaco : espacosVazios){
    for(auto& cor : coresTab){
      if(cor != this->getCorUltimaJogada()){
        if(verificarJogada(espaco.first, espaco.second, cor)){
          return false;
        }
      }
    }
  }

  // Se a quantidade de espaços em branco é maior que 0
  // Mas não há jogadas possíveis para cores diferentes
  // Daquela que realizou a ultima jogada
  // Então o jogo acabou
  return true;
}
