
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
 
       
//    queue <stack <string> > caminhos;
//    caminhos=s.getGrafosDepositos()->diferentesCaminhos2Depositos("Fresco_0","Fresco_1");
//    
//    if(caminhos.empty()){
//        cout << "Vazio" << endl;
//    }
//    while(!caminhos.empty()){
//        stack <string> stk(caminhos.front());
//        while(!stk.empty()){
//        
//        cout<<stk.top() << " : ";
//        stk.pop();
//        }
//        cout << endl <<"ANOTHER:" << endl;
//        caminhos.pop();
//    }
    
//    cout << "Caminho Curto:" << endl;
//    stack<string> caminhoCurto = s.getGrafosDepositos()->caminhoMaisCurto("Fresco_0","Normal_2");
//    while(!caminhoCurto.empty()){
//        cout << caminhoCurto.top() << endl;
//        caminhoCurto.pop();
//    }
 
 //PERCURSO ENTRE DOIS DEPOSITOS SENDO TODOS OS DEPOOSITOS DO MESMO TIPO:   
//    stack <string> caminho;
//    caminho=s.getGrafosDepositos()->percurso2DepositosMesmoTipo("Fresco_1","Fresco_4");
//    
//      while(!caminho.empty()){
//       
//       cout<<caminho.top() << " : ";
//       caminho.pop();
//       }    
    
    
    return 0;   
}
      
