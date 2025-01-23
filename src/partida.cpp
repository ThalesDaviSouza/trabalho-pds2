#include "./../include/partida.hpp"

RegistroPartida::RegistroPartida(string apelido, Jogo jogo, bool ganhou)
: apelidoJogador(apelido), jogo(jogo), ganhou(ganhou)
{}

RegistroPartida::RegistroPartida(string apelido, Jogo jogo, bool ganhou, int pontuacao)
: apelidoJogador(apelido), jogo(jogo), ganhou(ganhou), pontuacao(pontuacao) 
{}

string RegistroPartida::getApelidoJogador(){
  return apelidoJogador;
}

Jogo RegistroPartida::getJogo(){
  return jogo;
}

bool RegistroPartida::getGanhou(){
  return ganhou;
}

int RegistroPartida::getPontuacao(){
  return pontuacao;
}
