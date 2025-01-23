#include <iostream>

#include "./../../include/menus/menuPreJogo.hpp"
#include "./../../include/menus/menuItem.hpp"
#include "./../../Enums/MenuOptions.cpp"

/**
 * @details Itens do Menu:
 * @details Jogar Jogo da Velha.
 * @details Jogar Reversi.
 * @details Jogar Lig4.
 * @details Voltar ao menu anterior.
 */
MenuPreJogo::MenuPreJogo()
: Menu(false) 
{
  this->itens.push_back(MenuItem(jogarJogoDaVelha, "Jogar Jogo da Velha", false));
  this->itens.push_back(MenuItem(jogarReversi, "Jogar Reversi", false));
  this->itens.push_back(MenuItem(jogarLig4, "Jogar Lig4", false));
  this->itens.push_back(MenuItem(voltar, "Voltar ao menu anterior", false));
}
