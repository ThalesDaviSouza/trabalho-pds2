#ifndef MENU_H
#define MENU_H

#include <vector>
#include "./menuItem.hpp"
#include "./../gerenciadorDeJogadores.hpp"

using namespace std;

class Menu {
protected:
  /**
   * @brief Lista de itens do menu
   */
  vector<MenuItem> itens;

public:
  /**
   * @brief Construtor padrão da classe.
   * 
   * @param ehMenuBase Indica se é o menu base ou não. Importante para integração com as subclasses.
   */
  Menu(bool ehMenuBase);
  virtual ~Menu() = default;

  /**
   * @brief Imprime os itens do Menu (MenuItem).
   */ 
  void imprimirMenu();

  /**
   * @brief Valida a ação é um dos itens do Menu (MenuItem).
   * 
   * @param escolha Ação que será verificada.
   */
  bool validarAcao(int escolha);

  /**
   * @brief Indica se o item do menu (MenuItem) abre um Menu novo.
   * 
   * @param escolha Valor do item do menu (MenuItem) que deseja verificar.
   */
  virtual bool acaoAbreMenu(int escolha);

  /**
   * @brief Cria um novo Menu e retorna um ponteiro que aponta para o novo Menu.
   * 
   * @param escolha Valor do item do menu (MenuItem).
   */
  virtual Menu* abrirMenuNovo(int escolha);

  /**
   * @brief Valida se um item do menu (MenuItem) fecha o menu atual.
   * 
   * @param escolha Valor do item do menu (MenuItem).
   */
  virtual bool acaoFechaMenu(int escolha);

  /**
   * @brief Valida se o item do menu (MenuItem) encerra o programa.
   * 
   * @param escolha Valor do item do menu (MenuItem).
   */
  virtual bool acaoEncerraPrograma(int escolha);

};


#endif