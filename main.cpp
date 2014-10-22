
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
    //    DepositoNormal dn;
    //    dn.setCapacidade(4);
    //    dn.setNumeroPaletes(4);
    //    
    //    
    //    Produto pd("aaaa");
    //    Produto pd1("aaaa");
    //    Produto pd3("aaaa");
    //    Produto pd4("aaaa");
    //    Produto pd5("aaaa");
    //    Produto pd6("aaaa");
    //    Produto pd7("aaaa");
    //    Produto pd8("aaaa");
    //    Produto pd9("bbbb");
    //    Produto pd10("bbbb");
    //    Produto pd11("bbbb");
    //    Produto pd12("bbbb");
    //    vector<Produto> prod;
    //    
    //    
    //          prod.push_back(pd);
    //          prod.push_back(pd1);
    //          prod.push_back(pd3);
    //          prod.push_back(pd4);
    //          prod.push_back(pd5);
    //          prod.push_back(pd6);
    //          prod.push_back(pd7);
    //          prod.push_back(pd8);
    //          prod.push_back(pd9);
    //          prod.push_back(pd10);
    //          prod.push_back(pd11);
    //          prod.push_back(pd12);
    //
    //    
    //    dn.inserirProdutos(prod);
    //    dn.expedirVarios(3);
    //    cout << dn <<endl;

//    DepositoFresco d;
//    DepositoFresco d1;
//    d.setNumeroPaletes(5);
//    d.setCapacidade(5);
//    d1.setCapacidade(5);
//    d1.setNumeroPaletes(5);
//    string s="Merda";
//    
//    if(d==d1){
//        s="Boa";
//    }
//    
//    cout << s <<endl;

     //Deposito d;
    DepositoNormal dn;
    dn.setCapacidade(4);
    dn.setNumeroPaletes(4);


    Produto pd("aaaa");
    Produto pd1("aaaa");
    Produto pd3("aaaa");
    vector<Produto> prod;
    prod.push_back(pd);
    prod.push_back(pd1);
    prod.push_back(pd3);
    dn.inserirProdutos(prod);

    DepositoNormal dn2;
    dn2.setCapacidade(4);
    dn2.setNumeroPaletes(4);

    Produto pd0("aaaa");
    Produto pd01("aaaa");
    Produto pd03("aaaa");
    vector<Produto> prod2;
    prod2.push_back(pd0);
    prod2.push_back(pd01);
    prod2.push_back(pd03);
    dn2.inserirProdutos(prod2);

    if (dn==dn2) {
        cout << "iguais" << endl;
    } else {
        cout << "Diferentes" << endl;
    }
    
    cout << dn2 <<endl;
    
    return 0;

}
