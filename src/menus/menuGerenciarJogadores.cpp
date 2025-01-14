#include <iostream>

#include "./../../include/menus/menuGerenciarJogadores.hpp"
#include "./../../include/menus/menuItem.hpp"
#include "./../../Enums/MenuOptions.cpp"


MenuGerenciarJogadores::MenuGerenciarJogadores()
: Menu(false) 
{
  this->itens.push_back(MenuItem(adicionarJogador, "Adicionar Jogador", false));
  this->itens.push_back(MenuItem(removerJogador, "Remover Jogador", false));
  this->itens.push_back(MenuItem(exibirJogadores, "Exibir Jogador", false));
  this->itens.push_back(MenuItem(voltar, "Voltar ao menu anterior", false));
}
