/* 
 * File:   MenuUI.cpp
 * Author: Miguel
 * 
 * Created on 6 de Dezembro de 2014, 0:56
 */

#include "MenuUI.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
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
    int nrTentativas=0;
    double custoTotal=0;
    string primeiroDeposito,segundoDeposito,decisao;
    queue <stack <string> > caminhos;
    stack <string> caminho;
  
    cout <<"MENU"<<endl;
    cout <<"1-> Construir grafo."<<endl;
    cout <<"2-> Todos os percursos possíveis entre dois depósitos."<<endl;
    cout <<"3-> Percurso entre dois depósitos envolvendo apenas um tipo de depósito."<<endl;
    cout <<"4-> Percurso mais curto entre dois depósitos."<<endl;
    cout <<"5-> Sair."<<endl<<endl;
    cout <<"Por favor, insira o número da instrução que deseja efetuar: "<<endl;    
    cin >>escolha;
    
    while(escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4 && escolha!=5){
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
            ofstream destino;
//            destino.open("ficheiroEscrita.txt");
//            destino << this->armazem;
//            destino << this->grafo;
//            destino.close();
//            cout << "Grafo adicionado com sucesso !!!"<<endl;
           }
          
           cout<<endl;
           menu(simArm);     
          
            
        case 2:
           
            cout <<"Insira o primeiro depósito:" <<endl;
            cin>> primeiroDeposito;
            while(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"PRIMEIRO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o primeiro depósito:" <<endl;
                cin>> primeiroDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            
            nrTentativas=0;
            
            cout <<"Insira o segundo depósito:" <<endl;
            cin>> segundoDeposito;
            
            while(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"SEGUNDO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o segundo depósito:" <<endl;
                cin>> segundoDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            
            
            cout <<endl<< "PERCURSOS POSSIVEIS:"<<endl;
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
           
           cout<<endl;
           menu(simArm); 
            
        case 3:
            nrTentativas=0;
            
            cout <<"Insira o primeiro depósito:" <<endl;
            cin>> primeiroDeposito;
            while(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"PRIMEIRO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o primeiro depósito:" <<endl;
                cin>> primeiroDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            
            nrTentativas=0;
            
            cout <<"Insira o segundo depósito:" <<endl;
            cin>> segundoDeposito;
            
            while(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"SEGUNDO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o segundo depósito:" <<endl;
                cin>> segundoDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            cout <<endl<<"PERCURSO APENAS COM DEPÓSITOS DO MESMO TIPO:"<<endl;
            
            caminho=simArm->getGrafosDepositos()->percurso2DepositosMesmoTipo(primeiroDeposito,segundoDeposito);
            
            if(caminho.empty()){
                cout<<"Não existe percurso entre estes depósitos."<<endl;
            }
            while(!caminho.empty()){
        
            cout<<caminho.top() << " : ";
            caminho.pop();
            }
    
            
           cout<<endl;
           menu(simArm); 
        
        case 4:
            nrTentativas=0;
            
          cout <<"Insira o primeiro depósito:" <<endl;
            cin>> primeiroDeposito;
            while(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"PRIMEIRO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o primeiro depósito:" <<endl;
                cin>> primeiroDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(primeiroDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            
            nrTentativas=0;
            
            cout <<"Insira o segundo depósito:" <<endl;
            cin>> segundoDeposito;
            
            while(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO" && nrTentativas!=2){
                cout <<"SEGUNDO DEPÓSITO INVÁLIDO !!!"<<endl;
                cout <<"Insira o segundo depósito:" <<endl;
                cin>> segundoDeposito;
                nrTentativas++;              
            }
            if(this->grafo.getTipoDeposito(segundoDeposito)=="INVALIDO"){ //Para sair para o menu.
            menu(simArm);
            }
            cout <<endl<<"PERCURSO MAIS CURTO:"<<endl;
            
            
            caminho=simArm->getGrafosDepositos()->caminhoMaisCurto(primeiroDeposito,segundoDeposito,custoTotal);
            
            if(caminho.empty()){
                cout<<"Não existe percurso entre estes depósitos."<<endl;
            }
            while(!caminho.empty()){
        
            cout<<caminho.top() << " : ";
            caminho.pop();
            }
            
            cout << "Custo Total: "<< custoTotal << endl;
           
           cout<<endl;
           menu(simArm); 
            
            case 5:
                std::exit(0);
    }
}


