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
  MenuItem(int valor, string texto, bool abreMenu)
   : valor(valor), 
     texto(texto), 
     abreMenu(abreMenu), 
     fechaMenu(valor == voltar) 
  { }

  void imprimirLinha();
  int getValor();
  bool getAbreMenu();
  bool getFechaMenu();

};

#endif