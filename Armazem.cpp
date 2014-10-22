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

Armazem::Armazem(string nome, int numDepositosFrescos, int numDepositosNormais,
        int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    this->numDepositosFrescos = numDepositosFrescos;
    this->numDepositosNormais = numDepositosNormais;
    this->nome=nome;

    for (int i = 0; i < numDepositosFrescos; i++) {
        Deposito *d= new Deposito(criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias));
        DepositoFresco *dF=dynamic_cast<DepositoFresco *>(d);
        
        conjuntoDepositos.push_back(*dF);
    }

    for (int i = 0; i < numDepositosNormais; i++) {
        Deposito *d= new Deposito(criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias));
        DepositoNormal *dN=dynamic_cast<DepositoNormal *>(d);
        
        conjuntoDepositos.push_back(*dN);
    }
}

Armazem::~Armazem() {
    conjuntoDepositos.clear();
}

Deposito Armazem::criarDeposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    Deposito d(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    return d;
}

//void Armazem::escrever(ostream& out) const{
//    out << "Armazem" <<endl;
//    for(int i=0; i<this)
//}
