#include "./../include/gerenciadorDeJogos.hpp"
#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../include/jogadorInGame.hpp"
#include "./../shared/Utils.hpp"

#include <iostream>

using namespace std;


GerenciadorDeJogos::GerenciadorDeJogos(GerenciadorDeJogadores& gerenciadorDeJogadores) 
: gerenciadorDeJogadores(gerenciadorDeJogadores) 
{ }

GerenciadorDeJogos::~GerenciadorDeJogos(){
  delete tabuleiro;
}

void GerenciadorDeJogos::imprimirJogadores(){
  if((int)jogadores.size() == 0){
    cout << "* - Sem jogadores selecionados no momento" << endl;
  }
  else{
    int i = 1;

    cout << "Jogadores Atuais:" << endl;

    for(JogadorInGame& jogador : jogadores){
      cout << "#" << i << " - " << jogador.getJogador().getNome();
      cout << " (" << jogador.getJogador().getApelido() << ")" << endl;

      i++;
    }

    cout << endl << endl;
  }
}

void GerenciadorDeJogos::selecionarJogador(){
  string apelido;
  Cor cor;
  char aux;

  cout << "Digite o apelido do jogador: ";
  cin >> apelido;
  clearBuffer();

  Jogador jog = gerenciadorDeJogadores.buscarJogador(apelido);

  cout << "Escolha a cor: ";
  cin >> aux;
  cor = static_cast<Cor>(aux);

  JogadorInGame jogador(jog, cor);

  jogadores.push_back(jogador);

}

void GerenciadorDeJogos::JogarJogoDaVelha(){
  if((int)jogadores.size() != QTD_JOGADORES_VELHA){
    string msgErro = "A quantidade de jogadores para jogo da velha deve ser ";
    msgErro.append(to_string(QTD_JOGADORES_VELHA));

    throw length_error(msgErro);
  }

  tabuleiro = new Tabuleiro_JogoDaVelha();
  
  JogadorInGame jogadorAtual = jogadores.front();
  int linha, coluna;
  int posProxJogador = 0;
  bool jogadaValida = false;

  while (!tabuleiro->verificarVitoria())
  {
    cout << "Turno do Jogador: " << jogadorAtual.getJogador().getNome() << "(" << jogadorAtual.getJogador().getApelido() << ")";
    cout << endl;

    tabuleiro->printTabuleiro();
    cout << endl;

    do{
      cout << "Digite a sua jogada (linha coluna): ";
      if((cin >> linha >> coluna)){
        jogadaValida = tabuleiro->verificarJogada(linha, coluna, jogadorAtual.getCor());
        if(!jogadaValida){
          cout << "Houve um erro: Essa jogada eh invalida" << endl;
        }
      }
      else{
        cout << "Houve um erro na leitura" << endl;
        clearBuffer();
        continue;
      }
    }while(!jogadaValida);
    
    tabuleiro->fazerJogada(linha, coluna, jogadorAtual.getCor());

    posProxJogador = (posProxJogador == 0) ? 1 : 0;
    
    jogadorAtual = jogadores.at(posProxJogador);

  }

  Cor corGanhador = tabuleiro->getCorUltimaJogada();
  int posGanhador = 0;

  for(auto& jog : jogadores){
    if(jog.getCor() == corGanhador){
      break;
    }
    else{
      posGanhador++;
    }
  }

  JogadorInGame ganhador = jogadores.at(posGanhador);

  tabuleiro->printTabuleiro();

  cout << endl << "O Jogo acabou!" << endl;
  cout << "Vencedor: " << ganhador.getJogador().getNome() << endl;

  delete tabuleiro;
  
}
