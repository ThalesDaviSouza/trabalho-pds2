#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

using namespace std;

class Jogador{
private:
  string Nome;
  string Apelido;

public:
  string getNome();
  string getApelido();

};


#endif