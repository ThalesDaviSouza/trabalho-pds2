#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

using namespace std;

class Jogador{
private:
  /**
   * @brief Nome do Jogadro.
   */
  string Nome;

  /**
   * @brief Apelido do Jogadro.
   */
  string Apelido;

public:
  
  /**
   * @brief Construtor padrão da class.
   * 
   * @param nome Nome do Jogador
   * @param apelido Apelido do Jogador (deve ser único)
   */
  Jogador(string nome, string apelido);

  /**
   * @brief Retorna o nome do joogador.
   */
  string getNome();

  /**
   * @brief Retorna o apelido do joogador.
   */
  string getApelido();

};


#endif