/* 
 * File:   Produto.h
 * Author: Miguel
 *
 * Created on 20 de Outubro de 2014, 11:37
 */

#ifndef PRODUTO_H
#define	PRODUTO_H

#include <iostream>
using namespace std;

class Produto {
public:
    Produto();
    Produto(string produto);
    Produto(const Produto& orig);
    string getProduto() const;
    void escrever() const;
    virtual ~Produto();
private:
    string produto;

};
#endif	/* PRODUTO_H */

