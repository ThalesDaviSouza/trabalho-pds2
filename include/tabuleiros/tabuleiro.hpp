#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
#include <vector>
#include "./../../Enums/Cor.cpp"

#define COLUNAS_LIG4 7
#define LINHAS_LIG4 6
#define QTD_VITORIA_LIG4 4

#define COLUNAS_VELHA 3
#define LINHAS_VELHA 3
#define QTD_VITORIA_VELHA 3

using namespace std;

class Tabuleiro{
protected: 
    int colunas;
    int linhas;
    vector<vector<Cor>> tabuleiro_;
    int linhaUltimaJogada = -1;
    int colunaUltimaJogada = -1;
    Cor corUltimaJogada = Vazio;

    bool posicaoEhValida(int linha, int coluna);

    virtual bool verificarHorizontal(int linha, int coluna, int quantParaVitoria);
    virtual bool verificarBaixo(int linha, int coluna, int quantParaVitoria);
    virtual bool verificarDiagonalBaixo(int linha, int coluna, int quantParaVitoria);
    virtual bool verificarDiagonalCima(int linha, int coluna, int quantParaVitoria);

public:
    Tabuleiro(int colunas_, int linhas_);
    void printTabuleiro();
    virtual bool verificarJogada(int linha, int coluna, Cor cor);
    virtual void fazerJogada(int linha, int coluna, Cor cor) = 0;

    /**
     * @brief Valida se a condicao de vitória foi alcançada 
     */
    virtual bool verificarVitoria() = 0; 

    int getLinhaUltimaJogada();
    int getColunaUltimaJogada();
};

class Tabuleiro_Lig4 : public Tabuleiro{ 
    private: 
     int getLinhaVazia(int coluna);
     
    public:
     Tabuleiro_Lig4();
     bool verificarJogada(int linha, int coluna, Cor cor) override;
     void fazerJogada(int linha, int coluna, Cor cor) override;
     void fazerJogada(int coluna, Cor cor);
     virtual bool verificarVitoria(); 
}; 

class Tabuleiro_JogoDaVelha : public Tabuleiro{ 
    public:
     Tabuleiro_JogoDaVelha();
     bool verificarJogada(int linha, int coluna, Cor cor) override;
     void fazerJogada(int linha, int coluna, Cor cor) override;
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