
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
#include <fstream>
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
//    Armazem a = s.criarArmazem();
   vector<Produto> prod;
   prod=s.expedirProdutos(3);
   cout << s << endl;
   for(int i=0; i<prod.size(); i++){
       cout << prod.at(i).getProduto() << endl;
   }
//    ofstream destino;
//    destino.open("ficheiroEscrita.txt");
//    destino << a;
//    destino.close();
    return 0;

}
