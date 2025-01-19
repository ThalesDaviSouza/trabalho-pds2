#include <iostream>

#include "./../include/menus/menu.hpp"
#include "./../../include/menus/menuGerenciarJogadores.hpp"
#include "./../../include/menus/menuGerenciarJogos.hpp"
#include "./../../include/menus/MenuPreJogo.hpp"
#include "./../../include/gerenciadorDeJogadores.hpp"
#include "./../Enums/MenuOptions.cpp"

using namespace std;

string montarMensagemDeErro(int escolha){
  string mensagemErro = "A acao ("; 
  mensagemErro = mensagemErro.append(to_string(escolha));
  mensagemErro = mensagemErro.append(") eh invalida");
  
  return mensagemErro;
}

// Menu base
Menu::Menu(bool ehSuperClass){
  if(ehSuperClass){
    this->itens.push_back(MenuItem(gerenciarJogos, "Gerenciar Jogos", true));
    this->itens.push_back(MenuItem(gerenciarJogadores, "Gerenciar Jogadores", true));
    this->itens.push_back(MenuItem(fecharPrograma, "Fechar Programa", false));
  }
}

void Menu::imprimirMenu(){
  cout << "Escolha uma das opcoes abaixo:" << endl << endl;

  for(MenuItem&item : this->itens){
    item.imprimirLinha();
  }
}

bool Menu::validarAcao(int escolha){

  for(MenuItem& item : this->itens){
    if(item.getValor() == escolha){
      return true;
    }
  }

  return false;
}

bool Menu::acaoAbreMenu(int escolha){
  for(MenuItem& item : this->itens){
    if(item.getValor() == escolha){
      return item.getAbreMenu();
    }
  }

  string mensagemErro = montarMensagemDeErro(escolha);
  
  throw invalid_argument(mensagemErro);

}

bool Menu::acaoFechaMenu(int escolha){
  for(MenuItem& item : this->itens){
    if(item.getValor() == escolha){
      return item.getFechaMenu();
    }
  }

  string mensagemErro = montarMensagemDeErro(escolha);
  
  throw invalid_argument(mensagemErro);

}

Menu* Menu::abrirMenuNovo(int escolha){
  switch (escolha)
  {
  case gerenciarJogadores:
    return new MenuGerenciarJogadores();
    break;
  
  case gerenciarJogos:
    return new MenuGerenciarJogos();
    break;
      
  case iniciarJogo:
    return new MenuPreJogo();
    break;
      
  default:
    throw out_of_range("O menu nao foi encontrado");
    break;
  }
}

bool Menu::acaoEncerraPrograma(int escolha){
  return escolha == fecharPrograma;
}