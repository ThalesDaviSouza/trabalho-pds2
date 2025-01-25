#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include "./../Enums/Cor.cpp"

using namespace std;

inline void clearBuffer(){
  string lixo;
  cin.clear();
  getline(cin, lixo);
}

inline void imprimirCores(){
  cout << "...[" << static_cast<char>(Branco) << "] - Branco" << endl;
  cout << "...[" << static_cast<char>(Preto) << "] - Preto" << endl;
  cout << "...[" << static_cast<char>(Amarelo) << "] - Amarelo" << endl;
  cout << "...[" << static_cast<char>(Vermelho) << "] - Vermelho" << endl;
  cout << "...[" << static_cast<char>(X) << "] - X" << endl;
  cout << "...[" << static_cast<char>(O) << "] - O" << endl;
}

#endif