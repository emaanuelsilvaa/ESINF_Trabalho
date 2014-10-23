/* 
 * File:   SimuladorArmazem.cpp
 * Author: Miguel
 * 
 * Created on 22 de Outubro de 2014, 10:30
 */

#include "SimuladorArmazem.h"

SimuladorArmazem::SimuladorArmazem() {
    Armazem armazem(criarArmazem());


}

SimuladorArmazem::SimuladorArmazem(const SimuladorArmazem& orig) {


}

SimuladorArmazem::~SimuladorArmazem() {
}

Armazem SimuladorArmazem::criarArmazem() {
    Armazem armazem;
    if (ler.validarFicheiro()) {
        string nome;
        int min = 0, max = 0;

        nome = ler.getNomeArmazem();
        ler.getNumeroDepositosFrescos(min, max);
        this->numDepositosFrescos = valorAleatorio(min, max);
        ler.getNumeroDepositosNormais(min, max);
        this->numDepositosNormais = valorAleatorio(min, max);

        Armazem armazem(nome, numDepositosFrescos, numDepositosNormais);
        criarDepositos(armazem);
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
        string chave = "F";
        chave.append(itoa(i, tmp, 10));
        armazem.criarDepositoFresco(numeroPaletes, chave, area, capacidadeMaxima, m);
    }
    
    for (int i = 0; i < numDepositosNormais; i++) {
        int numeroPaletes = this->valorAleatorio(minPaletes, maxPaletes);
        double area = double (this->valorAleatorio(minArea, maxArea));
        int capacidadeMaxima = this->valorAleatorio(minCapacidadeMaxima, maxCapacidadeMaxima);
        map<string, double> m;
        char tmp[5];
        string chave = "N";
        chave.append(itoa(i, tmp, 10));
        armazem.criarDepositoNormal(numeroPaletes, chave, area, capacidadeMaxima, m);
    }

}

int SimuladorArmazem::valorAleatorio(int min, int max) {
    int num;
    srand(time(NULL));
    num = rand() % ((max + 1) - min) + min;
    return num;
}
//
//string SimuladorArmazem::integerTostring(int num){
//    int i;
//    char b[4];
//    
//    string s= itoa(i,b,10);
//    
//    return s;
//}
//
//SimuladorArmazem::gerarDepositos(int numeroFrescos, int numeroNormais){
//    
//    this->numeroPaletes=valorAleatorio(0,20);
//    this->chave=valorAleatorio(0,20);
//    this->chaveEmString=integerTostring(chave);
//}
