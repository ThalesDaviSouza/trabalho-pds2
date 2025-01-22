#include "./../include/minmax.hpp"

#include <vector>
#include <thread>
#include <future>

MinMaxNode::MinMaxNode(Tabuleiro* tabuleiro, JogadorInGame& agente, JogadorInGame& inimigo)
: agente(agente), inimigo(inimigo)
{ 
  Tabuleiro* tab = nullptr;
  if(dynamic_cast<Tabuleiro_JogoDaVelha*>(tabuleiro)){
    tab = new Tabuleiro_JogoDaVelha();
  }
  else if(dynamic_cast<Tabuleiro_Lig4*>(tabuleiro)){
    cout << "Tabuleiro lig4" << endl;
    tab = new Tabuleiro_Lig4();
  }
  else if(dynamic_cast<Tabuleiro_Reversi*>(tabuleiro)){
    cout << "Tabuleiro reversi" << endl;
    tab = new Tabuleiro_Reversi();
  }else{

    cout << "Tabuleiro deu pau" << endl;
  }

  for(int i = 0; i < tab->getQuantidadeLinhas(); i++){
    for(int j = 0; j < tab->getQuantidadeColunas(); j++){
      tab->getTabuleiroRef()[i][j] = tabuleiro->getTabuleiro()[i][j];
    }
  }

  this->tabuleiro = tab;
}

Tabuleiro* MinMaxNode::getTabuleiro(){
  return tabuleiro;
}

int MinMaxNode::getPesoJogada(int linha, int coluna, Cor corAgente){
  MinMaxNode agenteAux(tabuleiro, inimigo, agente);

  if(agenteAux.getTabuleiro()->verificarJogada(linha, coluna, agente.getCor())){
    try
    {
      agenteAux.getTabuleiro()->fazerJogada(linha, coluna, agente.getCor());

      // agenteAux.getTabuleiro()->printTabuleiro();

      if(agenteAux.getTabuleiro()->verificarVitoria()){
        return (agenteAux.getTabuleiro()->getCorUltimaJogada() == corAgente) ? +1 : -1;
      }
    }
    catch(const std::exception& e)
    {
      // Empatou
      return 0;
    }
    
  }
  else{
    cout << "movimento invalido" << endl;
    cout << "linha: " << linha << endl;
    cout << "coluna: " << coluna << endl;
    cout << "Cor: " << static_cast<char>(agente.getCor()) << endl;
    
    agenteAux.getTabuleiro()->printTabuleiro();

    return 0;
  }

  vector<pair<int, int>> jogadasPossiveis;

  for(int i = 0; i < agenteAux.getTabuleiro()->getQuantidadeLinhas(); i++){
    for(int j = 0; j < agenteAux.getTabuleiro()->getQuantidadeColunas(); j++){
      if(agenteAux.getTabuleiro()->verificarJogada(i, j, agente.getCor())){
        jogadasPossiveis.push_back(make_pair(i, j));
      }
    }
  }
  
  vector<int> pesos;
  bool ehTurnoDoAgente = (corAgente == agente.getCor());  

  for(auto& jogada : jogadasPossiveis){
    pesos.push_back(agenteAux.getPesoJogada(jogada.first, jogada.second, corAgente));
  }

  int pesoRetorno = pesos.front();
  
  for(auto& peso : pesos){
    // Se for turno do agente, Maxmizing
    if(ehTurnoDoAgente && (peso > pesoRetorno)){
      pesoRetorno = peso;
    }
    // Se for turno do jogador, Minmizing
    else if(!ehTurnoDoAgente && (peso < pesoRetorno)){
      pesoRetorno = peso;
    }
  }

  return pesoRetorno;

}

pair<int, int> MinMaxNode::melhorJogada(){  
  // Lista de todas as jogadas possíveis
  // peso da jogada, pair<linha, coluna>
  vector<pair<int, pair<int, int>>> jogadasPossiveis;

  for(int i = 0; i < tabuleiro->getQuantidadeLinhas(); i++){
    for(int j = 0; j < tabuleiro->getQuantidadeColunas(); j++){
      if(tabuleiro->verificarJogada(i, j, agente.getCor())){
        jogadasPossiveis.push_back(make_pair(0, make_pair(i, j)));
      }
    }
  }

  if((int)jogadasPossiveis.size() > 0){
    
    pair<int, pair<int, int>>* melhorJogada = &jogadasPossiveis.front();
    vector<thread> threads;
    vector<future<int>> resultados;

    int i = 0;

    for(auto& jogada : jogadasPossiveis){
      promise<int> promessa;
      resultados.push_back(promessa.get_future());

      // Criar threads chamando o método da instância
      threads.emplace_back([i, this, jogada = jogada, promessa = std::move(promessa)]() mutable {
        int resultado = this->getPesoJogada(jogada.second.first, jogada.second.second, agente.getCor()); 

        promessa.set_value(resultado); 
      });
      
    }
    
    for(auto& th : threads){
      if(th.joinable()){
        th.join();
      }
    }
    
    for(int i = 0; i < resultados.size(); i++){
      jogadasPossiveis[i].first = resultados[i].get();
    }
    
    for(auto& jogada : jogadasPossiveis){
      // cout << "Peso jogada: " << jogada.first << "[" << jogada.second.first << " " << jogada.second.second << "]" << endl;
      if((int)(jogada.first) > (int)(melhorJogada->first)){
        melhorJogada = &jogada;
      }

    }
    
    // cout << "melhor Jogada: " << melhorJogada->first << endl;

    return melhorJogada->second;
  }
  else{
    throw runtime_error("Sem jogadas possiveis");
  }
}

pair<int,int> MinMaxNode::obterJogadaAgente(Tabuleiro* tabuleiro, JogadorInGame& agente, JogadorInGame& inimigo){
  pair<int,int> retorno = make_pair(0, 0);

  MinMaxNode base(tabuleiro, agente, inimigo);
  
  retorno = base.melhorJogada();

  return retorno;
}


