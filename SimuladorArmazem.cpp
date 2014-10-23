/* 
 * File:   SimuladorArmazem.cpp
 * Author: Miguel
 * 
 * Created on 22 de Outubro de 2014, 10:30
 */

#include "SimuladorArmazem.h"

SimuladorArmazem::SimuladorArmazem() {
    Armazem armazem(criarArmazem());
    
   
}

SimuladorArmazem::SimuladorArmazem(const SimuladorArmazem& orig) {


}

SimuladorArmazem::~SimuladorArmazem() {
}

Armazem SimuladorArmazem::criarArmazem(){
    LerFicheiro l;
    string nome;
    int min=0, max=0;
    
    nome= l.getNomeArmazem();
    l.getNumeroDepositosFrescos(min, max);
    this->numDepositosFrescos=valorAleatorio(min, max);
    l.getNumeroDepositosNormais(min, max);
    this->numDepositosNormais=valorAleatorio(min,max);
    
    Armazem armazem(nome,numDepositosFrescos,numDepositosNormais);
    return armazem;
}

void SimuladorArmazem::criarDepositos(Armazem& armazem){
  
}

int SimuladorArmazem::valorAleatorio(int min, int max) {
    int num;
    srand(time(NULL));
    num = rand() % max + min;

    return num;
}
//
//string SimuladorArmazem::integerTostring(int num){
//    int i;
//    char b[4];
//    
//    string s= itoa(i,b,10);
//    
//    return s;
//}
//
//SimuladorArmazem::gerarDepositos(int numeroFrescos, int numeroNormais){
//    
//    this->numeroPaletes=valorAleatorio(0,20);
//    this->chave=valorAleatorio(0,20);
//    this->chaveEmString=integerTostring(chave);
//}
