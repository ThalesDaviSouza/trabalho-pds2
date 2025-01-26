#include "./third-party/doctest.h"
#include "./../shared/Utils.hpp"
#include <sstream>
#include <iostream>
#include <string>

TEST_CASE("Shared - clearBuffer: validar se o buffer esta sendo limpo") {
    istringstream input("12345\n"); 
    streambuf* antigoCin = cin.rdbuf(input.rdbuf()); 
    
    clearBuffer();
    
    string teste;
    getline(cin, teste);
    cin.rdbuf(antigoCin); 
    
    CHECK(teste.empty()); 
}

TEST_CASE("Shared - imprimirCores: validar se está imprimindo as cores certas") {
    ostringstream buffer;
    // Redireciona `cout` para o buffer
    streambuf* original = cout.rdbuf(buffer.rdbuf());  

    imprimirCores();

    // Restaura o buffer original de `cout`
    cout.rdbuf(original);  
    
    CHECK(buffer.str() == "...[B] - Branco\n...[P] - Preto\n...[A] - Amarelo\n...[V] - Vermelho\n...[X] - X\n...[O] - O\n");
}

