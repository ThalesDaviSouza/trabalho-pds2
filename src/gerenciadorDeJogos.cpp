#include "./../include/gerenciadorDeJogos.hpp"
#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../include/jogadorInGame.hpp"
#include "./../include/minmax.hpp"
#include "./../shared/Utils.hpp"
#include "./../Enums/MenuOptions.cpp"

#include <iostream>
#include <map>

using namespace std;


GerenciadorDeJogos::GerenciadorDeJogos(GerenciadorDeJogadores& gerenciadorDeJogadores) 
: gerenciadorDeJogadores(gerenciadorDeJogadores) 
{ }

GerenciadorDeJogos::~GerenciadorDeJogos() = default;

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

void GerenciadorDeJogos::removerJogadorPartida(string apelido){
  int aux = 0;

  for(auto& jogador : jogadores){
    if(jogador.getJogador().getApelido().compare(apelido) == 0){
      jogadores.erase(jogadores.begin()+aux);
      break;
    }
    ++aux;
  }
}

Cor GerenciadorDeJogos::solicitarCorJogador(string mensagemSelecao){
  bool corValida = false;
  char aux;
  Cor cor;
  do{
    imprimirCores();
    cout << endl;
    cout << mensagemSelecao;

    if(cin >> aux){
      cor = static_cast<Cor>(aux);

      corValida = true;
      
      for(auto& jog : jogadores){
        if(jog.getCor() == cor){
          cout << "O time escolhido ja esta em jogo" << endl;
          corValida = false;
          break;
        }
      }
    }
    else{
      cout << "Houve um erro na leitura" << endl;
      clearBuffer();
    }
  }while(!corValida);

  return cor;
}

void GerenciadorDeJogos::selecionarJogador(){
  int posJogador = 0;
  Jogador* jogador;
  bool editar = false;
  int escolha;
  bool escolhaValida = false;
  Cor cor;
  char aux;
  bool corValida = false;

  do{
    cout << "Jogadores salvos: " << endl;
    gerenciadorDeJogadores.exibirJogadoresResumido();
    cout << "...[" << voltar << "] - Terminar selecao" << endl;
    cout << endl;

    cout << "Insira o numero do jogador: ";
    if(cin >> posJogador){
      if(posJogador == voltar){
        continue;
      }
      
      jogador = &gerenciadorDeJogadores.buscarJogadorPorPosicao(posJogador);
      
      editar = false;
      for(auto& jog : jogadores){
        if(jog.getJogador().getApelido().compare(jogador->getApelido()) == 0){
          editar = true;
          break;
        }
      }

      if(editar){
        escolhaValida = false;
        while (!escolhaValida)
        {      
          cout << "jogador " << jogador->getNome() << " ja esta em jogo" << endl;
          cout << "...[1] - Remover jogador" << endl;
          cout << "...[2] - Alterar cor do jogador" << endl;

          if(cin >> escolha){
            if(escolha == 1){
              escolhaValida = true;  
              removerJogadorPartida(jogador->getApelido());
            }
            else if(escolha == 2){
              escolhaValida = true;  

              cor = solicitarCorJogador("Insira o codigo do novo time do jogador: ");
              
              for(auto& jog : jogadores){
                if(jog.getJogador().getApelido().compare(jogador->getApelido()) == 0){
                  jog.setCor(cor);
                  break;
                }
              }
            }
            else{
              cout << "Houve um erro: opcao invalida" << endl;
            }
          }
          else{
            cout << "Houve um erro: falha na leitura" << endl;
            clearBuffer();
          }
        }
      }
      else{
        cor = solicitarCorJogador("Insira o codigo do time do jogador: ");
        if(cor != Vazio){
          JogadorInGame jogadorInGame(*jogador, cor);
          jogadores.push_back(jogadorInGame);
        }
      }
    }
    else{
      cout << "Houve um erro na leitura" << endl;
      clearBuffer();
    }
    
  }while(posJogador != voltar);

}

void GerenciadorDeJogos::JogarJogoDaVelha(){
  bool ativarIA = false;
  Cor corIA = Vazio;
  JogadorInGame* jogadorIa = nullptr;

  if((int)jogadores.size() == 1){
    ativarIA = true;
    corIA = jogadores.at(0).getCor() == X ? O : X;

    Jogador aux("IA", "IA");
    jogadorIa = new JogadorInGame(aux, corIA);
  }
  else if((int)jogadores.size() != QTD_JOGADORES_VELHA){
    string msgErro = "A quantidade de jogadores para jogo da velha deve ser ";
    msgErro.append(to_string(QTD_JOGADORES_VELHA));

    throw length_error(msgErro);
  }

  tabuleiro = new Tabuleiro_JogoDaVelha();
  
  JogadorInGame jogadorAtual = jogadores.front();
  int linha, coluna;
  int posProxJogador = 0;
  bool jogadaValida = false;

  cout << "Jogar conta a maquina: " << ativarIA << endl;

  while (!tabuleiro->verificarVitoria())
  {
    cout << "Turno do Jogador: " << jogadorAtual.getJogador().getNome() << "(" << jogadorAtual.getJogador().getApelido() << ")";
    cout << endl;

    tabuleiro->printTabuleiro();
    cout << endl;
    
    jogadaValida = false;
    do{
      cout << "Digite a sua jogada (linha coluna): ";
      if((cin >> linha >> coluna)){
        --linha;
        --coluna;
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

    if(!ativarIA){
      posProxJogador = (posProxJogador == 0) ? 1 : 0;
    }
    else if(!tabuleiro->verificarVitoria()){
      pair<int, int> jogadaIA = MinMaxNode::obterJogadaAgente(tabuleiro, *jogadorIa, jogadorAtual);
      cout << "Jogada IA " << jogadaIA.first << jogadaIA.second << endl;
      tabuleiro->fazerJogada(jogadaIA.first, jogadaIA.second, corIA);
    }
    
    jogadorAtual = jogadores.at(posProxJogador);

  }

  JogadorInGame* ganhador = nullptr;

  Cor corGanhador = tabuleiro->getCorUltimaJogada();
  if(ativarIA && corGanhador == corIA){
    ganhador = jogadorIa;
  }
  else{
    int posGanhador = 0;

    for(auto& jog : jogadores){
      if(jog.getCor() == corGanhador){
        break;
      }
      else{
        posGanhador++;
      }
    }

    ganhador = &jogadores.at(posGanhador);

  }

  tabuleiro->printTabuleiro();

  cout << endl << "O Jogo acabou!" << endl;

  cout << "Vencedor: " << ganhador->getJogador().getNome() << endl;

  bool ganhou = false;

  for(auto& jogador : jogadores){
    ganhou = (jogador.getJogador().getApelido().compare(ganhador->getJogador().getApelido()) == 0);

    gerenciadorDeJogadores.adicionarRegistroDePartida(jogador.getJogador().getApelido(), jogoDaVelha, ganhou);
  }
  
  if(ativarIA){
    delete jogadorIa;
  }

  delete tabuleiro;
  
}

void GerenciadorDeJogos::JogarLig4(){
  if((int)jogadores.size() != QTD_JOGADORES_LIG4){
    string msgErro = "A quantidade de jogadores para Lig4 deve ser ";
    msgErro.append(to_string(QTD_JOGADORES_LIG4));

    throw length_error(msgErro);
  }

  tabuleiro = new Tabuleiro_Lig4();
  
  JogadorInGame jogadorAtual = jogadores.front();
  int coluna;
  int posProxJogador = 0;
  bool jogadaValida = false;

  while (!tabuleiro->verificarVitoria())
  {
    cout << "Turno do Jogador: " << jogadorAtual.getJogador().getNome() << "(" << jogadorAtual.getJogador().getApelido() << ")";
    cout << endl;

    tabuleiro->printTabuleiro();
    cout << endl;

    jogadaValida = false;
    do{
      cout << "Digite a sua jogada (coluna): ";
      if((cin >> coluna)){
        --coluna;
        jogadaValida = tabuleiro->verificarJogada(0, coluna, jogadorAtual.getCor());

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
    
    tabuleiro->fazerJogada(0, coluna, jogadorAtual.getCor());

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


pair<Cor, int> retornarGanhadorReversi(Tabuleiro& tab)
{
  map<Cor, int> quantidadePecas;
  Cor corAtual = Vazio;

  for(int i = 0; i < tab.getQuantidadeLinhas(); i++){
    for(int j = 0; j < tab.getQuantidadeColunas(); j++){
      corAtual = tab.getTabuleiro()[i][j];

      if(corAtual != Vazio){
        // Se já existir no map
        if(quantidadePecas.find(corAtual) != quantidadePecas.end()){
          quantidadePecas[corAtual]++;
        }
        else{
          quantidadePecas.insert(make_pair(corAtual, 1));
        }
      }
    }
  }

  int aux = 0;
  pair<Cor, int> maioQuantidade;

  for(auto& par : quantidadePecas){
    if(aux == 0 || par.second > maioQuantidade.second){
      maioQuantidade.first = par.first;
      maioQuantidade.second = par.second;

      if(aux == 0){
        aux++;
      }
    }
  }

  return maioQuantidade;
}

void GerenciadorDeJogos::JogarReversi(){
  if((int)jogadores.size() != QTD_JOGADORES_REVERSI){
    string msgErro = "A quantidade de jogadores para reversi deve ser ";
    msgErro.append(to_string(QTD_JOGADORES_REVERSI));

    throw length_error(msgErro);
  }

  for(auto& jogador : jogadores){
    if(jogador.getCor() != Branco && jogador.getCor() != Preto){
      throw runtime_error("O time dos jogadores deve ser Branco (B) ou Preto (P)");
    }
  }

  tabuleiro = new Tabuleiro_Reversi();
  
  JogadorInGame jogadorAtual = jogadores.front();
  int linha, coluna;
  int posProxJogador = 0;
  bool jogadaValida = false;

  while (!tabuleiro->verificarVitoria())
  {
    cout << "Turno do Jogador: " << jogadorAtual.getJogador().getNome() << " (" << jogadorAtual.getJogador().getApelido() << ")" << endl;
    cout << "Time: " << static_cast<char>(jogadorAtual.getCor()) << endl;
    cout << endl;

    tabuleiro->printTabuleiro();
    cout << endl;

    jogadaValida = false;
    do{
      cout << "Digite a sua jogada (linha coluna): ";
      if((cin >> linha >> coluna)){
        --linha;
        --coluna;
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
  
  pair<Cor, int> corGanhador = retornarGanhadorReversi(*tabuleiro);
  int posGanhador = 0;

  for(auto& jog : jogadores){
    if(jog.getCor() == corGanhador.first){
      break;
    }
    else{
      posGanhador++;
    }
  }

  JogadorInGame ganhador = jogadores.at(posGanhador);

  tabuleiro->printTabuleiro();

  cout << endl << "O Jogo acabou!" << endl;

  cout << "Vencedor: " << ganhador.getJogador().getNome() << " Com a pontuacao de " << corGanhador.second << endl;

  delete tabuleiro;
  
}


void GerenciadorDeJogos::removerTodosJogadores(){
  jogadores.clear();
}

int GerenciadorDeJogos::getQuantidadeJogadores(){
  return (int)jogadores.size();
}
