#include "./../include/jogadorInGame.hpp"

Jogador JogadorInGame::getJogador(){
  return this->jogador;
}

Cor JogadorInGame::getCor(){
  return this->cor;
}

void JogadorInGame::setCor(Cor cor){
  this->cor = cor;
}