/* 
 * File:   DepositoNormal.cpp
 * Author: Miguel
 * 
 * Created on 20 de Outubro de 2014, 10:49
 */

#include "DepositoNormal.h"
#include <iostream>
using namespace std;

DepositoNormal::DepositoNormal() : Deposito() {
    this->ordemProduto = 0;
    criarPaletes();
}

DepositoNormal::DepositoNormal(const DepositoNormal& orig) : Deposito(orig) {
    this->ordemProduto = 0;
    criarPaletes();
}

DepositoNormal::DepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) : Deposito(numeroPaletes, chave, area, capacidadeMaxima, distancias) {
    this->ordemProduto = 0;
    criarPaletes();
}

DepositoNormal::~DepositoNormal() {
    this->paletes.clear();
}

void DepositoNormal::criarPaletes() { // mudar este
    int paletesACriar = getNumeroPaletes() - paletes.size();
    for (int i = 0; i < paletesACriar; i++) {
        stack< Produto> conjunto;
        this->paletes.push_back(conjunto);
    }
}

double DepositoNormal::getOrdemProduto()const {
    return this->ordemProduto;
}

void DepositoNormal::setOrdemProduto(int ordem) {
    this->ordemProduto = ordem;
}

vector<stack<Produto> > DepositoNormal::getPaletes()const {
    return this->paletes;
}

void DepositoNormal::setNumeroPaletes(int numeroPaletes) {
    this->Deposito::setNumeroPaletes(numeroPaletes);
    criarPaletes();
}

bool DepositoNormal::verificarDepositoCheio() {


    for (int i = 0; i < getNumeroPaletes(); i++) {
        if (getPaletes().at(i).size() != getCapacidade()) {
            return false;
        }
    }
    return true;
}

bool DepositoNormal::inserirProduto(Produto& produto) {

    int it;

    for (it = 0; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() < getCapacidade()) {
            paletes.at(it).push(produto);
            ordemProduto++;
            return true;
        }
    }
    for (it = 1; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() < getCapacidade() / 2) {
            paletes.at(it).push(produto);
            ordemProduto++;
            return true;
        }
    }
    return false;
}

bool DepositoNormal::inserirProdutos(vector<Produto> produtos) {
    int i;

    for (i = 0; i < produtos.size(); i++) {

        if (!inserirProduto(produtos.at(i))) {
            return false;
        }
    }
    return true;
}

Produto DepositoNormal::expedir() {
    Produto produto("SEM PRODUTO");

    if (ordemProduto == 0) {
        return produto;
    }

    int it;

    for (it = 1; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() > 0) {
            produto = paletes.at(it).top();
            paletes.at(it).pop();
            return produto;
        }
    }
    for (it = 0; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() > 0) {
            produto = paletes.at(it).top();
            paletes.at(it).pop();
            return produto;
        }
    }

    return produto;
}

int DepositoNormal::getMaximoProdutos() const{
    int numeroPal=this->getNumeroPaletes();
    int capacidadeMax=this->getCapacidade();
    int maxProdutos=0;
    if(numeroPal%2 ==0){
        maxProdutos= (numeroPal/2)*capacidadeMax;
        maxProdutos+=(numeroPal/2)*capacidadeMax/2;
    }else{
        maxProdutos= ((numeroPal/2)+1)*capacidadeMax;
        maxProdutos+=(numeroPal-(numeroPal/2)+1)*capacidadeMax/2;
    }
    return maxProdutos;
}

vector<Produto> DepositoNormal::expedirVarios(int numeroExpedicoes) {
    vector<Produto> listaProdutos;

    for (int k = 0; k < numeroExpedicoes; k++) {
        Produto produto;
        produto = this->expedir();
        if (produto.getProduto() == "SEM PRODUTO") {
            return listaProdutos;
        } else {
            listaProdutos.push_back(produto);
        }

    }
    return listaProdutos;
}

void DepositoNormal::escrever(ostream& out) const {
    this->Deposito::escrever(out);
    out << "\nTIPO DE DEPÓSITO: DEPÓSITO NORMAL" << endl;
    out << "Listagem de Paletes:";
    if(this->paletes.empty()){
        out << "\n---Sem Paletes---"<<endl;
    }
    for (int i = 0; i<this->getNumeroPaletes(); i++) {
        out << "\n-Palete Nº:" << i << endl;
        if (!paletes.at(i).empty()) {
            stack< Produto> copia(paletes.at(i));
            while (!copia.empty()) {
                Produto produto = copia.top();
                out << "Produto:" << produto.getProduto() << "---" << endl;
                copia.pop();
            }
        } else {
            out << "\n---Palete Vazia---" << endl;
        }
    }
    out << "\n ----------Fim de Depósito----------" << endl;
}

bool DepositoNormal::operator==(const DepositoNormal& d)const{

    if (!this->Deposito::operator==(d)) {
        return false;
    }
    if (!verificarIgualdadePaletes(d)){
        return false;
    }

    return(this->ordemProduto== d.ordemProduto);
}

bool DepositoNormal::verificarIgualdadePaletes(const DepositoNormal& d)const{

    if (this->paletes.size()!=d.getPaletes().size()){
        return false;
    }
    
    for (int i = 0; i < paletes.size(); i++) {
        if (paletes.at(i).size() != d.getPaletes().at(i).size()) {
            return false;
        } else {
            
            stack<Produto> copia(paletes.at(i));
            stack<Produto> copia2(d.getPaletes().at(i));
            while(!copia.empty()){
                Produto copiaProduto= copia.top();
                Produto copiaProduto2= copia2.top();
                if(copiaProduto.getProduto()!=copiaProduto2.getProduto()){
                    return false;
                }
               
                copia.pop();
                copia2.pop();
            }
        }
           
    }
    return true;   
}

DepositoNormal& DepositoNormal::operator =(const DepositoNormal& d){
    if(&d==this){
        return *this;
    }
    
    (*this).Deposito::operator =(d);
    this->ordemProduto=d.ordemProduto;
    vector<stack<Produto> > paletes (d.getPaletes());
}              

ostream& operator<<(ostream& out, const DepositoNormal& d) {
    d.escrever(out);
    return out;
}
