/* 
 * File:   DepositoNormal.h
 * Author: 1130647 e 1130648
 *
 * Created on 20 de Outubro de 2014, 10:49
 */

#ifndef DEPOSITONORMAL_H
#define	DEPOSITONORMAL_H

#include "Deposito.h"
#include "Produto.h"
#include <vector>
#include <stack>
using namespace std;

class DepositoNormal : public Deposito {
public:
    DepositoNormal();
    DepositoNormal(const DepositoNormal& orig);
    DepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    virtual ~DepositoNormal();

    bool inserirProduto(Produto &produto);
    bool inserirProdutos(vector<Produto>& produtos);
    Produto expedir();
    vector<Produto> expedirVarios(int numeroExpedicoes);
    void escrever(ostream& out) const;
    void setNumeroPaletes(int numeroPaletes);
    double getOrdemProduto() const;
    void setOrdemProduto(int ordem);
    vector<stack<Produto> > getPaletes()const;
    bool verificarDepositoCheio();
    int getMaximoProdutos()const;

    //Operadores
    bool operator==(const DepositoNormal& d) const;
    DepositoNormal& operator=(const DepositoNormal& d);
private:
    vector<stack<Produto> > paletes;
    double ordemProduto;
    void criarPaletes();
    bool verificarIgualdadePaletes(const DepositoNormal& d) const;
    
};

ostream& operator<<(ostream& out, const DepositoNormal& d);

#endif	/* DEPOSITONORMAL_H */

