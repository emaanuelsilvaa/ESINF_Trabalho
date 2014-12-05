/* 
 * File:   SimuladorArmazem.cpp
 * Author: 1130647 e 1130648
 * 
 * Created on 22 de Outubro de 2014, 10:30
 */

#include "SimuladorArmazem.h"
#include "GrafosDepositos.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Construtor vazio que cria um armazem e grava num ficheiro a estrutura do armazém
 */
SimuladorArmazem::SimuladorArmazem() {
    GrafosDepositos grafo();
    Armazem armazem(criarArmazem());
    escreverFicheiro();
}

/**
 * Construtor cópia da classe SimuladorArmazem.
 * @param orig SimuladorArmazem a ser copiado.
 */
SimuladorArmazem::SimuladorArmazem(const SimuladorArmazem& orig) {
    GrafosDepositos grafo();
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

/**
 * Destrutor da classe SimuladorCópia.
 */
SimuladorArmazem::~SimuladorArmazem() {
    this->chaves.clear();
}

/**
 * Método que cria um armazém com valores aleatórios.
 * @return armazém criado.
 */
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
        if (minF > maxF) {
            return armazem;
        }
        this->numDepositosFrescos = math.valorAleatorio(minF, maxF);
        ler.getNumeroDepositosNormais(minN, maxN);
        if (minN > maxN) {
            return armazem;
        }
        this->numDepositosNormais = math.valorAleatorio(minN, maxN);

        Armazem arm(nome, numDepositosFrescos, numDepositosNormais);
        this->armazem = arm;
        criarDepositos(armazem);
        inserirProdutos();

        return armazem;

    }

    return armazem;
}

/**
 * Método que permite criar depósitos num armazem.
 * @param armazem onde irão ser criados depósitos.
 */
void SimuladorArmazem::criarDepositos(Armazem& armazem) {
    ler.getNumeroPaletes(minPaletes, maxPaletes);
    ler.getArea(minArea, maxArea);
    ler.getNumeroProdutos(minProdutos, maxProdutos);
    ler.getCapacidadeMaxima(minCapacidadeMaxima, maxCapacidadeMaxima);
    ler.getDistancias(minDistancias, maxDistancias);

    for (int i = 0; i < numDepositosFrescos; i++) {
        int numeroPaletes = math.valorAleatorio(minPaletes, maxPaletes);
        double area = double (math.valorAleatorio(minArea, maxArea));
        int capacidadeMaxima = math.valorAleatorio(minCapacidadeMaxima, maxCapacidadeMaxima);
        map<string, double> m;
        char tmp[5];
        string chaveF = "Fresco_";
        chaveF.append(itoa(i, tmp, 10));
        chaves.push_back(chaveF);
        armazem.criarDepositoFresco(numeroPaletes, chaveF, area, capacidadeMaxima, m);
    }

    for (int i = 0; i < numDepositosNormais; i++) {
        int numeroPaletes = math.valorAleatorio(minPaletes, maxPaletes);
        double area = double (math.valorAleatorio(minArea, maxArea));
        int capacidadeMaxima = math.valorAleatorio(minCapacidadeMaxima, maxCapacidadeMaxima);
        map<string, double> m;
        char tmp[5];
        string chaveN = "Normal_";
        chaveN.append(itoa(i, tmp, 10));
        chaves.push_back(chaveN);
        armazem.criarDepositoNormal(numeroPaletes, chaveN, area, capacidadeMaxima, m);
    }
    associarDepositos();
}

/**
 * Método que escreve a estrutura de um armazem no ficheiro de saida.
 */
void SimuladorArmazem::escreverFicheiro() {
    ofstream destino;
    destino.open("ficheiroEscrita.txt");
    destino << this->armazem;
    destino.close();
}

/**
 * Método que insere produtos num armazém.
 * @return true se inseriu todos os produtos, ou false se não inseriu.
 */
bool SimuladorArmazem::inserirProdutos() {
    vector<Produto> listaProd;
    int numProdutos = math.valorAleatorio(minProdutos, maxProdutos);

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

    return armazem.inserirProdutos(listaProd);

}

/**
 * Métodos que expede produtos de um armazém.
 * @param numProdutos numero de produtos a serem expedidos
 * @return lista de produtos expedidos.
 */
vector<Produto> SimuladorArmazem::expedirProdutos(int numProdutos) {
    vector<Produto> prod;
    prod = armazem.expedir(numProdutos);
    escreverFicheiro();
    return prod;
}

/**
 * Permite obter o armazem.
 * @return armazem.
 */
Armazem SimuladorArmazem::getArmazem() const {
    return this->armazem;
}

GrafosDepositos * SimuladorArmazem::getGrafosDepositos() {
    return &(this->grafo);
}

/**
 * Método que associa a um depósito os seus depósitos vizinhos e as distancias entre eles.
 */
void SimuladorArmazem::associarDepositos() {

    map<string, Deposito*>::const_iterator vetorOrigem;
    map<string, Deposito*> deps;
    map<string, Deposito*>::const_iterator vetorAdjacente;
    armazem.getDepositosReferencia(deps);
    vetorOrigem = deps.begin();
    string chave;
    int cont = 0;
    double distancia;
    if (deps.size() > 1) {
        for (vetorOrigem = deps.begin(); vetorOrigem != deps.end(); vetorOrigem++) {
            map<string, double> distancias;

            if (cont != 0 && cont != deps.size() - 1) {

                int dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente = vetorOrigem;
                vetorAdjacente++;
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }
                
                dist = 0;
                dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente--;
                vetorAdjacente--;
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }
            } else if (cont == 0) {

                double dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente = vetorOrigem;
                vetorAdjacente++;
                dist = 0;
                dist = math.valorAleatorio(minDistancias, maxDistancias);
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }

                dist = 0;
                dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente = deps.end();
                vetorAdjacente--;
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }
            } else {

                double dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente = deps.end();
                vetorAdjacente--;
                vetorAdjacente--;

                dist = 0;
                dist = math.valorAleatorio(minDistancias, maxDistancias);
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }


                dist = 0;
                dist = math.valorAleatorio(minDistancias, maxDistancias);
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }
            }

            if (deps.size() > 2 && cont != 0 && cont <= deps.size() - 3) {
                int dist = math.valorAleatorio(minDistancias, maxDistancias);
                vetorAdjacente = vetorOrigem;
                vetorAdjacente++;
                vetorAdjacente++;
                if ((vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist)) {
                    (vetorAdjacente->second)->inserirDistancia(vetorOrigem->second->getChave(), dist);

                }

            }
            cont++;
        }
    }

    grafo.construirGrafo(armazem);

}

ostream& operator<<(ostream& out, const SimuladorArmazem& a) {
    a.getArmazem().escrever(out);
    return out;
}


