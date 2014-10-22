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

Armazem::Armazem(string nome, int numDepositosFrescos, int numDepositosNormais) {
    this->numDepositosFrescos = numDepositosFrescos;
    this->numDepositosNormais = numDepositosNormais;
    this->nome = nome;
}

Armazem::~Armazem() {
    conjuntoDepositos.clear();
}

DepositoFresco Armazem::criarDepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    DepositoFresco d(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    return d;
}

DepositoNormal Armazem::criarDepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    DepositoNormal  d(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    return d;
}


//bool Armazem::inserirDeposito(string tipoDeposito, int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
//
//    if (tipoDeposito == "Fresco") {
//        Deposito *d = new Deposito(criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias));
//        DepositoFresco *dF = dynamic_cast<DepositoFresco *> (d);
//        conjuntoDepositos[nElems] = dF;
//        return true;
//    }
//
//    if (tipoDeposito == "Normal") {
//        Deposito *d = new Deposito(criarDeposito(numeroPaletes, chave, area, capacidadeMaxima, distancias));
//        DepositoNormal *dN = dynamic_cast<DepositoNormal *> (d);
//        conjuntoDepositos[nElems] = dN;
//        return true;
//    }
//    return false;
//}

map<string, Deposito*> Armazem::getDepositos() const {
    return this->conjuntoDepositos;
}

int Armazem::getNumDepositosNormais() const {
    return this->numDepositosNormais;
}

int Armazem::getNumDepositosFrescos() const {
    return this->numDepositosFrescos;
}

void Armazem::escrever(ostream& out) const {
    out << "\n-----Armazem-----" << endl;
    out << "-Numero de Depositos:" << conjuntoDepositos.size() << "-" << endl;
    out << "-Numero De Depositos Frescos:" << numDepositosFrescos << "-" << endl;
    out << "-Numero De Depositos Normais:" << numDepositosNormais << "-" << endl;

    map<string, Deposito*>::const_iterator it;
    it = conjuntoDepositos.begin();
    for (it = conjuntoDepositos.begin(); it != conjuntoDepositos.end(); it++) {
        if (typeid (it->second) == typeid (DepositoFresco)) {
            dynamic_cast<DepositoFresco*> (it->second)->escrever(out);
            continue;
        }
        if (typeid (it->second) == typeid (DepositoNormal)) {
            dynamic_cast<DepositoNormal*> (it->second)->escrever(out);
            continue;
        }

    }
    out << "----------Fim de Armazem----------" << endl;
}

ostream& operator<<(ostream& out, const Armazem& a) {
    a.escrever(out);
    return out;
}
