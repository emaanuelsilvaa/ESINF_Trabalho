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
    
    while(!origem.eof()){
        getline(origem, linha, '\n');
        if(linha.find("Nome:") !=std::string::npos){
            int inicio=linha.find ("Nome:");
            nome=linha.substr(inicio+5);
            
        }
        
    }
    return nome;
}

void LerFicheiro::getNumeroDepositosFrescos(int& min, int& max) const {
     ifstream origem;
    origem.open("ficheiroLer.txt");
    
    string linha;

    while(!origem.eof()){
        
        getline(origem, linha, '\n');
        if(linha.find("NumeroDepositosFrescos:[") !=std::string::npos){
            int mInicio=linha.find ("NumeroDepositosFrescos:[");
            int mFim= linha.find(",");
           // min= itoa(linha.substr(mInicio+1,mFim));
            cout << min << endl;
            
        }
        
    }

}

