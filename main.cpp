/* 
 * File:   main.cpp
 * Author: Miguel
 *
 * Created on 9 de Outubro de 2014, 10:43
 */

#include <cstdlib>
#include "Deposito.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Deposito d;
    Deposito a;
    
    a.setChave("0069");
    
    d.inserirDistancia(a,20);
    cout << d << endl;
    return 0;
}

