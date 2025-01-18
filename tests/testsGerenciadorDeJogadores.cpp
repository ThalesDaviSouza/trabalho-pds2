#include "./third-party/doctest.h"
#include "./../include/gerenciadorDeJogadores.hpp"

TEST_SUITE("Gerenciador de Jogadores: Adicionar jogadores"){
  TEST_CASE("Gerenciador de Jogadores: dado 1 nome e 1 apelido adicionar o jogador na lista"){
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
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
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
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
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    string apelido2 = "TESTE2";
    
    gerenciador.adicionarJogador(nome1, apelido1);

    CHECK(gerenciador.jogadorEhValido(apelido2));
  }

  TEST_CASE("Dado 1 apelido que ja esta em uso retornar falso"){
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
    string nome1 = "TESTE PESSOA 1";
    string apelido1 = "TESTE1";
    
    gerenciador.adicionarJogador(nome1, apelido1);

    CHECK_FALSE(gerenciador.jogadorEhValido(apelido1));
  }
}

TEST_SUITE("Gerenciador de Jogadores: Validar remocao de jogadores"){
  TEST_CASE("Dado 1 apelido remover ele da lista"){
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
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
    GerenciadorDeJogadores gerenciador("data", "dados_test.txt");
    
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
    GerenciadorDeJogadores * gerenciador = new GerenciadorDeJogadores("data", "dados_test.txt");
    
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

    gerenciador = new GerenciadorDeJogadores("data", "dados_test.txt");

    CHECK_FALSE(gerenciador->jogadorEhValido(apelido1));
    CHECK_FALSE(gerenciador->jogadorEhValido(apelido2));

    gerenciador->removerJogador(apelido1);
    gerenciador->removerJogador(apelido2);
    gerenciador->salvarJogadores();
    
    delete gerenciador;
  }
}