#include "./../include/menus/menuItem.hpp"

#include <iostream>

using namespace std;

void MenuItem::imprimirLinha(){
  cout << "[" << this->valor << "] - " << this->texto << endl; 
}

int MenuItem::getValor(){
  return this->valor;
}

bool MenuItem::getAbreMenu(){
  return this->abreMenu;
}

bool MenuItem::getFechaMenu(){
  return this->fechaMenu;
}
