#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>

using namespace std;

inline void clearBuffer(){
  string lixo;
  cin.clear();
  getline(cin, lixo);
}

#endif