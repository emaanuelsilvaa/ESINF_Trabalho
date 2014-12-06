/* 
 * File:   MenuUI.cpp
 * Author: Miguel
 * 
 * Created on 6 de Dezembro de 2014, 0:56
 */

#include "MenuUI.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

MenuUI::MenuUI() {
}

MenuUI::MenuUI(const MenuUI& orig) {
}

MenuUI::~MenuUI() {
}

void MenuUI::menu(SimuladorArmazem* simArm){
    int escolha;
    string primeiroDeposito,segundoDeposito,decisao;
    queue <stack <string> > caminhos;
  
    cout <<"MENU"<<endl;
    cout <<"1-> Construir grafo."<<endl;
    cout <<"2-> Todos os percursos possíveis entre dois depósitos."<<endl;
    cout <<"3-> Percurso entre dois depósitos envolvendo apenas um tipo de depósito."<<endl;
    cout <<"4-> Percurso mais curto entre dois depósitos."<<endl<<endl;
    cout <<"Por favor, insira o número da instrução que deseja efetuar: "<<endl;    
    cin >>escolha;
    
    while(escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4){
        cout<<"Por favor, insira um número válido para o menu em questão:"<<endl;
        cin >>escolha;
    }
    
    switch(escolha){
        
        case 1:
          
           cout << "ESTRUTURA DO GRAFO:"<<endl;
           cout<< *simArm->getGrafosDepositos() <<endl;
           cout<< "Deseja gravar a estrutura do grafo no ficheiro de escrita? (s/n)" <<endl;
           cin>>decisao;
           
           if(decisao!="s" && decisao!="n"){
               cout<<"Por favor, insira 's' se deseja gravar ou 'n' se não quer gravar o grafo no ficheiro de escrita."<<endl;
               cin>>decisao;
           }
           if(decisao=="s"){
//            ofstream destino;
//            destino.open("ficheiroEscrita.txt");
//            destino << this->grafo;
//            destino.close();
//            cout << "Grafo adicionado com sucesso !!!"<<endl;
           }
                 
           break;
            
        case 2:
           
            cout <<"Insira o primeiro depósito:" <<endl;
            cin>> primeiroDeposito;
            cout <<"Insira o segundo depósito:" <<endl;
            cin>> segundoDeposito;
            cout <<"PERCURSOS POSSIVEIS:"<<endl;
            caminhos=simArm->getGrafosDepositos()->diferentesCaminhos2Depositos(primeiroDeposito,segundoDeposito);
            if(caminhos.empty()){
            cout << "Vazio" << endl;
            }
            while(!caminhos.empty()){
            stack <string> stk(caminhos.front());
            while(!stk.empty()){
        
            cout<<stk.top() << " : ";
            stk.pop();
            }
            cout << endl <<"ANOTHER:" << endl;
            caminhos.pop();
    }
            break;
            
        case 3:
            break;
        
        case 4:
            break;
    }
}


