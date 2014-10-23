/* 
 * File:   SimuladorArmazem.h
 * Author: Miguel
 *
 * Created on 22 de Outubro de 2014, 10:30
 */

#ifndef SIMULADORARMAZEM_H
#define	SIMULADORARMAZEM_H

#include "Deposito.h"
#include "DepositoFresco.h"
#include "DepositoNormal.h"
#include "LerFicheiro.h"
#include "Armazem.h"
#include <vector>
#include <iostream>

class SimuladorArmazem {
public:
    SimuladorArmazem();
    SimuladorArmazem(const SimuladorArmazem& orig);
    virtual ~SimuladorArmazem();
    int valorAleatorio(int min, int max);
    Armazem criarArmazem();
//    string integerTostring(int num);
//    map<string, Deposito> gerarDepositos(int nrfrescos, int nrNormais);
private:
    map <string, Deposito> conjuntoDepositos;
    Armazem armazem;
    int num;
    int numDepositosFrescos;
    int numDepositosNormais;
    int numeroPaletes;
    int chave;
    string chaveEmString;
    
    
};

#endif	/* SIMULADORARMAZEM_H */

