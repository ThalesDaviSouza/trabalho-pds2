#include <iostream>

#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../Enums/MenuOptions.cpp"

using namespace std;

GerenciadorDeJogadores gerenciadorDeJogadores("data", "dados.txt");

void menuJogadores(){
  int escolha = nenhuma;
  string nome, apelido;

  while(escolha != voltar){
    cout << "Escolha uma das opcoes abaixo:" << endl;
    cout << "[" << adicionarJogador << "] - Adicionar Jogador" << endl;
    cout << "[" << exibirJogadores << "] - Exibir Jogador" << endl;
    cout << "[" << voltar << "] - Voltar ao menu anterior" << endl;
    
    cin >> escolha;

    if(escolha == adicionarJogador){
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
    else if(escolha == exibirJogadores){
      gerenciadorDeJogadores.exibirJogadores();
    }
  }
}

int main(){
  int escolha = nenhuma;

  while(escolha != fecharPrograma){
    cout << "O que voce deseja fazer?" << endl;
    cout << "[" << gerenciarJogadores << "] - Gerenciar Jogadores" << endl;  
    cout << "[" << fecharPrograma << "] - Fechar Programa" << endl;

    cin >> escolha;  

    if(escolha == gerenciarJogadores){
      menuJogadores();
    }
  }


  return 0;
}