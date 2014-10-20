/* 
 * File:   Produto.cpp
 * Author: Miguel
 * 
 * Created on 20 de Outubro de 2014, 11:37
 */

#include "Produto.h"

Produto::Produto() {
}


Produto::Produto(const Produto& orig) {
    produto=orig.getProduto();
}

Produto::~Produto() {
}

Produto::Produto(string produto){
    this->produto=produto;
}

string Produto::getProduto() const{
    return this->produto;
}


void Produto::escrever() const{
    cout << this->produto <<endl;
}
