#include "./third-party/doctest.h"
#include "./../include/minmax.hpp"
#include <iostream>

TEST_CASE("Minimax: dado um tabuleiro com uma jogada que pode ganhar rotornar a jogada ganhadora"){
  Tabuleiro_JogoDaVelha tab;
  Jogador jogadorAgente("IA", "IA");
  JogadorInGame agente(jogadorAgente, X);
  Jogador jogadorInimigo("INI", "INI");
  JogadorInGame inimigo(jogadorInimigo, O);

  tab.fazerJogada(0, 0, X);
  tab.fazerJogada(0, 1, X);
  pair<int, int> jogadaAgente = MinMaxNode::obterJogadaAgente(&tab, agente, inimigo);

  CHECK(jogadaAgente.first == 0);
  CHECK(jogadaAgente.second == 2);
}

TEST_CASE("Minimax: dado aonde o inimigo quase vai ganhar rotornar a jogada que ira empatar"){
  Tabuleiro_JogoDaVelha tab;
  Jogador jogadorAgente("IA", "IA");
  JogadorInGame agente(jogadorAgente, X);
  Jogador jogadorInimigo("INI", "INI");
  JogadorInGame inimigo(jogadorInimigo, O);

  tab.fazerJogada(0, 0, O);
  tab.fazerJogada(0, 1, O);
  pair<int, int> jogadaAgente = MinMaxNode::obterJogadaAgente(&tab, agente, inimigo);

  CHECK(jogadaAgente.first == 0);
  CHECK(jogadaAgente.second == 2);
}
