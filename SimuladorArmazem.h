/* 
 * File:   SimuladorArmazem.h
 * Author: Miguel
 *
 * Created on 22 de Outubro de 2014, 10:30
 */

#ifndef SIMULADORARMAZEM_H
#define	SIMULADORARMAZEM_H

#include "Deposito.h"
#include "DepositoFresco.h"
#include "DepositoNormal.h"
#include "LerFicheiro.h"
#include "Armazem.h"
#include <vector>
#include <iostream>
using namespace std;

class SimuladorArmazem {
public:
    SimuladorArmazem();
    SimuladorArmazem(const SimuladorArmazem& orig);
    virtual ~SimuladorArmazem();
    int valorAleatorio(int min, int max);
    Armazem criarArmazem(); 
    
    bool inserirProdutos(vector<Produto>& produtos);
    bool expedirProdutos(int numProdutos);
    Armazem getArmazem() const;
//    string integerTostring(int num);
//    map<string, Deposito> gerarDepositos(int nrfrescos, int nrNormais);
private:
    map <string, Deposito> conjuntoDepositos;
    Armazem armazem;
    int numDepositosFrescos;
    int numDepositosNormais;
    int maxPaletes;
    int minPaletes;
    int maxArea;
    int minArea;
    int maxProdutos;
    int minProdutos;
    int maxCapacidadeMaxima;
    int minCapacidadeMaxima;
    int minDistancias;
    int maxDistancias;
    vector<string> chaves;
    LerFicheiro ler;
    
    void criarDepositos(Armazem& armazem);
    void associarDepositos();
    void escreverFicheiro();
     
};
ostream& operator<<(ostream& out, const SimuladorArmazem& a);
#endif	/* SIMULADORARMAZEM_H */

