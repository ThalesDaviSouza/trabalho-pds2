#include "./../third-party/doctest.h"
#include "./../../include/tabuleiros/tabuleiro.hpp"

#include <iostream>

TEST_SUITE("Validar vitória"){
  TEST_CASE("Vitoria diagonal secundaria"){
    Tabuleiro_JogoDaVelha tab;
      
    tab.fazerJogada(0, 2, X);
    tab.fazerJogada(1, 1, X);
    tab.fazerJogada(2, 0, X);

    CHECK(tab.verificarVitoria());
  }

  TEST_CASE("Vitoria diagonal principal"){
    Tabuleiro_JogoDaVelha tab;
      
    tab.fazerJogada(0, 0, X);
    tab.fazerJogada(1, 1, X);
    tab.fazerJogada(2, 2, X);

    CHECK(tab.verificarVitoria());
  }

  TEST_CASE("Vitoria linha horizontal"){
    Tabuleiro_JogoDaVelha tab;
      
    tab.fazerJogada(2, 0, O);
    tab.fazerJogada(2, 1, O);
    tab.fazerJogada(2, 2, O);

    CHECK(tab.verificarVitoria());
  }

  TEST_CASE("Vitoria linha vertical"){
    Tabuleiro_JogoDaVelha tab;
      
    tab.fazerJogada(0, 1, O);
    tab.fazerJogada(1, 1, O);
    tab.fazerJogada(2, 1, O);

    CHECK(tab.verificarVitoria());
  }
}