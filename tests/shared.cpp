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