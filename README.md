# Projeto Final - PDS 2
## O problema
O projeto final de Programação de Software 2 (PDS 2) tem como objetivo implementar um sistema que permita aos usuários jogar e gerenciar três jogos de tabuleiro clássicos: Jogo da Velha, Lig4 e Reversi. 

O sistema deve oferecer uma experiência intuitiva para os jogadores, permitindo que eles:

- `Cadastro de Jogadores`: Criem um perfil com informações básicas para identificação.
- `Histórico de Jogos`: Acompanhem seu desempenho em cada um dos jogos, registrando vitórias, derrotas e empates.
- `Jogabilidade Dinâmica`: Possam competir em partidas individuais contra outros jogadores ou, eventualmente, contra uma IA.

Além disso, o projeto exige o uso de boas práticas de programação orientada a objetos (POO), incluindo modularidade, encapsulamento e reaproveitamento de código. O sistema deve ser estruturado de forma a permitir futuras expansões, como a adição de novos jogos ou funcionalidades.

Este projeto busca consolidar o aprendizado de técnicas avançadas de programação, aplicação de padrões de design e integração de componentes, além de proporcionar uma solução divertida e interativa para os usuários.

## A Solução 
Para atender aos requisitos do projeto, foi desenvolvido um sistema modular que integra os três jogos de tabuleiro – **Jogo da Velha, Lig4 e Reversi** – juntamente com funcionalidades de gerenciamento de jogadores e histórico de partidas. A solução foi estruturada com base nos princípios da programação orientada a objetos (POO), priorizando reutilização de código, organização e facilidade de manutenção.

### Principais Componentes da Solução
- `Cadastro de Jogadores`: Implementação de um sistema de registro que permite aos usuários criar e gerenciar perfis individuais. Cada perfil armazena informações relevantes, como nome, apelido (único) e histórico de partidas.

- `Jogos Implementados`: 
  - **Jogo da Velha**: Um clássico de estratégia em que dois jogadores competem para alinhar três símbolos em uma grade 3x3.
  - **Lig4**: Um jogo onde dois participantes alternam a inserção de peças em uma grade 6x7, com o objetivo de formar uma sequência de quatro peças na horizontal, vertical ou diagonal.
  - **Reversi**: Um desafio estratégico em uma grade 8x8, onde os jogadores competem para capturar e converter o maior número de peças adversárias.

- `Histórico de Partidas`: Armazena os resultados das partidas (vitórias, derrotas e empates) para cada jogador. Permite a consulta e exibição de estatísticas.

- `Interface Simples e Intuitiva`: As interações dos jogos e o gerenciamento de jogadores foram projetados para serem simples e acessíveis por meio de um sistema de menu organizado. O menu permite que os usuários naveguem facilmente entre opções como cadastro de jogadores, seleção de jogos e consulta de jogadores. Além disso, o sistema oferece feedbacks visuais claros para o estado do jogo e resultados.

- `Arquitetura Orientada a Objetos`: Cada jogo é implementado como uma classe separada que herdam da mesma classe tabuleiro, com lógica específica encapsulada e métodos para interação.

## Divisão das tarefas:
As responsabilidades do projeto foram dividas da seguinte forma:
- `Ítalo Leal:` 
  - Implementação do Makefile.
  - Adicionar o doctest no projeto.
  - Implementação de parte dos testes.

- `Julia Natalie:` 
  - Implementação do Jogo da Velha.
  - Implementação do Lig4.
  - Documentação do Projeto.

- `Thales Davi:`
  - Implementação do **gerenciador de jogadores**.
    - Salvar jogadores.
    - Salvar registros de partidas para montar as estatísticas.
  - Implementação do jogo Reversi.
  - Implementação dos menus em lógica de pilha.
  - Implementação do gerenciador de jogos (integração jogos de tabuleiro com a interface).
  - Implementação do algoritmo minimax.

- `Vitor Hugo:`
  - Funcionalidade de remover jogadores.
  - Implementação de grande parte dos testes.
  - Adicionar gcovr para gerar relatório de cobertura.
  - Adicionar o doxygen ao projeto.

## Extras:
As funcionalidades extras que foram adicionadas ao trabalho foram:

- `Menus:` Implementamos menus com lógica de pilha. Em outras palavras, a lógica de criação de um menu no sistema é altamente dinâmica permitindo sobreposições de menus (funcionamento similar a uma pilha) em que um menu pode abrir outro menu e no momento de fechar um menu o histórico de menus se mantêm. Essa funcionalidade evitou repetição na criação dos menus, permitindo que focassemos nossa atenção em outros detalhes. Além de obviamente, evitar a repetição exarcebada de linhas de código para implementar menus para os usuários.

- `Algoritmo minimax:` No jogo da velha implementamos um algoritmo minimax para jogar contra o jogador. 

- `Makefile:` Implementamos um Makefile dinâmico com capacidade de automaticamente detectar novos arquivos nas pastas *src* e *tests*. O que favoreceu muito a longo prazo no desenvolvimento do projeto, pois assim conseguimos adicionar vários arquivos sem ter nenhum retrabalho com o código do Makefile.

## Dificuldades:
- Separação das tarefas: apesar da definição inicial das tarefas, precisamos redistribuir as tarefas várias vezes e muitas vezes tivemos que realizar pair programming para funcionalidades mais complexas e tarefas mais extensas.
- Compilação em mais de um ambiente: como tinha membros do grupo que tinham windows e outros que possuiam linux, vimos várias vezes um código que compilava sem problemas em um ambiente, mas levantava erros no outro. O makefile que funcionava perfeitamente no windows, mas o formato da barra era diferente no linux e por isso precisava trocar... entre outros.

## Dependências:
Se por acaso o projeto não funcionar na sua máquina, tenha certeza de ter as seguintes dependências corretamente instaladas no seu sistema:
- C++ versão 14 ou superior.
- gcovr (se tiver o python pode ser instalado com o seguinte comando: *pip install gcovr*).
- doxygen (no linux pode ser instalado com o seguinte comando: *sudo apt install doxygen*).