#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

#include "./../../Enums/MenuOptions.cpp"

using namespace std;

class MenuItem{
private:
  int valor;
  string texto;
  bool abreMenu;
  bool fechaMenu;

public:
  /**
   * @brief Construtor padrão.
   * 
   * @param valor Valor que identificará o item do menu (MenuItem).
   * @param texto Texto do item do menu (MenuItem).
   * @param abreMenu Informa se abre um menu novo ou não.
   */
  MenuItem(int valor, string texto, bool abreMenu)
   : valor(valor), 
     texto(texto), 
     abreMenu(abreMenu), 
     fechaMenu(valor == voltar) 
  { }

  /**
   * @brief Imprime as informações do item do menu (MenuItem).
   */
  void imprimirLinha();

  /**
   * @brief Retorna o valor do item do menu (MenuItem).
   */
  int getValor();

  /**
   * @brief Retorna se o item do menu (MenuItem) abre um novo Menu.
   */
  bool getAbreMenu();

  /**
   * @brief Retorna se o item do menu (MenuItem) fecha o Menu atual.
   */
  bool getFechaMenu();

};

#endif