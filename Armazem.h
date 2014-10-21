/* 
 * File:   Armazem.h
 * Author: Paulo
 *
 * Created on 21 de Outubro de 2014, 11:45
 */

#ifndef ARMAZEM_H
#define	ARMAZEM_H

#include "Deposito.h"
#include "DepositoFresco.h"
#include <vector>
#include <iostream>
using namespace std;

class Armazem {
public:
    Armazem();
    Armazem(const Armazem& orig);
    Armazem(int numDepositosFrescos, int numDepositosNormais);
    virtual ~Armazem();
    Deposito& criarDeposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    bool inserirDeposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);

    void escrever(ostream& out) const;
private:
    vector<Deposito> conjuntoDepositos;
    int numDepositosFrescos;
    int numDepositosNormais;

};
ostream& operator<<(ostream& out, const Armazem& a);

#endif	/* ARMAZEM_H */

