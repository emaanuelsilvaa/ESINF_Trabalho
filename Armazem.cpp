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
    this->nome=orig.nome;
    this->maxDepositosFrescos=orig.maxDepositosFrescos;
    this->maxDepositosNormais=orig.maxDepositosNormais;
    this->numDepositosFrescos=orig.numDepositosFrescos;
    this->numDepositosNormais=orig.numDepositosNormais;
    this->conjuntoDepositos=orig.getDepositos();
    
}

Armazem::Armazem(string nome, int maxDepositosFrescos, int maxDepositosNormais) {
    this->numDepositosFrescos=0;
    this->numDepositosNormais=0;
    this->maxDepositosFrescos = maxDepositosFrescos;
    this->maxDepositosNormais = maxDepositosNormais;
    this->nome = nome;
}

Armazem::~Armazem() {
    conjuntoDepositos.clear();
}

DepositoFresco Armazem::criarDepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {

    DepositoFresco *dF= new DepositoFresco(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoFresco dF2(*dF);
    if (this->numDepositosFrescos < maxDepositosFrescos) {
        this->conjuntoDepositos[chave] = dF;
        numDepositosFrescos++;
    }
    
    return dF2;
}

DepositoNormal Armazem::criarDepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {

    DepositoNormal *dN = new DepositoNormal(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoNormal dN2(*dN);
    if (this->numDepositosNormais < maxDepositosNormais) {
        this->conjuntoDepositos[chave] = dN;
        numDepositosNormais++;
    }

    return dN2;
}

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
    out << "\n--------------------Estrutura do Armazem: "<< nome << " --------------------" << endl;
    out << "-Numero de Depositos:" << conjuntoDepositos.size() << "-" << endl;
    out << "-Numero De Depositos Frescos:" << numDepositosFrescos << "(Máximo:" << maxDepositosFrescos << ")-" << endl;
    out << "-Numero De Depositos Normais:" << numDepositosNormais << "(Máximo:" << maxDepositosNormais << ")-" << endl;
    out << "\n----------LISTAGEM DOS DEPÓSITOS:----------" << endl;
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

bool Armazem::inserirProdutos(vector<Produto> produtos){
 return true;   
}

bool Armazem::expedir(int numProdutos){
    return true;
}

Armazem& Armazem::operator =(const Armazem& d){
    if(&d == this){
        return *this;
    }
    this->maxDepositosFrescos=d.maxDepositosFrescos;
    this->maxDepositosNormais=d.maxDepositosNormais;
    this->nome=d.nome;
    this->numDepositosFrescos=d.numDepositosFrescos;
    this->numDepositosNormais=d.numDepositosNormais;
    
   map<string, Deposito*> conjuntoDepositos(d.conjuntoDepositos);
}

bool Armazem::operator ==(const Armazem& d) const{
    return (this->maxDepositosFrescos==d.maxDepositosFrescos &&
            this->maxDepositosNormais==d.maxDepositosNormais &&
            this->nome==d.nome &&
            this->numDepositosFrescos==d.numDepositosFrescos &&
            this->numDepositosNormais==d.numDepositosNormais &&
            std::equal(this->conjuntoDepositos.begin(), this->conjuntoDepositos.end(), d.conjuntoDepositos.begin()));
}

ostream& operator<<(ostream& out, const Armazem& a) {
    a.escrever(out);
    return out;
}
