#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>

#include "./../Enums/Jogo.cpp"

using namespace std;

class RegistroPartida{
private:
  string apelidoJogador;
  Jogo jogo;
  bool ganhou;
  int pontuacao;

public:
  RegistroPartida(string apelido, Jogo jogo, bool ganhou);
  RegistroPartida(string apelido, Jogo jogo, bool ganhou, int pontuacao);
  
  string getApelidoJogador();
  Jogo getJogo();
  bool getGanhou();
  int getPontuacao();

};


#endif