#include "./../include/jogador.hpp"

Jogador::Jogador(string nome, string apelido){
  this->Apelido = apelido;
  this->Nome = nome;
}

string Jogador::getApelido(){
  return this->Apelido;
}

string Jogador::getNome(){
  return this->Nome;
}

