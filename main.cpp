
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
#include "LerFicheiro.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

//    Armazem a("n", 3, 3);
//    map<string, double> d;
//    for (int i = 0; i < 50; i++) {
//        char tmp[5];
//        string chave = itoa(i, tmp, 10);
//        if (i < 25) {
//            a.criarDepositoNormal(20, chave, 20, 20, d);
//        } else {
//            a.criarDepositoFresco(20, chave, 20, 20, d);
//        }
//    }
//
//
//    cout << a << endl;

        SimuladorArmazem s;
        Armazem a=s.criarArmazem();
        cout << a <<endl;



    return 0;

}
