
/* 
 * File:   main.cpp
 * Author: Paulo
 *
 * Created on 13 de Outubro de 2014, 22:29
 */

#include <cstdlib>
#include "Deposito.h"
#include "DepositoFresco.h"
#include "Produto.h"
#include "DepositoNormal.h"

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Deposito d;
    DepositoNormal dn;
    dn.setCapacidade(4);
    dn.setNumeroPaletes(4);
    
    
    Produto pd("aaaa");
    Produto pd1("aaaa");
    Produto pd3("aaaa");
    Produto pd4("aaaa");
    Produto pd5("aaaa");
    vector<Produto> prod;
    
    
          prod.push_back(pd);
          prod.push_back(pd1);
          prod.push_back(pd3);
          prod.push_back(pd4);
          prod.push_back(pd5);


    
    dn.inserirProdutos(prod);
    dn.expedirVarios(3);
    
    DepositoNormal dn2;
    dn2.setCapacidade(4);
    dn2.setNumeroPaletes(4);
    
    
    Produto pd0("aaaa");
    Produto pd01("aaaa");
    Produto pd03("aaaa");
    Produto pd04("aaaa");
    Produto pd05("aaaa");
    vector<Produto> prod2;
    
    
          prod2.push_back(pd0);
          prod2.push_back(pd01);
          prod2.push_back(pd03);
          prod2.push_back(pd04);
          prod2.push_back(pd05);


    
    dn2.inserirProdutos(prod2);
    dn2.expedirVarios(3);
    cout << dn2 <<endl;
    return 0;
    
}
