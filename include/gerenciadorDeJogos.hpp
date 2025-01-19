#ifndef GERENCIADOR_DE_JOGOS_H
#define GERENCIADOR_DE_JOGOS_H

#include <string>
#include <vector>
#include "./gerenciadorDeJogadores.hpp"
#include "./jogadorInGame.hpp"
#include "./tabuleiros/tabuleiro.hpp"

using namespace std;

class GerenciadorDeJogos {
private:
  int rodadas = 1;
  Tabuleiro* tabuleiro;
  vector<JogadorInGame> jogadores;
  GerenciadorDeJogadores& gerenciadorDeJogadores;

public:
  GerenciadorDeJogos(GerenciadorDeJogadores& gerenciadorDeJogadores);
  ~GerenciadorDeJogos();
  
  void JogarJogoDaVelha();
  void imprimirJogadores();
  void selecionarJogador();

};

#endif