#ifndef JOGADORINGAME_H
#define JOGADORINGAME_H

#include "./jogador.hpp"
#include "./../Enums/Cor.cpp"

class JogadorInGame{
private:
  Jogador jogador;
  Cor cor;

public:
  JogadorInGame(Jogador& jogador, Cor cor) : jogador(jogador), cor(cor) {};
  Jogador getJogador();
  Cor getCor();
};

#endif