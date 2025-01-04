#ifndef MENU_H
#define MENU_H

#include <vector>
#include "./menuItem.hpp"
#include "./../gerenciadorDeJogadores.hpp"

using namespace std;

class Menu {
protected:
  vector<MenuItem> itens;

public:
  Menu(bool ehSuperClass);
  virtual ~Menu() = default;

  void imprimirMenu();
  bool validarAcao(int escolha);

  virtual bool acaoAbreMenu(int escolha);
  virtual Menu* abrirMenuNovo(int escolha);
  virtual bool acaoFechaMenu(int escolha);
  virtual bool acaoEncerraPrograma(int escolha);

};


#endif