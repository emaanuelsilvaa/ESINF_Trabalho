/* 
 * File:   LerFicheiro.cpp
 * Author: Miguel
 * 
 * Created on 23 de Outubro de 2014, 9:56
 */

#include "LerFicheiro.h"
#include <fstream>
#include <iostream>

LerFicheiro::LerFicheiro() {
}

LerFicheiro::LerFicheiro(const LerFicheiro& orig) {
}

LerFicheiro::~LerFicheiro() {
}

string LerFicheiro::getNomeArmazem() const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;
    string nome;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("Nome:") != std::string::npos) {
            int inicio = linha.find("Nome:");
            nome = linha.substr(inicio + 5);

        }

    }
    origem.close();
    return nome;
}

bool LerFicheiro::getNumeroDepositosFrescos(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("NumeroDepositosFrescos:[") != std::string::npos) {
            int mInicio = linha.find("NumeroDepositosFrescos:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 24, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;

        }      

    }
    
    origem.close();
    return false;
}

bool LerFicheiro::getNumeroDepositosNormais(int &min, int &max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("NumeroDepositosNormais:[") != std::string::npos) {
            int mInicio = linha.find("NumeroDepositosNormais:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 24, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;
        }

    }
    origem.close();
    return false;

}

bool LerFicheiro::getNumeroPaletes(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("NumeroPaletes:[") != std::string::npos) {
            int mInicio = linha.find("NumeroPaletes:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 15, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;
        }

    }
    origem.close();
    return false;
}

bool LerFicheiro::getArea(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("Area:[") != std::string::npos) {
            int mInicio = linha.find("Area:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 6, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            
            return true;
        }
    }
    origem.close();
    return false;
}

bool LerFicheiro::getCapacidadeMaxima(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("CapacidadeMaxima:[") != std::string::npos) {
            int mInicio = linha.find("CapacidadeMaxima:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 18, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;
        }
    }
    origem.close();
    return false;
}

bool LerFicheiro::getNumeroProdutos(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("NumeroProdutos:[") != std::string::npos) {
            int mInicio = linha.find("NumeroProdutos:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 16, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;
        }
    }
    origem.close();
    return false;
}

bool LerFicheiro::getDistancias(int& min, int& max) const {
    ifstream origem;
    origem.open("ficheiroLer.txt");

    string linha;

    while (!origem.eof()) {
        getline(origem, linha, '\n');
        if (linha.find("Distancias:[") != std::string::npos) {
            int mInicio = linha.find("Distancias:[");
            int mFim = linha.find(",");
            int maInicio = linha.find(",");
            int maFim = linha.find("]\n");
            min = atoi(linha.substr(mInicio + 12, mFim).c_str());
            max = atoi(linha.substr(maInicio + 1, maFim).c_str());
            return true;
        }
    }
    return false;
}

bool LerFicheiro::validarFicheiro() const {
    int numDepositosFrescos, numDepositosNormais, maxPaletes, minPaletes, maxArea, minArea, maxProdutos, minProdutos, maxCapacidadeMaxima, minCapacidadeMaxima, minDistancias, maxDistancias;
    if(!getNumeroPaletes(minPaletes, maxPaletes)){
        return false;
    }
    if(!getArea(minArea, maxArea)){
        return false;
    }
    if(!getNumeroProdutos(minProdutos, maxProdutos)){
        return false;
    }
    
    if(!getCapacidadeMaxima(minCapacidadeMaxima, maxCapacidadeMaxima)){
        return false;
    }
    
    if(!getDistancias(minDistancias, maxDistancias)){
        return false;
    }

    if(minPaletes>maxPaletes){
        return false;
    }
    if(minArea>maxArea){
        return false;
    }
    if(minProdutos>maxProdutos){
        return false;
    }
     if(minCapacidadeMaxima>maxCapacidadeMaxima){
        return false;
    }
    if(minDistancias>maxDistancias){
        return false;
    }
    
    return true;


}

