#include <iostream>
#include "./../../include/tabuleiro.hpp"

using namespace std;

Tabuleiro_Lig4::Tabuleiro_Lig4() : Tabuleiro(6, 7) {};

bool Tabuleiro_Lig4::verificarJogada(int x, int y, Cor cor) 
{
    /* REGRAS
    -o tabuleiro é preenchido de cima para baixo
    -se uma peça foi colocada embaixo, a outra vai em cima
    -só podem em espaços vazios
    */

    // verifica se a jogada foi feita nos limites do tabuleiro
    if (y < 0 || y >= 7)
    {
        cout << "Jogada fora do tabuleiro" << endl;
        return false;
    }

    // verifica qual a posição disponível na coluna escolhida
    for (int i = 5; i >= 0; i--)
    {
        if (tabuleiro_[i][y] == 0)
            return true;
    }

    throw invalid_argument("jogada inválida");

}

void Tabuleiro_Lig4::fazerJogada(int x, int y, Cor cor)
{
    if (verificarJogada(x, y, cor))
    {
        tabuleiro_[x][y] = cor;
    }
};

bool Tabuleiro_Lig4::verificarVitoria(int x, int y, Cor cor_atual) //TODO: como tirar tabuleiro de parametros
{

    /*
    DIREÇÕES PARA VERIFICAR VITÓRIA

    Horizontal para direita: (x, y+ )
    Horizontal para esquerda: (x, y-)
    Vertical para baixo: (x+, y)
    Vertical para cima: (x-, y)
    diagonal / para baixo: (x+,y-)
    diagonal / para cima: (x-, y+)
    diagonal \ para baixo: (x+, y+)
    diagonal \ para cima: (x-, y-)

    */
    tabuleiro_[x][y] = cor_atual; // A cor da peça atual
    int contador = 1;                // Conta peças consecutivas

    //Verificar horizontal para a direita
    contador = 1; // Reseta o contador
    for (int i = 1; i < 4; i++)
    { // Verificando até 3 casass
        if (y + i < 7 && tabuleiro_[x][y + i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar horizontal para a esquerda
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (y - i >= 0 && tabuleiro_[x][y - i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar vertical para baixo
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (x + i < 6 && tabuleiro_[x + i][y] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar diagonal principal (\) para baixo e direita
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (x + i < 6 && y + i < 7 && tabuleiro_[x + i][y + i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar diagonal principal (\) para cima e esquerda
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (x - i >= 0 && y - i >= 0 && tabuleiro_[x - i][y - i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar diagonal secundária (/) para baixo e esquerda
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (x + i < 6 && y - i >= 0 && tabuleiro_[x + i][y - i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    //Verificar diagonal secundária (/) para cima e direita
    contador = 1;
    for (int i = 1; i < 4; i++)
    {
        if (x - i >= 0 && y + i < 7 && tabuleiro_[x - i][y + i] == cor_atual)
        {
            contador++;
        }
        else
        {
            break;
        }
    }
    if (contador >= 4)
        return true;

    // Se nenhuma vitória foi encontrada
    return false;
}
