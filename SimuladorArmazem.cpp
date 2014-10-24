/* 
 * File:   SimuladorArmazem.cpp
 * Author: Miguel
 * 
 * Created on 22 de Outubro de 2014, 10:30
 */

#include "SimuladorArmazem.h"
#include <iostream>
#include <fstream>
using namespace std;

SimuladorArmazem::SimuladorArmazem() {
    Armazem armazem(criarArmazem());
    escreverFicheiro();
}

SimuladorArmazem::SimuladorArmazem(const SimuladorArmazem& orig) {
    this->armazem = orig.getArmazem();
    this->numDepositosFrescos = orig.numDepositosFrescos;
    this->numDepositosNormais = orig.numDepositosNormais;
    this->maxPaletes = orig.maxPaletes;
    this->minPaletes = orig.minPaletes;
    this->maxArea = orig.maxArea;
    this->minArea = orig.minArea;
    this->maxProdutos = orig.maxProdutos;
    this->minProdutos = orig.minProdutos;
    this->maxCapacidadeMaxima = orig.maxCapacidadeMaxima;
    this->minCapacidadeMaxima = orig.minCapacidadeMaxima;
    this->minDistancias = orig.minDistancias;
    this->maxDistancias = orig.maxDistancias;
    vector<string> chaves(orig.chaves);
    ler = orig.ler;


}

SimuladorArmazem::~SimuladorArmazem() {
}

Armazem SimuladorArmazem::criarArmazem() {
    Armazem arm;
    if (ler.validarFicheiro()) {
        string nome;
        int minN = 0;
        int maxN = 0;
        int minF = 0;
        int maxF = 0;

        nome = ler.getNomeArmazem();
        ler.getNumeroDepositosFrescos(minF, maxF);
        this->numDepositosFrescos = valorAleatorio(minF, maxF);
        ler.getNumeroDepositosNormais(minN, maxN);
        this->numDepositosNormais = valorAleatorio(minN, maxN);

        Armazem arm(nome, numDepositosFrescos, numDepositosNormais);
        this->armazem = arm;
        criarDepositos(armazem);
        inserirProdutos();

        return armazem;

    }

    return armazem;
}

void SimuladorArmazem::criarDepositos(Armazem& armazem) {
    ler.getNumeroPaletes(minPaletes, maxPaletes);
    ler.getArea(minArea, maxArea);
    ler.getNumeroProdutos(minProdutos, maxProdutos);
    ler.getCapacidadeMaxima(minCapacidadeMaxima, maxCapacidadeMaxima);
    ler.getDistancias(minDistancias, maxDistancias);

    for (int i = 0; i < numDepositosFrescos; i++) {
        int numeroPaletes = this->valorAleatorio(minPaletes, maxPaletes);
        double area = double (this->valorAleatorio(minArea, maxArea));
        int capacidadeMaxima = this->valorAleatorio(minCapacidadeMaxima, maxCapacidadeMaxima);
        map<string, double> m;
        char tmp[5];
        string chaveF = "Fresco_";
        chaveF.append(itoa(i, tmp, 10));
        armazem.criarDepositoFresco(numeroPaletes, chaveF, area, capacidadeMaxima, m);
    }

    for (int i = 0; i < numDepositosNormais; i++) {
        int numeroPaletes = this->valorAleatorio(minPaletes, maxPaletes);
        double area = double (this->valorAleatorio(minArea, maxArea));
        int capacidadeMaxima = this->valorAleatorio(minCapacidadeMaxima, maxCapacidadeMaxima);
        map<string, double> m;
        char tmp[5];
        string chaveN = "Normal_";
        chaveN.append(itoa(i, tmp, 10));
        armazem.criarDepositoNormal(numeroPaletes, chaveN, area, capacidadeMaxima, m);
    }
}

int SimuladorArmazem::valorAleatorio(int min, int max) {
    int num;
    srand(time(NULL));
    num = rand() % ((max + 1) - min) + min;
    return num;
}

void SimuladorArmazem::escreverFicheiro() {
    ofstream destino;
    destino.open("ficheiroEscrita.txt");
    string s;
    destino << this->armazem;
    destino.close();
}

bool SimuladorArmazem::inserirProdutos() {
    vector<Produto> listaProd;
    int numProdutos = valorAleatorio(minProdutos, maxProdutos);
    
    cout << numProdutos << endl;
    for (int i = 0; i < numProdutos; i++) {
        if (i % 2 == 0) {
            Produto p("Maça");
            listaProd.push_back(p);
        } else {
            Produto p("Banana");
            listaProd.push_back(p);
        }
    }
    armazem.inserirProdutos(listaProd);
    return true;
}

bool SimuladorArmazem::expedirProdutos(int numProdutos) {
    return true;
}

Armazem SimuladorArmazem::getArmazem() const {
    return this->armazem;
}

ostream& operator<<(ostream& out, const SimuladorArmazem& a) {
    a.getArmazem().escrever(out);
    return out;
}


