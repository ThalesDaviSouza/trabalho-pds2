#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H

enum MenuOptions {
  nenhuma = 0,
  voltar = -2,
  // Opções do menu principal
  // Até o 100 por precaução
  fecharPrograma = -1,
  gerenciarJogadores = 2,


  // Opções do menu de Jogadores [200-299]
  adicionarJogador = 200,
  removerJogador = 201,
  exibirJogadores = 202,

};

#endif