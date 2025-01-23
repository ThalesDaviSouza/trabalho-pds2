#include "./../third-party/doctest.h"
#include "./../../include/menus/menuItem.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("MenuItem::imprimirLinha: Dado um menu item validar a impressao"){
  int valor = 0;
  string texto = "TESTE";
  bool abreMenu = false;
  
  MenuItem item(valor, texto, false);
  ostringstream buffer;
  streambuf* original = cout.rdbuf(buffer.rdbuf());  
  
  item.imprimirLinha();
    
  cout.rdbuf(original);  

  CHECK(buffer.str() == "[0] - TESTE\n");
}
