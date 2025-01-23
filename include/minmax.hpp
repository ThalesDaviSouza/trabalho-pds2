#ifndef MINMAX_H
#define MINMAX_H

#include <string>

#include "./../Enums/Jogo.cpp"
#include "./tabuleiros/tabuleiro.hpp"
#include "./jogadorInGame.hpp"

using namespace std;

class MinMaxNode{
private:
  Tabuleiro* tabuleiro;
  JogadorInGame& inimigo;
  JogadorInGame& agente;
  bool vitoriaEmUmaJogada(int linha, int coluna);

public:
  MinMaxNode(Tabuleiro* tabuleiro, JogadorInGame& agente, JogadorInGame& inimigo);
  ~MinMaxNode();

  /**
   * @brief Retorna a posicao linha coluna que o agente irá jogar
   */
  static pair<int, int> obterJogadaAgente(Tabuleiro* tabuleiro, JogadorInGame& agente, JogadorInGame& inimigo);
  
  pair<int, int> melhorJogada();
  int getPesoJogada(int linha, int coluna, Cor corAgente);
  Tabuleiro* getTabuleiro();

};


#endif