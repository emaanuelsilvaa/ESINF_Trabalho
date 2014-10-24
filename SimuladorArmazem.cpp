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
        chaves.push_back(chaveF);
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
         chaves.push_back(chaveN);
        armazem.criarDepositoNormal(numeroPaletes, chaveN, area, capacidadeMaxima, m);
    }
     associarDepositos();
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

    cout << "Foram criados: " << numProdutos << " produtos." << endl;
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

vector<Produto> SimuladorArmazem::expedirProdutos(int numProdutos) {
    vector<Produto> prod;
    prod = armazem.expedir(numProdutos);
    escreverFicheiro();
    return prod;
}

Armazem SimuladorArmazem::getArmazem() const {
    return this->armazem;
}

void SimuladorArmazem::associarDepositos() {
    map<string, Deposito*>::const_iterator it;
    map<string, Deposito*> deps;
    vector<string>::iterator it3;
    armazem.getDepositosReferencia(deps);
    it = deps.begin();
    it3=chaves.begin();
    string chave;
    int cont = 0;
    double distancia;
    if (deps.size() > 1) {
        for (it = deps.begin(); it != deps.end(); it++) {
            map<string, double> distancias;
            if (typeid (*(it->second)) == typeid (DepositoFresco)) {
                if(cont !=0 && cont!=deps.size()-1 ){    
                    double dist = valorAleatorio(minDistancias, maxDistancias);
                    vector<string>::iterator it4;
                    it4=it3;
                    it4++;
                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4,dist);
                    dist=0;
                    dist = valorAleatorio(minDistancias, maxDistancias);
                    cout << minDistancias <<"vs"<< maxDistancias <<endl;
                    it4--;
                    it4--;
                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4,dist);
                }
            }

            if (typeid (*(it->second)) == typeid (DepositoNormal)) {
                if(cont !=0 && cont!=deps.size()-1 ){    
                    double dist = valorAleatorio(minDistancias, maxDistancias);
                    vector<string>::iterator it4;
                    it4=it3;
                    it4++;
                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4,dist);
                    dist=0;
                    dist = valorAleatorio(minDistancias, maxDistancias);
                    it4--;
                    it4--;
                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4,dist);
                }
            }
            cont++; 
            it3++;
        }
    }
}

ostream& operator<<(ostream& out, const SimuladorArmazem& a) {
    a.getArmazem().escrever(out);
    return out;
}


