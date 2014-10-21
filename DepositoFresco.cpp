/* 
 * File:   DepositoFresco.cpp
 * Author: Paulo
 * 
 * Created on 21 de Outubro de 2014, 9:56
 */

#include "DepositoFresco.h"
#include <iostream>
using namespace std;

DepositoFresco::DepositoFresco() : Deposito() {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

DepositoFresco::DepositoFresco(const DepositoFresco& orig) : Deposito(orig) {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

DepositoFresco::DepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) : Deposito(numeroPaletes, chave, area, capacidadeMaxima, distancias) {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

DepositoFresco::~DepositoFresco() {
}

void DepositoFresco::criarPaletes() {
    int paletesACriar = getNumeroPaletes() - paletes.size();
    for (int i = 0; i < paletesACriar; i++) {
        queue< map<double, Produto> > conjunto;
        this->paletes.push_back(conjunto);
    }
}

void DepositoFresco::setNumeroPaletes(int numeroPaletes) {
    this->Deposito::setNumeroPaletes(numeroPaletes);
    criarPaletes();
}

bool DepositoFresco::inserirProduto(Produto& produto) {
    int posicaoMenorCarga = verificarMenorCarga();
    
        if (paletes.at(posicaoMenorCarga).size() < getCapacidade()) {
            map<double, Produto> m;
            m[ordemProduto] = produto;
            paletes.at(posicaoMenorCarga).push(m);
            ordemProduto++;
            return true;
        }
    return false;
}

bool DepositoFresco::inserirProdutos(vector<Produto>& produtos){   
    for(int i=0; i<produtos.size(); i++){
        if(!inserirProduto(produtos.at(i))){
            return false;
        }
    }
    return true;
}

int DepositoFresco::verificarMenorCarga() {
    int posicaoMenorCarga = 0;
    int it = 0;
    for (it = 0; it < paletes.size(); it++) {
        if (paletes.at(it).size() < paletes.at(posicaoMenorCarga).size()) {
            posicaoMenorCarga = it;
        }
    }
    return posicaoMenorCarga;
}

Produto DepositoFresco::expedir() {
    Produto produto("SEM PRODUTO");

    if (produtoInicial > ordemProduto || ordemProduto == 0) {
        return produto;
    }

    for (int i = 0; i < paletes.size(); i++) {
        map<double, Produto> copia2 = paletes.at(i).front();
        map<double, Produto>::iterator it;
        it = copia2.begin();

        if (it->first == produtoInicial) {
            produto = it->second;
            paletes.at(i).pop();
            produtoInicial++;
            return produto;
        }
    }
    return produto;
}

vector<Produto> DepositoFresco::expedirVarios(int numeroExpedicoes) {
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

void DepositoFresco::escrever(ostream& out) const {
    this->Deposito::escrever(out);
    out << "\nTIPO DE DEPÓSITO: DEPÓSITO FRESCO" <<endl;
    out << "Listagem de Paletes:";
    
    for (int i = 0; i<this->getNumeroPaletes(); i++) {
        out << "\n-Palete Nº:" << i + 1 << endl;
        if (!paletes.at(i).empty()) {
                queue<map<double, Produto> > copia(paletes.at(i));
                while (!copia.empty()) {
                    map<double, Produto> copiaProduto = copia.front();
                    map<double, Produto>::iterator it = copiaProduto.begin();
                    out << "---" << "NºdeOrdem:" << it->first << ":" << " Produto:" << it->second.getProduto() << "---" << endl;
                    copia.pop();
                }
        } else {
            out << "\n---Palete Vazia---" << endl;
        }
    }
}


vector<queue< map<double, Produto> > > DepositoFresco::getPaletes() const {
    return paletes;
}

void DepositoFresco::setPaletes(vector<queue<map<double, Produto> > > p) {
    vector<queue< map<double, Produto> > > paletes(p);
}

bool DepositoFresco::operator==(const DepositoFresco& d) const {
        if(!this->Deposito::operator ==(d)){
            return false;
        }

    if (verificarIgualdadePaletes(d)) {
        return false;
    }
    
    return (this->ordemProduto == d.ordemProduto && this->produtoInicial == d.produtoInicial);

}

DepositoFresco& DepositoFresco::operator =(const DepositoFresco& d){
    if(&d==this){
        return *this;
    }
    
    (*this).Deposito::operator =(d);
    this->ordemProduto=d.ordemProduto;
    this->produtoInicial=d.produtoInicial;
    vector<queue< map<double,Produto> > > paletes (d.getPaletes());
}

bool DepositoFresco::verificarIgualdadePaletes(const DepositoFresco d)const {
    if (this->paletes.size() != d.getPaletes().size()) {
        return false;
    }

    for (int i = 0; i < paletes.size(); i++) {
        if (paletes.at(i).size() != d.getPaletes().at(i).size()) {
            return false;
        } else {

            queue<map<double, Produto> > copia(paletes.at(i));
            queue<map<double, Produto> > copia2(d.getPaletes().at(i));
            while (!copia.empty()) {
                map<double, Produto> copiaProduto = copia.front();
                map<double, Produto> copiaProduto2 = copia.front();
                map<double, Produto>::iterator it = copiaProduto.begin();
                map<double, Produto>::iterator it2 = copiaProduto2.begin();
                if (it->first != it2->first || it->second.getProduto() != it->second.getProduto()) {
                    return false;
                }
            }
        }

    }
    return true;
}

ostream& operator<<(ostream& out, const DepositoFresco& d) {
    d.escrever(out);
    return out;
}

