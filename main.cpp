
/* 
 * File:   main.cpp
 * Author: Miguel
 *
 * Created on 13 de Outubro de 2014, 22:29
 */

#include <cstdlib>
#include "Deposito.h"
#include "DepositoFresco.h"
#include "Produto.h"
#include "DepositoNormal.h"
#include "Armazem.h"

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Armazem a("n",20,20);
    Deposito d;
    map<string, double> m;
    d=a.criarDeposito(20,"A01",20,10,m);
    a.inserirDeposito(d);

    return 0;

}
