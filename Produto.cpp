/* 
 * File:   Produto.cpp
 * Author: Miguel
 * 
 * Created on 20 de Outubro de 2014, 11:37
 */

#include "Produto.h"

/**
 * Construtor vazio da classe Produto.
 */
Produto::Produto() {
}

/**
 * Construtor copia da classe Produto.
 * @param orig produto a ser copiado.
 */
Produto::Produto(const Produto& orig) {
    produto=orig.getProduto();
}

/**
 * Destrutor da classe Produto.
 */
Produto::~Produto() {
}

/**
 * COnstrutor da classe Produto.
 * @param produto nome do produto.
 */
Produto::Produto(string produto){
    this->produto=produto;
}

/**
 * Metodo que devolve o nome do produto.
 * @return nome do produto.
 */
string Produto::getProduto() const{
    return this->produto;
}

/**
 * Metodo que escreve o nome do produto.
 */
void Produto::escrever() const{
    cout << this->produto <<endl;
}
