#include "./third-party/doctest.h"
#include "./../include/gerenciadorDeJogos.hpp"
#include "./../include/gerenciadorDeJogadores.hpp"
#include <sstream>
#include <iostream>
#include <string>

TEST_SUITE("GerenciadorDeJogos::selecionarJogador")
{
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  Jogador jogador1("NOME1", "APL1");
  Jogador jogador2("NOME2", "APL2");

  TEST_CASE("adicionarJogador: Dado um jogador adicionar ele na lista de jogadores da partida"){
    gerenciador.adicionarJogador(jogador1, Branco);
    gerenciador.adicionarJogador(jogador2, Preto);

    CHECK(gerenciador.getQuantidadeJogadores() == 2);
  }

  TEST_CASE("removerJogadorPartida: Dado um apelido, remover o jogador da partida"){
    gerenciador.removerJogadorPartida(jogador2.getApelido());

    CHECK(gerenciador.getQuantidadeJogadores() == 1);
  }
}

TEST_SUITE("GerenciadorDeJogos::solicitarCorJogador") {
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  Jogador jogador1("NOME1", "APL1");


  TEST_CASE("Dar uma cor valida, selecionar ela") {
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());

    // Redireciona cin para simular a entrada
    istringstream input("V\n");
    cin.rdbuf(input.rdbuf());  

    Cor corSelecionada = gerenciador.solicitarCorJogador("Escolha uma cor: ");
    
    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(corSelecionada == Vermelho);
  }

  TEST_CASE("Dada uma cor que ja esta em uso selecionar outra") {
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());

    gerenciador.adicionarJogador(jogador1, Vermelho);

    // Simula entrada: Vermelho, depois Amarelo
    istringstream input("V\nA\n");
    cin.rdbuf(input.rdbuf());  

    Cor corSelecionada = gerenciador.solicitarCorJogador("Escolha uma cor: ");

    // Amarelo deve ser selecionado, pois Vermelho já está em uso
    CHECK(corSelecionada == Amarelo);  
    
    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 
  }

}

TEST_CASE("GerenciadorDeJogos::imprimirJogadores"){
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  string nome1 = "N1";
  string apelido1 = "A1";
  
  SUBCASE("Caso nao tenha jogadores, imprimir mensagem de informativa"){
    ostringstream buffer;
    // Redireciona `cout` para o buffer
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    gerenciador.imprimirJogadores();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(buffer.str() == "* - Sem jogadores selecionados no momento\n");

  }

  SUBCASE("Dado 1 jogador valido, imprimir o jogador"){
     ostringstream buffer;
    // Redireciona `cout` para o buffer
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    gerenciadorDeJogadores.adicionarJogador(nome1, apelido1);
    Jogador Jogador1 = gerenciadorDeJogadores.buscarJogador(apelido1);
    gerenciador.adicionarJogador(Jogador1, X);
    gerenciador.imprimirJogadores();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(buffer.str() == "Jogadores Atuais:\n#1 - N1 (A1)\n\n\n");
  }
}

TEST_CASE("GerenciadorDeJogos::selecionarJogador") {
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  string nome1 = "N1";
  string apelido1 = "A1";
  string nome2 = "N2";
  string apelido2 = "A2";

  gerenciadorDeJogadores.adicionarJogador(nome1, apelido1);
  gerenciadorDeJogadores.adicionarJogador(nome2, apelido2);

  SUBCASE("Dado o id de um jogador valido e uma cor valida, adicionar o jogador"){  
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    // Redireciona cin para simular a entrada
    // 0 -> Adicionar jogador na primeira posição 
    // B -> Escolher o time Branco 
    // -2 -> Fechar seleção 
    istringstream input("0\nB\n-2\n");
    cin.rdbuf(input.rdbuf());  

    gerenciador.selecionarJogador();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(gerenciador.getQuantidadeJogadores() == 1);
  }

  SUBCASE("Dado 2 ids de jogador valido e 2 cores validas, adicionar os 2 jogadores"){  
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    // Redireciona cin para simular a entrada
    // 0 -> Adicionar jogador na primeira posição 
    // B -> Escolher o time Branco 
    // 1 -> Adicionar jogador na segunda posição 
    // P -> Escolhe o time Preto 
    // -2 -> Fechar seleção 
    istringstream input("0\nB\n1\nP\n-2\n");
    cin.rdbuf(input.rdbuf());  
    
    gerenciador.selecionarJogador();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(gerenciador.getQuantidadeJogadores() == 2);
  }
  
  SUBCASE("Dado 1 jogador que ja esta adicionado, trocar a cor dele"){  
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    // Redireciona cin para simular a entrada
    // 0 -> Adicionar jogador na primeira posição 
    // B -> Escolher o time Branco 
    // 0 -> Selecionar jogador na primeira posição 
    // 2 -> Selecionar para alterar a cor 
    // P -> Trocar o time para o time Preto 
    // -2 -> Fechar seleção 
    istringstream input("0\nB\n0\n2\nP\n-2\n");
    cin.rdbuf(input.rdbuf());  
    
    gerenciador.selecionarJogador();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(gerenciador.getQuantidadeJogadores() == 1);
  }
  
  SUBCASE("Dado 1 jogador que ja esta adicionado, remover ele"){  
    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    // 0 -> Adicionar jogador na primeira posição 
    // B -> Escolher o time Branco 
    // 0 -> Selecionar jogador na primeira posição 
    // 1 -> Selecionar para remover o jogador  
    // -2 -> Fechar seleção 
    istringstream input("0\nB\n0\n1\n-2\n");
    // Redireciona cin para simular a entrada
    cin.rdbuf(input.rdbuf());  
    
    gerenciador.selecionarJogador();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original); 

    CHECK(gerenciador.getQuantidadeJogadores() == 0);
  }

}

TEST_CASE("GerenciadorDeJogos::JogarJogoDaVelha"){
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  string nome1 = "N1";
  string apelido1 = "A1";
  string nome2 = "N2";
  string apelido2 = "A2";

  gerenciadorDeJogadores.adicionarJogador(nome1, apelido1);
  gerenciadorDeJogadores.adicionarJogador(nome2, apelido2);

  Jogador jogador1 = gerenciadorDeJogadores.buscarJogador(apelido1); 
  Jogador jogador2 = gerenciadorDeJogadores.buscarJogador(apelido2); 

  gerenciador.adicionarJogador(jogador1, X);

  SUBCASE("Partida entre dois jogadores"){
    gerenciador.adicionarJogador(jogador2, O);

    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    istringstream input("1 1\n1 2\n2 2\n2 3\n3 3\n");
    // Redireciona cin para simular a entrada
    cin.rdbuf(input.rdbuf()); 

    gerenciador.JogarJogoDaVelha();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original);
    
    // Esse é um teste caixa preta
    // Validamos apenas se inserir as jogadas estão funcionando sem lançar nenhum erro
    CHECK(true);
  }
  SUBCASE("Partida contra IA"){

    // Redireciona `cout` para o buffer
    ostringstream buffer;
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    // entrada para a IA ganhar
    istringstream input("1 1\n2 2\n3 2\n");
    // Redireciona cin para simular a entrada
    cin.rdbuf(input.rdbuf()); 

    gerenciador.JogarJogoDaVelha();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original);

    // Esse é um teste caixa preta
    // Validamos apenas se inserir as jogadas estão funcionando sem lançar nenhum erro
    CHECK(true);
  }
}

TEST_CASE("GerenciadorDeJogos::JogarLig4"){
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  string nome1 = "N1";
  string apelido1 = "A1";
  string nome2 = "N2";
  string apelido2 = "A2";

  gerenciadorDeJogadores.adicionarJogador(nome1, apelido1);
  gerenciadorDeJogadores.adicionarJogador(nome2, apelido2);

  Jogador jogador1 = gerenciadorDeJogadores.buscarJogador(apelido1); 
  Jogador jogador2 = gerenciadorDeJogadores.buscarJogador(apelido2); 

  gerenciador.adicionarJogador(jogador1, X);
  gerenciador.adicionarJogador(jogador2, O);

  // Redireciona `cout` para o buffer
  ostringstream buffer;
  streambuf* original = cout.rdbuf(buffer.rdbuf());  

  istringstream input("1\n2\n1\n2\n1\n2\n1\n");
  // Redireciona cin para simular a entrada
  cin.rdbuf(input.rdbuf()); 

  gerenciador.JogarLig4();

  // Restaura o buffer original de `cout`
  cout.rdbuf(original);
  
  // Esse é um teste caixa preta
  // Validamos apenas se inserir as jogadas estão funcionando sem lançar nenhum erro
  CHECK(true);
}

TEST_CASE("GerenciadorDeJogos::JogarReversi"){
  GerenciadorDeJogadores gerenciadorDeJogadores("data_test", "dados_jogadores_test.txt", "dados_partidas_test.txt");
  GerenciadorDeJogos gerenciador(gerenciadorDeJogadores);
  string nome1 = "N1";
  string apelido1 = "A1";
  string nome2 = "N2";
  string apelido2 = "A2";

  gerenciadorDeJogadores.adicionarJogador(nome1, apelido1);
  gerenciadorDeJogadores.adicionarJogador(nome2, apelido2);

  Jogador jogador1 = gerenciadorDeJogadores.buscarJogador(apelido1); 
  Jogador jogador2 = gerenciadorDeJogadores.buscarJogador(apelido2); 

  gerenciador.adicionarJogador(jogador1, Branco);
  gerenciador.adicionarJogador(jogador2, Preto);

  // Redireciona `cout` para o buffer
  ostringstream buffer;
  streambuf* original = cout.rdbuf(buffer.rdbuf());  

  istringstream input("4 3\n5 3\n6 4\n3 3\n4 2\n5 2\n6 3\n5 1\n6 1\n7 1\n4 1\n7 3\n6 2\n3 1\n6 5\n7 6\n8 3\n7 2\n6 6\n6 7\n7 4\n7 5\n8 1\n8 2\n2 1\n3 6\n2 7\n3 5\n6 8\n8 4\n2 5\n1 5\n3 2\n1 8\n8 5\n7 7\n5 6\n5 7\n5 8\n4 8\n4 6\n4 7\n3 8\n3 7\n2 8\n7 8\n8 7\n8 6\n8 8\n3 4\n2 4\n2 3\n1 4\n1 3\n1 7\n 1 6\n2 6\n2 2\n1 1\n");
  // Redireciona cin para simular a entrada
  cin.rdbuf(input.rdbuf()); 

  gerenciador.JogarReversi();

  // Restaura o buffer original de `cout`
  cout.rdbuf(original);
  
  // Esse é um teste caixa preta
  // Validamos apenas se inserir as jogadas estão funcionando sem lançar nenhum erro
  CHECK(true);
}
