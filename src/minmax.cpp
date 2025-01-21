#include "./../include/minmax.hpp"

#include <vector>

MinMaxNode::MinMaxNode(Tabuleiro* tabuleiro, JogadorInGame& agente, JogadorInGame& inimigo)
: agente(agente), inimigo(inimigo)
{ 
  Tabuleiro* tab = nullptr;
  if(dynamic_cast<Tabuleiro_JogoDaVelha*>(tabuleiro)){
    cout << "Tabuleiro jogo da velha" << endl;
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
      cout << "Tentativa fazer a jogada" << endl;
      cout << "linha: " << linha << endl;
      cout << "coluna: " << coluna << endl;
      cout << "agente cor: " << agente.getCor() << endl;
      agenteAux.getTabuleiro()->fazerJogada(linha, coluna, agente.getCor());
      agenteAux.getTabuleiro()->printTabuleiro();
    }
    catch(const std::exception& e)
    {
      // Empatou
      cout << "Empatou" << endl;
      return 0;
    }
    
  }
  else{
    return 0;
  }

  try{
    if(agenteAux.getTabuleiro()->verificarVitoria()){
      cout << "Agente ganhou: " << endl;
      return (agenteAux.getTabuleiro()->getCorUltimaJogada() == corAgente) ? +1 : -1;
    }
  }
  catch(const std::exception& e){
    // Deu velha
    return 0;
  }

  vector<pair<int, pair<int, int>>> jogadasPossiveis;

  for(int i = 0; i < tabuleiro->getQuantidadeLinhas(); i++){
    for(int j = 0; j < tabuleiro->getQuantidadeColunas(); j++){
      if(tabuleiro->verificarJogada(i, j, agente.getCor())){
        jogadasPossiveis.push_back(make_pair(0, make_pair(i, j)));
      }
    }
  }

  int pesoRetorno = 0;

  for(auto& jogada : jogadasPossiveis){
    pesoRetorno += agenteAux.getPesoJogada(jogada.second.first, jogada.second.second, corAgente);
  }
  
  cout << "Peso calculado: " << pesoRetorno << endl;
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

    for(auto& jogada : jogadasPossiveis){
      jogada.first = getPesoJogada(jogada.second.first, jogada.second.second, agente.getCor());
    }
    
    for(auto& jogada : jogadasPossiveis){
      cout << "Peso jogada: " << jogada.first << "[" << jogada.second.first << " " << jogada.second.second << "]" << endl;

      if((int)(jogada.first) > (int)(melhorJogada->first)){
        melhorJogada = &jogada;
      }
    }
    
    cout << "melhor Jogada: " << melhorJogada->first << endl;

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


