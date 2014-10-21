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

DepositoNormal::~DepositoNormal() {
}

void DepositoNormal::criarPaletes() { // mudar este
    int paletesACriar = getNumeroPaletes() - paletes.size();
    for (int i = 0; i < paletesACriar; i++) {
        stack< Produto> conjunto;
        this->paletes.push_back(conjunto);
    }
}

void DepositoNormal::setNumeroPaletes(int numeroPaletes) {
    this->Deposito::setNumeroPaletes(numeroPaletes);
    criarPaletes();
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
    
    if(ordemProduto==0){
        return produto;
    }
    
    int it;

    for (it =1; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() > 0) {
            produto = paletes.at(it).top();
            paletes.at(it).pop();
            return produto;
        }
    }
            for (it =0; it < paletes.size(); it = it + 2) {
                if (paletes.at(it).size() > 0) {
                    produto = paletes.at(it).top();
                    paletes.at(it).pop();
                    return produto;
                }
            }
    
    return produto;
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

    for (int i = 0; i<this->getNumeroPaletes(); i++) {
        out << "\n-Palete Nº:" << i  << endl;
        if (!paletes.at(i).empty()) {
            stack< Produto> copia(paletes.at(i));
            while (!copia.empty()) {
                Produto produto = copia.top();
                out << "---" << "Produto:" << produto.getProduto() << "---" << endl;
                copia.pop();
            }
        } else {
            out << "\n---Palete Vazia---" << endl;
        }
    }
}

ostream& operator<<(ostream& out, const DepositoNormal& d) {
    d.escrever(out);
    return out;
}
