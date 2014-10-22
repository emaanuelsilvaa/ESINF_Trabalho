
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
#include "Armazem.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Armazem a("n",20,20);
    DepositoFresco *dF=new DepositoFresco();
    vector<Deposito*> vec;
    vec.push_back(dF);
    map<string, double> d;
    a.criarDepositoNormal(20,"A00",20,20,d);
    cout << a <<endl;
    return 0;

}
