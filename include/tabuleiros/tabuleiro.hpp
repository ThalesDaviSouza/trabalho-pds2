#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
#include <vector>
#include "./../../Enums/Cor.cpp"

/**
 * @brief Definições  do tamanho máximo do tabuleiro de Lig4 e a contagem necessária de peças para vitória.
 */
#define COLUNAS_LIG4 7
#define LINHAS_LIG4 6
#define QTD_VITORIA_LIG4 4

/**
 * @brief Definições do tamanho máximo do tabuleiro de Joga da Velha e a contagem necessária de peças para vitória.
 */
#define COLUNAS_VELHA 3
#define LINHAS_VELHA 3
#define QTD_VITORIA_VELHA 3

#define COLUNAS_REVERSI 8
#define LINHAS_REVERSI 8

using namespace std;

/**
 * @class Tabuleiro
 *
 * @brief Representa a Classe mãe dos tabuleiros.
 */
class Tabuleiro
{
protected:
    int colunas;                    /** Quantidade de colunas do tabuleiro. */
    int linhas;                     /** Quantidade de linhas do tabuleiro. */
    vector<vector<Cor>> tabuleiro_; /** Vetor de vetores que cria a matriz para representar cada tabuleiro. */
    int linhaUltimaJogada = -1;     /** Linha da última jogada. */
    int colunaUltimaJogada = -1;    /** Coluna da última jogada. */
    Cor corUltimaJogada = Vazio;    /** Cor do jogador responsável pela última jogada. */

    /**
     * @brief Verifica se a jogada realizada entá dentro dos limites do tabuleiro.
     *
     * @param linha Corresponde à linha da jogada.
     * @param coluna Corresponde à coluna da jogada.
     * @return A linha e a coluna caso estejam nos limites do tabuleiro.
     */
    bool posicaoEhValida(int linha, int coluna);

    /**
     * @brief A função verifica, a partir da posição de uma jogada, se há peças iguais consecutivas suficientes na horizontal
     * do tabuleiro, para atender ao valor de `quantParaVitoria`, determinando um vencedor.
     *
     * @param linha Linha correspondente à jogada.
     * @param coluna Coluna correspondente à jogada.
     * @param quantParaVitoria Número de peças iguais consecutivas necessário para vencer.
     *
     * @return True se a peça analisada forma uma sequência vencedora.
     * @return False caso contrário.
     */
    virtual bool verificarHorizontal(int linha, int coluna, int quantParaVitoria);

    /**
     * @brief A função verifica, a partir da posição de uma jogada, se há peças iguais consecutivas suficientes na vertical
     * do tabuleiro, para atender ao valor de `quantParaVitoria`, determinando um vencedor.
     *
     * @param linha Linha correspondente à jogada.
     * @param coluna Coluna correspondente à jogada.
     * @param quantParaVitoria Número de peças iguais consecutivas necessário para vencer.
     *
     * @return True se a peça analisada forma uma sequência vencedora. False caso contrário.
     */
    virtual bool verificarBaixo(int linha, int coluna, int quantParaVitoria);

    /**
     * @brief A função verifica, a partir da posição de uma jogada, se há peças iguais consecutivas suficientes na diagonal direcionada para baixo
     * do tabuleiro, para atender ao valor de `quantParaVitoria`, determinando um vencedor.
     *
     * @param linha Linha correspondente à jogada.
     * @param coluna Coluna correspondente à jogada.
     * @param quantParaVitoria Número de peças iguais consecutivas necessário para vencer.
     *
     * @return True se a peça analisada forma uma sequência vencedora. False caso contrário.
     */
    virtual bool verificarDiagonalBaixo(int linha, int coluna, int quantParaVitoria);

    /**
     * @brief A função verifica, a partir da posição de uma jogada, se há peças iguais consecutivas suficientes na diagonal direcionada para cima
     * do tabuleiro, para atender ao valor de `quantParaVitoria`, determinando um vencedor.
     *
     * @param linha Linha correspondente à jogada.
     * @param coluna Coluna correspondente à jogada.
     * @param quantParaVitoria Número de peças iguais consecutivas necessário para vencer.
     *
     * @return True se a peça analisada forma uma sequência vencedora. False caso contrário.
     */
    virtual bool verificarDiagonalCima(int linha, int coluna, int quantParaVitoria);

public:
    /**
     * @brief Construtor da classe 'Tabuleiro'.
     *
     * @param colunas_ Quantidade de colunas do tabuleiro.
     * @param linhas_ Quantidade de linhas do tabuleiro.
     */
    Tabuleiro(int colunas_, int linhas_);

    /**
     * @brief Imprime o tabuleiro na tela
     */
    void printTabuleiro();

    /**
     * @brief Verifica se a jogada é válida de acordo com as regras do jogo selecionado.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     *
     * @return True se a jogada é válida. False caso contrário.
     */
    virtual bool verificarJogada(int linha, int coluna, Cor cor);

    /**
     * @brief Caso a função 'verificarJogada' retornar true, essa função é responsável por fazer a jogada.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     */
    virtual void fazerJogada(int linha, int coluna, Cor cor) = 0;

    /**
     * @brief Esta função deve ser implementada pelas classes derivadas para percorrer todo o tabuleiro e
     * verificar se houve algum vencedor na partida, de acordo com as regras específicas de cada jogo.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que está fazendo a jogada.
     *
     * @return True se alguma vitória foi encontrada. False caso contrário.
     */
    virtual bool verificarVitoria() = 0;

    /**
     * @brief Método que permite acessar o atributo 'LinhaUltimaJogada' da classe 'Tabuleiro'.
     */
    int getLinhaUltimaJogada();

    /**
     * @brief Método que permite acessar o atributo 'ColunaUltimaJogada' da classe 'Tabuleiro'.
     */
    int getColunaUltimaJogada();
};

/**
 * @class Tabuleiro_Lig4.
 *
 * @brief Classe filha de 'Tabuleiro', representa os tabuleiros de Lig4.
 */
class Tabuleiro_Lig4 : public Tabuleiro
{
private:

    /**
     * @brief  Função responsável por encontrar a linha vazia da coluna escolhida no tabuleiro.
     * 
     * @throw invalid_argument se a coluna estiver cheia.
     *
     * @return A linha vazia da coluna escolhida. 
     */
    int getLinhaVazia(int coluna); 

public:
    /**
     * @brief Construtor da classe 'Tabuleiro_Lig4'. A inicialização ocorrerá na chamada do construtor
     * da classe mãe 'Tabuleiro' utilizando a lista de inicialização para passar o número de linhas e colunas.
     */
    Tabuleiro_Lig4();

    /**
     * @brief Essa função verifica se a jogada é válida de acordo com as seguintes regras do Lig4:
     *
     * - A jogada deve ser feita em uma coluna existente;
     *
     * - A coluna deve ter no mínimo 1 espaço vazio;
     *
     * - A peça sempre "cai" na parte mais baixa disponível da coluna.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     * 
     * @throw invalid_argument caso a jogada seja feita em uma coluna não existente no tabuleiro.
     *
     * @return True se a jogada é válida. False caso contrário.
     *
     * @note O parâmetro 'linha' é desconsiderado no momento da implementação.
     */
    bool verificarJogada(int linha, int coluna, Cor cor) override;

    /**
     * @brief Essa função redireciona a chamada para a função 'fazerJogada(int coluna, Cor cor)' e existe
     * para atender a interface da classe 'Tabuleiro'.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     */
    void fazerJogada(int linha, int coluna, Cor cor) override;

    /**
     * @brief Caso a função 'verificarJogada' retorne true, essa função é responsável por fazer a jogada.
     *
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     * 
     * @throw invalid_argument caso a coluna esteja cheia.
     */
    void fazerJogada(int coluna, Cor cor);

    /**
     * @brief Verifica se houve vencedor na partida.
     *
     * Esta função é responsável por percorrer todo o tabuleiro e verificar se houve algum vencedor
     * na partida, o que ocorre quando existem 4 peças do mesmo jogador consecutivas na diagonal,
     * horizontal ou vertical do tabuleiro.
     *
     * @return True se alguma vitória foi encontrada. False caso contrário.
     */
    virtual bool verificarVitoria();
};

/**
 * @class Tabuleiro_JogoDaVelha.
 *
 * @brief Classe filha de 'Tabuleiro', representa os tabuleiros do Jogo da Velha.
 */
class Tabuleiro_JogoDaVelha : public Tabuleiro
{
public:
    /**
     * @brief Construtor da classe 'Tabuleiro_JogoDaVelha'. A inicialização ocorrerá na chamada do construtor
     * da classe mãe 'Tabuleiro' utilizando a lista de inicialização para passar o número de linhas e colunas.
     */
    Tabuleiro_JogoDaVelha();

    /**
     * @brief Essa função verifica se a jogada é válida de acordo com as seguintes regras do Jogo da
     * Velha:
     *
     * - A jogada deve ser feita em uma coluna e linha existentes;
     *
     * - O espaço escolhido deve estar vazio.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     *
     * @return True se a jogada é válida. False caso contrário.
     */
    bool verificarJogada(int linha, int coluna, Cor cor) override;

    /**
     * @brief Caso a função 'verificarJogada' retorne true, essa função é responsável por fazer a jogada.
     *
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param cor Cor do jogador que efetuou a jogada.
     */
    void fazerJogada(int linha, int coluna, Cor cor) override;

    /**
     * @brief Verifica se houve vencedor na partida.
     *
     * Essa função é responsável por percorrer todo o tabuleiro e verificar se houve algum vencedor
     * na partida, o que ocorre quando existem 3 peças do mesmo jogador consecutivas na diagonal,
     * horizontal ou vertical do tabuleiro.
     *
     * @return True se alguma vitória foi encontrada. False caso contrário.
     */
    bool verificarVitoria() override;
};

class Tabuleiro_Reversi : public Tabuleiro{ 
     public:
     Tabuleiro_Reversi(int linhas_, int colunas_);
     bool verificarJogada(int linha, int coluna, Cor cor) override;
     void fazerJogada(int linha, int coluna, Cor cor) override;
     bool verificarVitoria() override;
};

#endif