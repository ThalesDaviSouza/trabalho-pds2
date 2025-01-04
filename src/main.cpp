#include <iostream>
#include <stack>

#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../include/menus/menu.hpp"
#include "./../Enums/MenuOptions.cpp"

using namespace std;

GerenciadorDeJogadores gerenciadorDeJogadores = GerenciadorDeJogadores("data", "dados.txt");

void addJogador(){
  string nome, apelido;

  cin.clear();
  fflush(stdin);

  cout << "Insira o nome do jogador: ";
  getline(cin, nome);
  
  cout << "Insira o apelido do jogador: ";
  getline(cin, apelido);

  if(gerenciadorDeJogadores.adicionarJogador(nome, apelido)){
    cout << "Jogador adicionado com sucesso" << endl;
  }
  else{
    cout << "Falha ao adicionar o jogador" << endl;
    cout << "Verifique se o Apelido ja nao esta em uso" << endl;
  }
}

int main(){
  int escolha = nenhuma;
  stack<Menu*> menus;

  try{
    menus.push(new Menu(true));
  }
  catch(exception& ex){
    cout << ex.what();
  }
  
  while(true)
  {
    menus.top()->imprimirMenu();
    cout << "Opcao: ";
    cin >> escolha;

    try
    {
      if(menus.top()->validarAcao(escolha))
      {
        if(menus.top()->acaoEncerraPrograma(escolha)){
          break;
        }
        if(menus.top()->acaoAbreMenu(escolha)){
          Menu* menuAtual = menus.top()->abrirMenuNovo(escolha); 
          menus.push(menuAtual);
        }
        else if(menus.top()->acaoFechaMenu(escolha)){
          Menu* menuParaDeletar = menus.top();
          menus.pop();

          delete menuParaDeletar;
        }
        else{
          if(escolha == adicionarJogador){
            addJogador();
          }
          else if(escolha == exibirJogadores){
            gerenciadorDeJogadores.exibirJogadores();
          }
        }
      }
    }
    catch(const invalid_argument& e)
    {
      cerr << "Houve um erro: " << e.what() << '\n';
    }
    catch(const exception& e)
    {
      cerr << "Houve um erro: " << e.what() << '\n';
    }

  }

  delete menus.top();

  gerenciadorDeJogadores.salvarJogadores();

  return 0;
}