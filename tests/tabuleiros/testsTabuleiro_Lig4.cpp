#include "./../third-party/doctest.h"
#include "./../../include/tabuleiros/tabuleiro.hpp"

#include <iostream>

TEST_SUITE("Validar vitória"){
  TEST_CASE("Vitoria diagonal baixo"){
    Tabuleiro_Lig4 tab;
      
    tab.fazerJogada(3, Amarelo);
    tab.fazerJogada(3, Amarelo);
    tab.fazerJogada(3, Amarelo);
    tab.fazerJogada(3, Vermelho);

    tab.fazerJogada(4, Amarelo);
    tab.fazerJogada(4, Amarelo);
    tab.fazerJogada(4, Vermelho);

    tab.fazerJogada(5, Amarelo);
    tab.fazerJogada(5, Vermelho);
    tab.fazerJogada(6, Vermelho);

    CHECK(tab.verificarVitoria());
  }

  TEST_CASE("Vitoria diagonal cima"){
    Tabuleiro_Lig4 tab;
      
    tab.fazerJogada(6, Amarelo);
    tab.fazerJogada(6, Amarelo);
    tab.fazerJogada(6, Amarelo);
    tab.fazerJogada(6, Vermelho);

    tab.fazerJogada(5, Amarelo);
    tab.fazerJogada(5, Amarelo);
    tab.fazerJogada(5, Vermelho);

    tab.fazerJogada(4, Amarelo);
    tab.fazerJogada(4, Vermelho);

    tab.fazerJogada(3, Vermelho);

    CHECK(tab.verificarVitoria());
  }

  TEST_CASE("Vitoria linha horizontal"){
    Tabuleiro_Lig4 tab;

    tab.fazerJogada(3, Vermelho);
    tab.fazerJogada(4, Vermelho);
    tab.fazerJogada(5, Vermelho);
    tab.fazerJogada(6, Vermelho);

    CHECK(tab.verificarVitoria());
  }
}