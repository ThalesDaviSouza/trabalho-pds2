#include "./third-party/doctest.h"
#include <iostream>
#include <sstream>
#include <memory>

#include "./../include/gerenciadorDeJogadores.hpp"


TEST_SUITE("Gerenciador de Jogadores: Adicionar jogadores"){
  TEST_CASE("Gerenciador de Jogadores: dado 1 nome e 1 apelido adicionar o jogador na lista"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    bool jogador1Presente = false;
    
    string nome2 = "TESTE PESSOA 2";
    string apelido2 = "TESTE2";
    bool jogador2Presente = false;
    
    string nome3 = "TESTE PESSOA 3";
    string apelido3 = "TESTE3";
    bool jogador3Presente = false;

    string nome4 = "TESTE PESSOA 4";
    string apelido4 = "TESTE4";
    bool jogador4Presente = false;

    gerenciador.adicionarJogador(nome1, apelido1);
    gerenciador.adicionarJogador(nome2, apelido2);
    gerenciador.adicionarJogador(nome3, apelido3);
    gerenciador.adicionarJogador(nome4, apelido4);
    

    CHECK_FALSE(gerenciador.jogadorEhValido(apelido1));
    CHECK_FALSE(gerenciador.jogadorEhValido(apelido2));
    CHECK_FALSE(gerenciador.jogadorEhValido(apelido3));
    CHECK_FALSE(gerenciador.jogadorEhValido(apelido4));

  }

  TEST_CASE("Gerenciador de Jogadores: dado 1 apelido duplicado, nao permitir adicionar"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    bool insercao1, insercao2;

    insercao1 = gerenciador.adicionarJogador(nome1, apelido1);
    insercao2 = gerenciador.adicionarJogador(nome1, apelido1);

    CHECK(insercao1);
    CHECK_FALSE(insercao2);

  }
}


TEST_SUITE("Gerenciador de Jogadores: Validar jogadores para insercao"){
  TEST_CASE("Dado 1 apelido que nao esta na lista retornar verdadeiro"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    string apelido2 = "TESTE2";
    
    gerenciador.adicionarJogador(nome1, apelido1);

    CHECK(gerenciador.jogadorEhValido(apelido2));
  }

  TEST_CASE("Dado 1 apelido que ja esta em uso retornar falso"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    
    gerenciador.adicionarJogador(nome1, apelido1);

    CHECK_FALSE(gerenciador.jogadorEhValido(apelido1));
  }
}

TEST_SUITE("Gerenciador de Jogadores: Validar remocao de jogadores"){
  TEST_CASE("Dado 1 apelido remover ele da lista"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    string nome2 = "TESTE PESSOA 2";
    string apelido2 = "TESTE2";
    string nome3 = "TESTE PESSOA 3";
    string apelido3 = "TESTE3";
    string nome4 = "TESTE PESSOA 4";
    string apelido4 = "TESTE4";
    string nome5 = "TESTE PESSOA 5";
    string apelido5 = "TESTE5";
    
    gerenciador.adicionarJogador(nome1, apelido1);
    gerenciador.adicionarJogador(nome2, apelido2);
    gerenciador.adicionarJogador(nome3, apelido3);
    gerenciador.adicionarJogador(nome4, apelido4);
    gerenciador.adicionarJogador(nome5, apelido5);

    CHECK_FALSE(gerenciador.jogadorEhValido(apelido1));
    CHECK_FALSE(gerenciador.jogadorEhValido(apelido3));
    CHECK_FALSE(gerenciador.jogadorEhValido(apelido5));

    gerenciador.removerJogador(apelido1);
    gerenciador.removerJogador(apelido3);
    gerenciador.removerJogador(apelido5);

    CHECK(gerenciador.jogadorEhValido(apelido1));
    CHECK(gerenciador.jogadorEhValido(apelido3));
    CHECK(gerenciador.jogadorEhValido(apelido5));
  }

  TEST_CASE("Dado 1 apelido que nao esta na lista retornar false"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    
    string nome2 = "TESTE PESSOA 2";
    string apelido2 = "TESTE2";
    
    string nome3 = "TESTE PESSOA 3";
    string apelido3 = "TESTE3";

    string apelido4 = "TESTE4";
    bool retorno;
    
    gerenciador.adicionarJogador(nome1, apelido1);
    gerenciador.adicionarJogador(nome2, apelido2);
    gerenciador.adicionarJogador(nome3, apelido3);

    retorno = gerenciador.removerJogador(apelido4);

    CHECK_FALSE(retorno);
  }
}

TEST_SUITE("Gerenciador de Jogadores: Validar salvar jogadores"){
  TEST_CASE("Dado 1 jogador salvar ele no arquivo"){
    GerenciadorDeJogadores * gerenciador = new GerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    
    string nome2 = "TESTE PESSOA 2";
    string apelido2 = "TESTE2";
    
    gerenciador->adicionarJogador(nome1, apelido1);
    gerenciador->adicionarJogador(nome2, apelido2);

    CHECK_FALSE(gerenciador->jogadorEhValido(apelido1));
    CHECK_FALSE(gerenciador->jogadorEhValido(apelido2));
    
    gerenciador->salvarJogadores();

    delete gerenciador;

    gerenciador = new GerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");

    CHECK_FALSE(gerenciador->jogadorEhValido(apelido1));
    CHECK_FALSE(gerenciador->jogadorEhValido(apelido2));

    gerenciador->removerJogador(apelido1);
    gerenciador->removerJogador(apelido2);
    gerenciador->salvarJogadores();
    
    delete gerenciador;
  }
}

TEST_SUITE("GerenciadorDeJogadores::buscarJogador"){
  TEST_CASE("Dado um apelido achar um jogador"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    
    string nome = "TESTE PESSOA 1";
    string apelido = "TESTE1";

    gerenciador.adicionarJogador(nome, apelido);

    Jogador buscado = gerenciador.buscarJogador(apelido);

    CHECK(buscado.getApelido().compare(apelido) == 0);
    CHECK(buscado.getNome().compare(nome) == 0);

  }

  TEST_CASE("Dado um apelido que nao foi adicionado lancar exceção"){
    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
    string apelido = "TESTE1";

    CHECK_THROWS_AS(gerenciador.buscarJogador(apelido), std::out_of_range);

  }
}

TEST_CASE("GerenciadorDeJogadores::adicionarRegistroDePartida: dado um registro valido salvar ele"){
  shared_ptr<GerenciadorDeJogadores> gerenciador(new GerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt"));
  string nome = "TESTE PESSOA 1";
  string apelido = "TESTE1";
  Jogo jogo1 = reversi;
  string nome2 = "TESTE PESSOA 2";
  string apelido2 = "TESTE2";
  Jogo jogo2 = jogoDaVelha;

  gerenciador.get()->adicionarJogador(nome, apelido);
  gerenciador.get()->adicionarJogador(nome2, apelido2);
  gerenciador.get()->adicionarRegistroDePartida(apelido, jogo1, true, 10);
  gerenciador.get()->adicionarRegistroDePartida(apelido2, jogo2, true);

  gerenciador.get()->salvarJogadores();
  gerenciador.get()->salvarPartidas();

  gerenciador.reset(new GerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt"));

  CHECK(gerenciador.get()->getRegistrosDePartida(apelido).size() == 1);
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido).front().getApelidoJogador().compare(apelido) == 0);
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido).front().getGanhou());
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido).front().getJogo() == jogo1);
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido).front().getPontuacao() == 10);

  CHECK(gerenciador.get()->getRegistrosDePartida(apelido2).size() == 1);
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido2).front().getApelidoJogador().compare(apelido2) == 0);
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido2).front().getGanhou());
  CHECK(gerenciador.get()->getRegistrosDePartida(apelido2).front().getJogo() == jogo2);

  gerenciador.get()->removerJogador(apelido);
  gerenciador.get()->removerJogador(apelido2);
  gerenciador.get()->clearRegistrosPartidas();

  gerenciador.get()->salvarJogadores();
  gerenciador.get()->salvarPartidas();

}

TEST_SUITE("GerenciadorDeJogadores::exibirJogadores: ")
{
  TEST_CASE("Dado um jogador valida ser a impressao dele foi correta"){
    ostringstream buffer;
    // Redireciona `cout` para o buffer
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");  
    string nome = "TESTE PESSOA 1";
    string apelido = "TESTE1";

    gerenciador.adicionarJogador(nome, apelido);
    gerenciador.exibirJogadores();
    
    // Restaura o buffer original de `cout`
    cout.rdbuf(original);  
    
    CHECK(buffer.str() == "TESTE PESSOA 1 - [TESTE1]\nREVERSI - V: 0 D: 0\nLIG4 - V: 0 D: 0\nVELHA - V: 0 D: 0\n\n");
  }

  TEST_CASE("Dado que nao tem jogadores validar se a impressao informa isso"){
    ostringstream buffer;
    // Redireciona `cout` para o buffer
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    GerenciadorDeJogadores gerenciador("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");  
  
    gerenciador.exibirJogadores();
    
    // Restaura o buffer original de `cout`
    cout.rdbuf(original);  
    
    CHECK(buffer.str() == "Nenhum jogador adicionado ainda\n");
  }
}