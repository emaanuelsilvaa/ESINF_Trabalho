
/* 
 * File:   main.cpp
 * Author: 1130647 e 1130648
 *
 * Created on 13 de Outubro de 2014, 22:29
 */

#include <cstdlib>
#include "Deposito.h"
#include "DepositoFresco.h"
#include "Produto.h"
#include "DepositoNormal.h"
#include "SimuladorArmazem.h"
#include "Armazem.h"
#include "LerFicheiro.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SimuladorArmazem s;
    vector<Produto> prod;
    prod = s.expedirProdutos(3);
    cout << s << endl;
    
    printf("\n ------------------------------------------------------------ \n");
    
    cout << *s.getGrafosDepositos() << endl;
    return 0;

}
