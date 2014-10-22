/* 
 * File:   Armazem.cpp
 * Author: Paulo
 * 
 * Created on 21 de Outubro de 2014, 11:45
 */

#include "Armazem.h"

Armazem::Armazem() {
    this->numDepositosFrescos=0;
    this->numDepositosNormais=0;

}

Armazem::Armazem(const Armazem& orig) {
}

Armazem::Armazem(string nome, int numDepositosFrescos, int numDepositosNormais) {
    this->numDepositosFrescos=0;
    this->numDepositosNormais=0;
    this->maxDepositosFrescos = numDepositosFrescos;
    this->maxDepositosNormais = numDepositosNormais;
    this->nome = nome;
}

Armazem::~Armazem() {
    conjuntoDepositos.clear();
}

DepositoFresco Armazem::criarDepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    //Deposito *d1 = new Deposito(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    //  DepositoFresco *dF = dynamic_cast<DepositoFresco *> (d1);
    //        conjuntoDepositos[nElems] = dF;

    DepositoFresco *dF= new DepositoFresco(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoFresco dF2(*dF);
    if (this->numDepositosFrescos < maxDepositosFrescos) {
        cout << "Golo" <<endl;
        this->conjuntoDepositos[chave] = dF;
        cout << this->conjuntoDepositos.size() <<endl;
        numDepositosFrescos++;
    }
    
    return dF2;
}

DepositoNormal Armazem::criarDepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {

    DepositoNormal *dN = new DepositoNormal(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoNormal dN2(*dN);
    
    if (this->numDepositosNormais < maxDepositosNormais) {
        this->conjuntoDepositos[chave] = dN;
        maxDepositosNormais++;
    }

    return dN2;
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
    out << "\n---------- Estrutura do Armazem: "<< nome << " ----------" << endl;
    out << "-Numero de Depositos:" << conjuntoDepositos.size() << "-" << endl;
    out << "-Numero De Depositos Frescos:" << numDepositosFrescos << "(Máximo:" << maxDepositosFrescos << ")-" << endl;
    out << "-Numero De Depositos Normais:" << numDepositosNormais << "(Máximo:" << maxDepositosNormais << ")-" << endl;
    out << "\n---LISTAGEM DOS DEPÓSITOS:--" << endl;
    map<string, Deposito*>::const_iterator it;
    it = conjuntoDepositos.begin();
    for (it = conjuntoDepositos.begin(); it != conjuntoDepositos.end(); it++) {
        if (typeid (*(it->second)) == typeid (DepositoFresco)) {
            dynamic_cast<DepositoFresco*> (it->second)->escrever(out);
            continue;
        }
        
        if (typeid (*(it->second)) == typeid (DepositoNormal)) {
            dynamic_cast<DepositoNormal*> (it->second)->escrever(out);
            continue;
        }

    }
    
    out << "\n ----------Fim da Estrutura do Armazem: " << nome <<"----------" << endl;
}

ostream& operator<<(ostream& out, const Armazem& a) {
    a.escrever(out);
    return out;
}
