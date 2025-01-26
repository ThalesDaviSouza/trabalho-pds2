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
  
  Cor solicitarCorJogador(string mensagemSelecao);
  void JogarJogoDaVelha();
  void JogarLig4();
  void JogarReversi();
  void imprimirJogadores();
  void selecionarJogador();
  void removerTodosJogadores();
  int getQuantidadeJogadores();
  void removerJogadorPartida(string apelido);
  void adicionarJogador(Jogador& jogador, Cor cor);

};

#endif