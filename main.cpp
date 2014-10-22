
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
#include "SimuladorArmazem.h"

#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Deposito d;
//    DepositoNormal dn;
//    dn.setCapacidade(4);
//    dn.setNumeroPaletes(4);
//
//
//    Produto pd("aaaa");
//    Produto pd1("aaaa");
//    Produto pd3("aaaa");
//
//    vector<Produto> prod;
//
//
//    prod.push_back(pd);
//    prod.push_back(pd1);
//    prod.push_back(pd3);
//
//
//
//
//    dn.inserirProdutos(prod);
//
//
//    DepositoNormal dn2;
//    dn2.setCapacidade(4);
//    dn2.setNumeroPaletes(4);
//
//    Produto pd0("aaaa");
//    Produto pd01("aaaa");
//    Produto pd03("aaaa");
//    vector<Produto> prod2;
//
//    prod2.push_back(pd0);
//    prod2.push_back(pd01);
//    prod2.push_back(pd03);
//
//    dn2.inserirProdutos(prod2);
////    cout<<dn<<endl;
////    cout <<dn2<<endl;
//    
//    
//    if (dn.operator==(dn2)) {
//        cout << "iguais" << endl;
//    } else {
//        cout << "Diferentes" << endl;
//    }
    
     SimuladorArmazem armazem ("Tegopi");
     int y=armazem.valorAleatorio(0,20);
     cout << y <<endl;
    return 0;

}
