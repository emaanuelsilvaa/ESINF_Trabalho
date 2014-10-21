/* 
 * File:   DepositoFresco.h
 * Author: Paulo
 *
 * Created on 21 de Outubro de 2014, 9:56
 */

#ifndef DEPOSITOFRESCO_H
#define	DEPOSITOFRESCO_H

#include "Deposito.h"
#include "Produto.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;


class DepositoFresco : public Deposito {
public:
    DepositoFresco();
    DepositoFresco(const DepositoFresco& orig);
    DepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    virtual ~DepositoFresco();
    
    bool inserirProduto(Produto& produto);
    bool inserirProdutos(vector<Produto> &produtos);
    Produto expedir();
    vector<Produto> expedirVarios(int numeroExpedicoes);
    void escrever(ostream& out) const;
    void setNumeroPaletes(int numeroPaletes);

    // Operadores
    bool operator==(const DepositoFresco& d) const;
    DepositoFresco& operator=(const DepositoFresco& d);
private:
    vector<queue< map<double,Produto> > > paletes;
    double ordemProduto;
    double produtoInicial;

    int verificarMenorCarga();
    void criarPaletes();

};
ostream& operator<<(ostream& out, const DepositoFresco& d);

#endif	/* DEPOSITOFRESCO_H */

