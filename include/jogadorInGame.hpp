#ifndef JOGADORINGAME_H
#define JOGADORINGAME_H

#include "./jogador.hpp"
#include "./../Enums/Cor.cpp"

class JogadorInGame{
private:
  Jogador jogador;
  Cor cor;

public:
  /**
   * @brief Construtor padrão da classe.
   * 
   * @param jogador Jogador que está jogando.
   * @param cor Cor que o Jogador selecionou para o jogo.
   */
  JogadorInGame(Jogador& jogador, Cor cor) : jogador(jogador), cor(cor) {};

  /**
   * @brief Retorna o Jogador.
   */
  Jogador getJogador();

  /**
   * @brief Retorna a cor que o Jogador selecionou.
   */
  Cor getCor();
  void setCor(Cor cor);
};

#endif