//
//  main.cpp
//  Lab_6
//
#include <iostream>
#include <locale>
#include <fstream>
#include "Func.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    int a=0, b=0; int Mass[10000];
    
    *Mass = *Masiv::FunInput(a, b, Mass);
    
    *Mass = *Masiv::FunSmena(a, b, Mass);
    
    Masiv::FunOutput(a, b, Mass);
    
    return 0;
}
