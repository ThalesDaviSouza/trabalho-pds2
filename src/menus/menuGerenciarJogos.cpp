#include <iostream>

#include "./../../include/menus/menuGerenciarJogos.hpp"
#include "./../../include/menus/menuItem.hpp"
#include "./../../Enums/MenuOptions.cpp"

/**
 * @details Itens do Menu:
 * @details Jogar Jogo da Velha.
 * @details Jogar Reversi.
 * @details Jogar Lig4.
 * @details Voltar ao menu anterior.
 */
MenuGerenciarJogos::MenuGerenciarJogos()
: Menu(false) 
{
  this->itens.push_back(MenuItem(adicionarJogadorPartida, "Adicionar Jogador na Partida", false));
  this->itens.push_back(MenuItem(listarJogadoresPartida, "Listar Jogadores na Partida", false));
  this->itens.push_back(MenuItem(listarJogadoresCadastrados, "Listar Jogadores cadastrados", false));
  this->itens.push_back(MenuItem(iniciarJogo, "Iniciar o jogo", true));
  this->itens.push_back(MenuItem(voltar, "Voltar ao menu anterior", false));
}
