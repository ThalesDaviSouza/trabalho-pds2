#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
#include <vector>
#include "./../Enums/Cor.cpp"

using namespace std;

class Tabuleiro{
protected: 
    int colunas;
    int linhas;
    vector<vector<int>> tabuleiro_;

public:
    Tabuleiro(int colunas_, int linhas_);
    void printTabuleiro();
    virtual bool verificarJogada(int x, int y, Cor cor);
    virtual void fazerJogada(int x, int y, Cor cor);
};

class Tabuleiro_Lig4 : public Tabuleiro{ 
    public:
     Tabuleiro_Lig4();
     bool verificarJogada(int x, int y, Cor cor) override;
     void fazerJogada (int y)override;
     bool verificarVitoria(int tabuleiro_[6][7]);
}; 

class Tabuleiro_JogoDaVelha : public Tabuleiro{ 
    public:
     Tabuleiro_JogoDaVelha(int linhas_, int colunas_);
     bool verificarJogada(int x, int y, Cor cor) override;
     void fazerJogada(int x, int y, Cor cor) override;
     bool verificarVitoria();
};

class Tabuleiro_Reversi : public Tabuleiro{ 
     public:
     Tabuleiro_Reversi(int linhas_, int colunas_);
     bool verificarJogada(int x, int y, Cor cor) override;
     void fazerJogada(int x, int y, Cor cor) override;
     bool verificarVitoria();
};

#endif