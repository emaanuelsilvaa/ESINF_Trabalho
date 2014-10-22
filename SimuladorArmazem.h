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
#include <vector>
#include <iostream>

class SimuladorArmazem {
public:
    SimuladorArmazem();
    SimuladorArmazem(string nome);
    SimuladorArmazem(const SimuladorArmazem& orig);
    virtual ~SimuladorArmazem();
    int valorAleatorio(int min, int max);
private:
    int num;
    int numDepositosFrescos;
    int numDepositosNormais;
};

#endif	/* SIMULADORARMAZEM_H */

