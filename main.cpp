/* 
 * File:   main.cpp
 * Author: Miguel
 *
 * Created on 9 de Outubro de 2014, 10:43
 */

#include <cstdlib>
#include "Deposito.h"
#include "DepositoFresco.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        //Deposito d;
    DepositoFresco df;
    df.setCapacidade(3);
    df.setNumeroPaletes(5);

    //d.inserirDistancia("0001",20);
    //cout << d << endl;
    Produto pd("Bananas");
    Produto pd1("Pêras");
    Produto pd3("Gatos");
    vector<Produto> prod;
    

    for (int i = 0; i < 15; i++) {
        
        if (i == 0) {
             prod.push_back(pd);
            continue;
        }
        if (i > 10) {
          prod.push_back(pd1);
            continue;
        }
        
         prod.push_back(pd3);
    }
    
    df.inserirProdutos(prod);
    cout << df <<endl;
    return 0;
}

