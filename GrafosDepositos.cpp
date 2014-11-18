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

void GrafosDepositos::construirGrafo(Armazem& armazem, int minDistancias, int maxDistancias) {

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
            if (typeid (*(vetorOrigem->second)) == typeid (DepositoFresco)) {

                if (cont != 0 && cont != deps.size() - 1) {

                    int dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = vetorOrigem;
                    vetorAdjacente++;
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    addGraphEdge(dist, vetorOrigem->second, vetorAdjacente->second);
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente--;
                    vetorAdjacente--;
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);

                } else if (cont == 0) {

                    double dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = vetorOrigem;
                    vetorAdjacente++;
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = deps.end();
                    vetorAdjacente--;
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);

                } else {

                    double dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = deps.end();
                    vetorAdjacente--;
                    vetorAdjacente--;
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);


                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoFresco*> (vetorOrigem->second)->inserirDistancia((deps.begin()->second->getChave()), dist);

                }
            }

            if (typeid (*(vetorOrigem->second)) == typeid (DepositoNormal)) {
                if (cont != 0 && cont != deps.size() - 1) {
                    
                    double dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = vetorOrigem;
                    vetorAdjacente++;
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente--;
                    vetorAdjacente--;
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    
                } else if (cont == 0) {
                    
                    double dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente = vetorOrigem;
                    vetorAdjacente++;
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia(deps.end()->second->getChave(), dist);
                    
                } else {
                    
                    double dist = math.valorAleatorio(minDistancias, maxDistancias);
                    vetorAdjacente=vetorOrigem;
                    vetorAdjacente--;
                    vetorAdjacente--;
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia(vetorAdjacente->second->getChave(), dist);
                    dist = 0;
                    dist = math.valorAleatorio(minDistancias, maxDistancias);
                    dynamic_cast<DepositoNormal*> (vetorOrigem->second)->inserirDistancia((deps.begin()->second->getChave()), dist);
                    
                }
            }
            cont++;
        }
    }
}



