#include "./../include/gerenciadorDeJogadores.hpp"
#include "./../include/jogador.hpp"
#include "./../include/jogadorInGame.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;

/**
 * @details Tenta abrir o arquivo de dados na pasta especificada. Caso não exista, tenta criar a pasta e o arquivo. 
 */
GerenciadorDeJogadores::GerenciadorDeJogadores(
  string caminhoPasta, 
  string nomeArquivoJogadores,
  string nomeArquivoPartidas
)
{
  string caminhoArquivoJogadores = caminhoPasta + '/' + nomeArquivoJogadores;
  string caminhoArquivoPartidas = caminhoPasta + '/' + nomeArquivoPartidas;

  ifstream arquivoJogadores(caminhoArquivoJogadores);
  ifstream arquivoPartidas(caminhoArquivoPartidas);

  if(!arquivoJogadores.is_open() || !arquivoPartidas.is_open()){
    #ifdef _WIN32
    // Cria a pasta caso ela não exista
    _mkdir(caminhoPasta.c_str());
    #else 
    mkdir(caminhoPasta.c_str(), 0755);
    #endif
    
    if(!arquivoJogadores.is_open()){
      ofstream arquivoJogadoresCriado(caminhoArquivoJogadores);

      if(!arquivoJogadoresCriado.is_open()){
        cout << "Nao foi possível criar o arquivo de dados de jogadores" << endl;
        exit(-1);
      }
      arquivoJogadoresCriado.close();
    }

    if(!arquivoPartidas.is_open()){
      ofstream arquivoPartidasCriado(caminhoArquivoPartidas);

      if(!arquivoPartidasCriado.is_open()){
        cout << "Nao foi possivel criar o arquivo de dados de partidas" << endl;
        exit(-1);
      }
      arquivoPartidasCriado.close();
    }

  }
  
  ifstream aux(caminhoArquivoJogadores, ios::ate | ios::binary);

  // Verificando se o arquivo tem conteudo para ser lido
  if(aux.tellg() != 0){
    while(!arquivoJogadores.eof()){
      string nome;
      string apelido;
      
      getline(arquivoJogadores, nome);
      getline(arquivoJogadores, apelido);

      this->adicionarJogador(nome, apelido);

    }
  }
  
  ifstream auxPartidas(caminhoArquivoPartidas, ios::ate | ios::binary);
    if(auxPartidas.tellg() != 0){
    while(!arquivoPartidas.eof()){
      string apelido;
      Jogo jogo;
      int jogoAux;
      int pontuacao;
      bool ganhou;
      
      arquivoPartidas >> apelido;
      arquivoPartidas >> jogoAux;
      jogo = static_cast<Jogo>(jogoAux);

      if(jogo == reversi){
        arquivoPartidas >> pontuacao;
      }
      arquivoPartidas >> ganhou;

      if(jogo == reversi){
        this->adicionarRegistroDePartida(apelido, jogo, ganhou, pontuacao);
      }
      else{
        this->adicionarRegistroDePartida(apelido, jogo, ganhou);
      }

    }
  }

  this->caminhoArquivoJogadores = caminhoArquivoJogadores;
  this->caminhoArquivoPartidas = caminhoArquivoPartidas;
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

bool GerenciadorDeJogadores::removerJogador(string& apelido){
  int i = 0;

  for(Jogador& jogador : this->jogadores){
    if(jogador.getApelido().compare(apelido) == 0){
      this->jogadores.erase(this->jogadores.begin() + i);
      return true;
    }
    i++;
  }

  return false;
}

void imprimirEstaticaJogo(vector<RegistroPartida>& registros, Jogo jogo, string nomeJogo){
  int vitorias = 0;
  int derrotas = 0;

  for(auto& registro : registros){
    if(registro.getJogo() == jogo){
      vitorias += registro.getGanhou() ? 1 : 0;
      derrotas += registro.getGanhou() ? 0 : 1;
    }
  }
  
  cout << nomeJogo << " - V: " << vitorias << " D: " << derrotas << endl;

}

void GerenciadorDeJogadores::exibirJogadores(){
  if(this->jogadores.empty()){
    cout << "Nenhum jogador adicionado ainda" << endl;

    return;
  }

  for(Jogador& jogador : this->jogadores){
    cout << jogador.getNome() << " - [" << jogador.getApelido() << "]" << endl;

    vector<RegistroPartida> registros = getRegistrosDePartida(jogador.getApelido());

    imprimirEstaticaJogo(registros, reversi, "REVERSI");
    imprimirEstaticaJogo(registros, lig4, "LIG4");
    imprimirEstaticaJogo(registros, jogoDaVelha, "VELHA");
    
    cout << endl;
  }
}

bool GerenciadorDeJogadores::salvarJogadores(){
  ofstream arquivo(caminhoArquivoJogadores, ios::trunc);

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

  return true;
}

Jogador GerenciadorDeJogadores::buscarJogador(string apelido){
  for(auto& jogador : jogadores){
    if(jogador.getApelido().compare(apelido) == 0){
      return jogador;
    }
  }

  throw out_of_range("Jogador nao encontrado");
}

void GerenciadorDeJogadores::adicionarRegistroDePartida(string apelido, Jogo jogo, bool ganhou, int pontuacao){
  RegistroPartida registro(apelido, jogo, ganhou, pontuacao);
  registroPartidas.push_back(registro);
}

void GerenciadorDeJogadores::adicionarRegistroDePartida(string apelido, Jogo jogo, bool ganhou){
  RegistroPartida registro(apelido, jogo, ganhou);
  registroPartidas.push_back(registro);
}


bool GerenciadorDeJogadores::salvarPartidas(){
  ofstream arquivo(caminhoArquivoPartidas, ios::trunc);

  int aux = 1;
  int qtdRegistros = (int)registroPartidas.size();

  if(!arquivo.is_open()){
    cerr << "Houve um erro: Nao foi possivel salvar os registros das partidas" << endl;
    cout << caminhoArquivoPartidas << endl;
    return false;
  }

  if(!this->registroPartidas.empty())
  {
    for(RegistroPartida& partida : this->registroPartidas){
      arquivo << partida.getApelidoJogador() << endl;
      arquivo << static_cast<int>(partida.getJogo()) << endl;

      if(partida.getJogo() == reversi){
        arquivo << partida.getPontuacao() << endl;
      }

      arquivo << partida.getGanhou();

      if(aux != qtdRegistros){
        arquivo << endl;
        aux++;
      }
    }
  }
  
  arquivo.close();

  return true;
}

vector<RegistroPartida> GerenciadorDeJogadores::getRegistrosDePartida(string apelido){
  vector<RegistroPartida> registros;

  for(auto& registro : registroPartidas){
    if(registro.getApelidoJogador().compare(apelido) == 0){
      registros.push_back(registro);
    }
  }

  return registros;
}

void GerenciadorDeJogadores::clearRegistrosPartidas(){
  registroPartidas.clear();
}

void GerenciadorDeJogadores::exibirJogadoresResumido(){
  for(int i = 0; i < (int)jogadores.size(); i++){
    cout << "...[" << i << "] - " << jogadores.at(i).getNome() << " (" << jogadores.at(i).getApelido() << ")" << endl;
  }
}

Jogador& GerenciadorDeJogadores::buscarJogadorPorPosicao(int posicaoJogador){
  return jogadores.at(posicaoJogador);
}