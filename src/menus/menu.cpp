#include <iostream>

#include "./../include/menus/menu.hpp"
#include "./../../include/menus/menuGerenciarJogadores.hpp"
#include "./../../include/gerenciadorDeJogadores.hpp"
#include "./../Enums/MenuOptions.cpp"

using namespace std;

void lancarAcaoInvalida(int escolha){
  string mensagemErro = "A acao ("; 
  mensagemErro = mensagemErro.append(to_string(escolha));
  mensagemErro = mensagemErro.append(") eh invalida");

  throw invalid_argument(mensagemErro);

}

// Menu base
Menu::Menu(bool ehSuperClass){
  if(ehSuperClass){
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

}

bool Menu::acaoAbreMenu(int escolha){
  for(MenuItem& item : this->itens){
    if(item.getValor() == escolha){
      return item.getAbreMenu();
    }
  }

  lancarAcaoInvalida(escolha);
    
}

bool Menu::acaoFechaMenu(int escolha){
  for(MenuItem& item : this->itens){
    if(item.getValor() == escolha){
      return item.getFechaMenu();
    }
  }

  lancarAcaoInvalida(escolha);

}

Menu* Menu::abrirMenuNovo(int escolha){
  if(escolha == gerenciarJogadores){
    return new MenuGerenciarJogadores();
  }
}

bool Menu::acaoEncerraPrograma(int escolha){
  return escolha == fecharPrograma;
}