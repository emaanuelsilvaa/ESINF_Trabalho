
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

    DepositoFresco d;
    DepositoFresco d1;
    d.setNumeroPaletes(5);
    d.setCapacidade(5);
    d1.setCapacidade(5);
    d1.setNumeroPaletes(5);
    Produto a("Maça");
    Produto b("Maça");
    d.inserirProduto(a);
    d1.inserirProduto(b);
    string s="Merda";
    
    if(d==d1){
        s="Boa";
    }
    
    cout << s <<endl;
    
    

    return 0;

}
