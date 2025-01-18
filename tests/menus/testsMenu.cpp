#include "./../third-party/doctest.h"
#include "./../../include/menus/menu.hpp"
#include "./../../include/menus/menuGerenciarJogadores.hpp"

#include <iostream>
#include <typeinfo>

TEST_CASE("Menu: Dada uma acao retornar verdadeiro") {
  Menu menu(true);

  CHECK(menu.validarAcao(gerenciarJogadores) == true);
  CHECK(menu.validarAcao(fecharPrograma) == true);

}

TEST_CASE("Menu: Dada uma acao retornar falso") {
  Menu menu(true);

  CHECK(menu.validarAcao(voltar) == false);
  CHECK(menu.validarAcao(nenhuma) == false);
  
}



TEST_CASE("Menu: dada uma acao retornar se ela abre o menu ou nao") {
  Menu menu(true);

  CHECK(menu.acaoAbreMenu(gerenciarJogadores) == true);
  CHECK(menu.acaoAbreMenu(fecharPrograma) == false);

}

TEST_CASE("Menu: dada uma acao retornar que nao pertence ao menu lancar excecao") {
  Menu menu(true);

  CHECK_THROWS_AS(menu.acaoAbreMenu(nenhuma), invalid_argument);

}

TEST_SUITE("Menu: dada uma acao retornar o tipo correto de menu que deve ser aberto") {
  TEST_CASE("Menu: dada a acao gerenciarJogadores retornar MenuGerenciarJogadores"){
    Menu menu(true);
    string typeMenu = typeid(*menu.abrirMenuNovo(gerenciarJogadores)).name();
    string typeEsperado = typeid(MenuGerenciarJogadores).name();

    CHECK(typeMenu == typeEsperado);
  }

}

TEST_CASE("Menu: dada uma acao retornar se ela encerra o programa"){
  Menu menu(true);

  CHECK(menu.acaoEncerraPrograma(fecharPrograma) == true);
  CHECK(menu.acaoEncerraPrograma(gerenciarJogadores) == false);

}

// Está aqui porque se refere a todas as classes filhas do menu base que podem possuir a ação Voltar
TEST_CASE("Menu: dada uma acao retornar se ela fecha o menu") {
  MenuGerenciarJogadores menu;

  CHECK(menu.acaoFechaMenu(voltar) == true);
  CHECK(menu.acaoFechaMenu(adicionarJogador) == false);

}