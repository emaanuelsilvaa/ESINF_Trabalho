/* 
 * File:   GrafosDepositos.cpp
 * Author: Paulo
 * 
 * Created on 17 de Novembro de 2014, 22:45
 */

#include "GrafosDepositos.h"

GrafosDepositos::GrafosDepositos() {
}

GrafosDepositos::GrafosDepositos(const GrafosDepositos& orig) {
}

GrafosDepositos::~GrafosDepositos() {
}

void GrafosDepositos::construirGrafo(Armazem& armazem) {
    map<string, Deposito*> deps;
    map<string, Deposito*>::const_iterator vetorOrigem;
    armazem.getDepositosReferencia(deps);
    int associacoes = 0;
    for (vetorOrigem = deps.begin(); vetorOrigem != deps.end(); vetorOrigem++) {
        map<string, double> distancias(vetorOrigem->second->getDistancias());
        map<string, double>::iterator it;
        for (it = distancias.begin(); it != distancias.end(); it++) {
            Deposito * d = armazem.getDepositoPorChave(it->first);
            if (d != NULL) {
                addGraphEdge(it->second, vetorOrigem->second->getChave(), armazem.getDepositoPorChave(it->first)->getChave());
                associacoes++;
            }
        }     
    } 
    
}

string GrafosDepositos::getTipoDeposito(string chave){
    if(chave.find("Normal_") != std::string::npos){
        return "Normal";
    }else if(chave.find("Fresco_") != std::string::npos){
        return "Fresco";
    }
    return "INVALIDO";
}

ostream& operator<<(ostream& out, GrafosDepositos & g) {
    g.write(out);
    return out;
}




