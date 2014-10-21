/* 
 * File:   Armazem.cpp
 * Author: Paulo
 * 
 * Created on 21 de Outubro de 2014, 11:45
 */

#include "Armazem.h"

Armazem::Armazem() {
}

Armazem::Armazem(const Armazem& orig) {
}

Armazem::Armazem(int numDepositosFrescos, int numDepositosNormais,
        int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    this->numDepositosFrescos = numDepositosFrescos;
    this->numDepositosNormais = numDepositosNormais;

    for (int i = 0; i < numDepositosFrescos; i++) {
        Deposito d = criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias);
        d = DepositoFresco();
        conjuntoDepositos.push_back(d);
    }

    for (int i = 0; i < numDepositosNormais; i++) {
        Deposito d = criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias);
        d = DepositoNormal();
        conjuntoDepositos.push_back(d);
    }
    //
}

Armazem::~Armazem() {
}

Deposito Armazem::criarDeposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    Deposito d;
    return d;
}
