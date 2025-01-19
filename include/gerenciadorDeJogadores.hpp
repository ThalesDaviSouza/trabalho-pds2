#ifndef GERENCIADOR_DE_JOGADORES_H
#define GERENCIADOR_DE_JOGADORES_H

#include <string>
#include <vector>
#include "./jogador.hpp"
#include "./jogadorInGame.hpp"
#include "./partida.hpp"
#include "./../Enums/Jogo.cpp"

using namespace std;

class GerenciadorDeJogadores {
private:
  string nomeArquivo;
  string caminhoPasta;
  string caminhoArquivoJogadores;
  string caminhoArquivoPartidas;
  vector<Jogador> jogadores;
  vector<RegistroPartida> registroPartidas;

public:
  /**
   * @brief Construtor padrão da classe.
   * 
   * @param caminhoPasta Caminho relativo onde ficam os dados.
   * @param nomeArquivo Nome do arquivo onde ficam os dados.
   */
  GerenciadorDeJogadores(string caminhoPasta, string nomeArquivoJogadores, string nomeArquivoPartidas);
  ~GerenciadorDeJogadores() = default;

  /**
   * @brief Exibe todos os Jogadores cadastrados
   */
  void exibirJogadores();

  /**
   * @brief Adiciona jogadores.
   * 
   * @param nome Nome do Jogador
   * @param apelido Apelido do Jogador (deve ser único)
   */
  bool adicionarJogador(string& nome, string& apelido);

  /**
   * @brief Remove 1 Jogador da lista de jogadores.
   * 
   * @param apelido Apelido do Jogador que deve ser removido.
   */
  bool removerJogador(string& apelido);

  /**
   * @brief Verifica se um apelido de Jogador é válido.
   * 
   * @param apelido Apelido do Jogador.
   */
  bool jogadorEhValido(string& apelido);

  /**
   * @brief Salva todos os Jogadores carregados na lista no arquivo de dados.
   */
  bool salvarJogadores();

  Jogador buscarJogador(string apelido);
  
  /**
   * @brief Adiciona o registro para quando o jogo possui pontuacao
   */
  void adicionarRegistroDePartida(string apelido, Jogo jogo, bool ganhou, int pontuacao);
  void adicionarRegistroDePartida(string apelido, Jogo jogo, bool ganhou);
  
  vector<RegistroPartida>  getRegistrosDePartida(string apelido);

  bool salvarPartidas();

};

#endif