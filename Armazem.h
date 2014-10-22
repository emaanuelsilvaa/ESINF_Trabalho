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
#include "DepositoNormal.h"
#include <map>
#include <iostream>
using namespace std;

class Armazem {
public:
    Armazem();
    Armazem(const Armazem& orig);
    Armazem(string nome, int numDepositosFrescos, int numDepositosNormais);
    virtual ~Armazem();
    
    
    DepositoFresco criarDepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    DepositoNormal criarDepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    bool inserirDeposito(string tipo,Deposito& d);
    
    void escrever(ostream& out) const;
    
    map<string, Deposito*> getDepositos()const;
    int getNumDepositosFrescos()const;
    int getNumDepositosNormais() const;
    
    //
    bool operator==(const Armazem& d) const;
    Armazem& operator=(const Armazem& d);
private:
    
    map<string, Deposito*> conjuntoDepositos;
    int numDepositosFrescos;
    int numDepositosNormais;
//    int nElems;
    string nome;

};
ostream& operator<<(ostream& out, const Armazem& a);

#endif	/* ARMAZEM_H */

