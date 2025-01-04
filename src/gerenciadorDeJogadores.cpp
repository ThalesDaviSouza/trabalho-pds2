#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../include/jogador.hpp"

#include <iostream>
#include <fstream>
#include <direct.h>

using namespace std;

GerenciadorDeJogadores::GerenciadorDeJogadores(
  string caminhoPasta, 
  string nomeArquivo
)
{
  string caminhoArquivo = caminhoPasta + '/' + nomeArquivo;

  ifstream arquivo(caminhoArquivo);

  if(!arquivo.is_open()){
    // Cria a pasta caso ela não exista
    _mkdir(caminhoPasta.c_str());

    ofstream arquivoCriado(caminhoArquivo);

    if(!arquivoCriado.is_open()){
      cout << "Não foi possível criar o arquivo de dados" << endl;
      exit(-1);
    }
  }
  else{
    
    ifstream aux(caminhoArquivo, ios::ate | ios::binary);

    // Verificando se o arquivo tem conteudo para ser lido
    if(aux.tellg() != 0){
      while(!arquivo.eof()){
        string nome;
        string apelido;
        
        getline(arquivo, nome);
        getline(arquivo, apelido);

        this->adicionarJogador(nome, apelido);

      }
    }

  }

  this->caminhoArquivo = caminhoArquivo;
  this->caminhoPasta = caminhoPasta;
  this->nomeArquivo = nomeArquivo;

}

bool GerenciadorDeJogadores::jogadorEhValido(string& apelido){
  for(Jogador&jogador : this->jogadores){
    if(jogador.getApelido() == apelido){
      return false;
    }
  }
  return true;
}

bool GerenciadorDeJogadores::adicionarJogador(string& nome, string& apelido){
  if(this->jogadorEhValido(apelido)){
    this->jogadores.push_back(Jogador(nome, apelido));
    return true;
  }
  else{
    return false;
  }
}

void GerenciadorDeJogadores::exibirJogadores(){
  if(this->jogadores.empty()){
    cout << "Nenhum jogador adicionado ainda" << endl;
    return;
  }

  for(Jogador& jogador : this->jogadores){
    cout << jogador.getNome() << " - [" << jogador.getApelido() << "]" << endl;
  }
}

bool GerenciadorDeJogadores::salvarJogadores(){
  ofstream arquivo(caminhoArquivo, ios::trunc);

  if(!this->jogadores.empty())
  {
    string apelidoUltimoJogador = this->jogadores.back().getApelido();

    for(Jogador& jogador : this->jogadores){
      arquivo << jogador.getNome() << endl;
      arquivo << jogador.getApelido();

      if(apelidoUltimoJogador.compare(jogador.getApelido()) != 0){
        arquivo << endl;
      }
    }
  }
  
  arquivo.close();

}