/* 
 * File:   SimuladorArmazem.cpp
 * Author: Miguel
 * 
 * Created on 22 de Outubro de 2014, 10:30
 */

#include "SimuladorArmazem.h"

SimuladorArmazem::SimuladorArmazem() {   
}

SimuladorArmazem::SimuladorArmazem(string nome){
    this->numDepositosFrescos=valorAleatorio(0,20);
    this->numDepositosNormais=valorAleatorio(0,20);
    this->numeroPaletes=valorAleatorio(0,20);
    this->distanciasDepositos=valorAleatorio(0,10);
    
    
}
SimuladorArmazem::SimuladorArmazem(const SimuladorArmazem& orig) {


}

SimuladorArmazem::~SimuladorArmazem() {
}



int SimuladorArmazem::valorAleatorio(int min, int max){

    int num=rand()% max + min; 
    
    return num;
}

