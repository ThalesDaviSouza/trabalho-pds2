#include "./../third-party/doctest.h"
#include "./../../include/tabuleiros/tabuleiro.hpp"

#include <iostream>

TEST_CASE("Tabuleiro::getCorUltimaJogada"){
  Tabuleiro_JogoDaVelha tabuleiro;
  
  tabuleiro.fazerJogada(0, 0, X);

  CHECK(tabuleiro.getCorUltimaJogada() == X);
}

TEST_CASE("Tabuleiro::getLinhaUltimaJogada"){
  Tabuleiro_JogoDaVelha tabuleiro;
  
  tabuleiro.fazerJogada(0, 0, X);
  tabuleiro.fazerJogada(1, 2, O);

  CHECK(tabuleiro.getLinhaUltimaJogada() == 1);
}

TEST_CASE("Tabuleiro::getColunaUltimaJogada"){
  Tabuleiro_JogoDaVelha tabuleiro;
  
  tabuleiro.fazerJogada(0, 0, X);
  tabuleiro.fazerJogada(2, 1, O);

  CHECK(tabuleiro.getColunaUltimaJogada() == 1);
}

TEST_CASE("Tabuleiro::getQuantidadeLinhas"){
  Tabuleiro_JogoDaVelha tabuleiro;
  int retorno = 0;

  retorno = tabuleiro.getQuantidadeLinhas();

  CHECK(retorno == LINHAS_VELHA);
}

TEST_CASE("Tabuleiro::getQuantidadeColunas"){
  Tabuleiro_JogoDaVelha tabuleiro;
  int retorno = 0;

  retorno = tabuleiro.getQuantidadeColunas();

  CHECK(retorno == COLUNAS_VELHA);
}

TEST_CASE("Tabuleiro::getTabuleiroRef"){
  Tabuleiro_JogoDaVelha tabuleiro;

  vector<vector<Cor>>& retorno = tabuleiro.getTabuleiroRef();

  CHECK(retorno == tabuleiro.getTabuleiro());
}

TEST_CASE("Tabuleiro::getTabuleiro"){
  Tabuleiro_JogoDaVelha tabuleiro;

  vector<vector<Cor>> retorno = tabuleiro.getTabuleiro();

  CHECK(retorno == tabuleiro.getTabuleiroRef());
}