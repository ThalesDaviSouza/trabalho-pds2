#ifndef JOGADORINGAME_H
#define JOGADORINGAME_H

#include "./jogador.hpp"
#include "./../Enums/cor.cpp"

class JogadorInGame{
private:
  Jogador jogador;
  Cor cor;

public:
  Jogador getJogador();
  Cor getCor();
};

#endif