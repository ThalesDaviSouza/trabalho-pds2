#include "./third-party/doctest.h"
#include "./../include/jogadorInGame.hpp"

TEST_CASE("JogadorInGame: Dado 1 jogador recuperar o Jogador em jogo"){
  string nome = "Jogador";
  string apelido = "Jog";
  Jogador jogador(nome, apelido);
  JogadorInGame jogadorInGame(jogador, Branco);

  CHECK(jogadorInGame.getJogador().getNome() == nome);
  CHECK(jogadorInGame.getJogador().getApelido() == apelido);
}

TEST_CASE("JogadorInGame: Dado 1 cor recuperar a cor do jogador"){
  string nome = "Jogador";
  string apelido = "Jog";
  Jogador jogador(nome, apelido);
  JogadorInGame jogadorInGame(jogador, Branco);

  CHECK(jogadorInGame.getCor() == Branco);
}
