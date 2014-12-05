
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

//void menu(SimuladorArmazem* simArm){
//    int escolha;
//    cout <<"MENU"<<endl;
//    cout <<"1-> Construir grafo."<<endl;
//    cout <<"2-> Todos os percursos possíveis entre dois depósitos."<<endl;
//    cout <<"3-> Percurso entre dois depósitos envolvendo apenas um tipo de depósito."<<endl;
//    cout <<"4-> Percurso mais curto entre dois depósitos."<<endl<<endl;
//    cout <<"Por favor, insira o número da instrução que deseja efetuar: "<<endl;    
//    cin >>escolha;
//    
//    if(escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4){
//        cout<<"Por favor, insira um número válido para o menu em questão:"<<endl;
//        cin >>escolha;
//    }
//    
//    switch(escolha){
//        
//        case '1':
//           cout<< *simArm.getGrafosDepositos() <<endl;
//            break;
//            
//        case '2':
//            break;
//            
//        case '3':
//            break;
//        
//        case '4':
//            break;
//    }
//}


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
//    double custoTotal = 0;
//    stack<string> caminhoCurto = s.getGrafosDepositos()->caminhoMaisCurto("Fresco_0","Normal_2", custoTotal);
//    while(!caminhoCurto.empty()){
//        cout << caminhoCurto.top() << endl;
//        caminhoCurto.pop();
//    }
//    cout << "Custo Total: "<< custoTotal << endl;
 
 //PERCURSO ENTRE DOIS DEPOSITOS SENDO TODOS OS DEPOOSITOS DO MESMO TIPO:   
//    stack <string> caminho;
//    caminho = s.getGrafosDepositos()->percurso2DepositosMesmoTipo("Fresco_0","Fresco_5");
//    
//      while(!caminho.empty()){
//       
//       cout<<caminho.top() << " : ";
//       caminho.pop();
//       }    
    
//Interface com o Utilizador.
//menu(&s);

    
    return 0;   
}
      
