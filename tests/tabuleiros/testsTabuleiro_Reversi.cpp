#include "./../third-party/doctest.h"
#include "./../../include/tabuleiros/tabuleiro.hpp"

#include <iostream>

TEST_SUITE("Validar jogada"){
  TEST_CASE("Tem peca a esquerda"){
    Tabuleiro_Reversi tab;
      
    CHECK(tab.verificarJogada(3, 5, Preto));
  }
  
  TEST_CASE("Tem peca a direita"){
    Tabuleiro_Reversi tab;
      
    CHECK(tab.verificarJogada(4, 2, Preto));
  }
  
  TEST_CASE("Tem peca a direita esta Vazia"){
    Tabuleiro_Reversi tab;
      
    CHECK_FALSE(tab.verificarJogada(4, 1, Preto));
  }
  
  TEST_CASE("Tem peca a esquerda esta Vazia"){
    Tabuleiro_Reversi tab;
      
    CHECK_FALSE(tab.verificarJogada(3, 6, Preto));
  }
  
  TEST_CASE("Tem peca a baixo"){
    Tabuleiro_Reversi tab;
      
    CHECK(tab.verificarJogada(2, 4, Preto));
  }
  
  TEST_CASE("Tem peca a baixo e esta Vazio logo abaixo"){
    Tabuleiro_Reversi tab;
      
    CHECK_FALSE(tab.verificarJogada(1, 4, Preto));
  }
  TEST_CASE("Tem peca a cima"){
    Tabuleiro_Reversi tab;
      
    CHECK(tab.verificarJogada(5, 3, Preto));
  }
  
  TEST_CASE("Tem peca a cima e esta Vazio logo acima"){
    Tabuleiro_Reversi tab;
      
    CHECK_FALSE(tab.verificarJogada(6, 3, Preto));
  }
  
  TEST_CASE("Tem peca na diagonal da esquerda para cima"){
    Tabuleiro_Reversi tab;
    tab.fazerJogada(4, 5, Branco);

    CHECK(tab.verificarJogada(5, 5, Preto));
  }
  
  TEST_CASE("Tem peca na diagonal da direita para baixo"){
    Tabuleiro_Reversi tab;
    
    tab.fazerJogada(3, 2, Branco);

    CHECK(tab.verificarJogada(2, 2, Preto));
  }
  
  TEST_CASE("Tem peca na diagonal da esquerda para baixo"){
    Tabuleiro_Reversi tab;
    
    tab.fazerJogada(2, 4, Preto);

    CHECK(tab.verificarJogada(2, 5, Branco));
  }
  
  TEST_CASE("Tem peca na diagonal da direita para cima"){
    Tabuleiro_Reversi tab;
      
    tab.fazerJogada(5, 3, Preto);

    CHECK(tab.verificarJogada(5, 2, Branco));
  }

}