#ifndef GERENCIADOR_DE_JOGADORES_H
#define GERENCIADOR_DE_JOGADORES_H

#include <string>
#include <vector>
#include "./jogador.hpp"

using namespace std;

class GerenciadorDeJogadores {
private:
  string nomeArquivo;
  string caminhoPasta;
  string caminhoArquivo;
  vector<Jogador> jogadores;

public:
  GerenciadorDeJogadores(string caminhoPasta, string nomeArquivo);
  ~GerenciadorDeJogadores() = default;
  void exibirJogadores();
  bool adicionarJogador(string& nome, string& apelido);
  bool removerJogador(string& apelido);
  bool jogadorEhValido(string& apelido);
  bool salvarJogadores();
};

#endif