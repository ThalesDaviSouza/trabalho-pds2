#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H

enum MenuOptions {
  nenhuma = 0,
  voltar = -2,
  // Opções do menu principal
  // Até o 100 por precaução
  fecharPrograma = -1,
  gerenciarJogos = 1,
  gerenciarJogadores = 2,

  // Opções do menu de jogos [100-199]
  adicionarJogadorPartida = 100,
  listarJogadoresPartida = 101,
  listarJogadoresCadastrados = 102,
  iniciarJogo = 103,
  jogarJogoDaVelha = 104,
  jogarReversi = 105,
  jogarLig4 = 106,

  // Opções do menu de Jogadores [200-299]
  adicionarJogador = 200,
  removerJogador = 201,
  exibirJogadores = 202,


};

#endif