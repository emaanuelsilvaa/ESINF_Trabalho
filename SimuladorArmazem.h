/* 
 * File:   SimuladorArmazem.h
 * Author: 1130647 e 1130648
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
#include "GrafosDepositos.h"
#include <vector>
#include <iostream>
#include <string>
#include "Matematica.h"
using namespace std;

class SimuladorArmazem {
public:
    SimuladorArmazem();
    SimuladorArmazem(const SimuladorArmazem& orig);
    virtual ~SimuladorArmazem();
    Armazem criarArmazem();
    GrafosDepositos * getGrafosDepositos();
    bool inserirProdutos();
    vector<Produto> expedirProdutos(int numProdutos);
    Armazem getArmazem() const;
    
private: 
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
    GrafosDepositos grafo;
    Matematica math;

    void criarDepositos(Armazem& armazem);
    void associarDepositos();
    void escreverFicheiro();
    
};
ostream& operator<<(ostream& out, const SimuladorArmazem& a);
#endif	/* SIMULADORARMAZEM_H */

