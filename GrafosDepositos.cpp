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

void GrafosDepositos::construirGrafo(Armazem armazem, double minDistancias, double maxDistancias){
//   
//    map<string, Deposito*>::const_iterator it;
//    map<string, Deposito*> deps;
//    vector<string>::iterator it3;
//    armazem.getDepositosReferencia(deps);
//    it = deps.begin();
//    //it3 = chaves.begin();
//    string chave;
//    int cont = 0;
//    double distancia;
//    if (deps.size() > 1) {
//        for (it = deps.begin(); it != deps.end(); it++) {
//            map<string, double> distancias;
//            if (typeid (*(it->second)) == typeid (DepositoFresco)) {
//                if (cont != 0 && cont != deps.size() - 1) {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4++;
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4, dist);
//                    map<string, Deposito*>::const_iterator vetorAdjacente;
//                    vetorAdjacente = it;
//                    vetorAdjacente++;
//                    grafo.addGraphEdge(dist, it->second, vetorAdjacente->second );
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    it4--;
//                    it4--;
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4, dist);
//                } else if (cont == 0) {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4++;
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4, dist);
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator itFim = chaves.end();
//                    itFim--;
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*itFim, dist);
//
//                } else {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4--;
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*it4, dist);
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoFresco*> (it->second)->inserirDistancia(*(chaves.begin()), dist);
//                }
//            }
//
//            if (typeid (*(it->second)) == typeid (DepositoNormal)) {
//                if (cont != 0 && cont != deps.size() - 1) {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4++;
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4, dist);
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    it4--;
//                    it4--;
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4, dist);
//                } else if (cont == 0) {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4++;
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4, dist);
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator itFim = chaves.end();
//                    itFim--;
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*itFim, dist);
//                } else {
//                    double dist = valorAleatorio(minDistancias, maxDistancias);
//                    vector<string>::iterator it4;
//                    it4 = it3;
//                    it4--;
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*it4, dist);
//                    dist = 0;
//                    dist = valorAleatorio(minDistancias, maxDistancias);
//                    dynamic_cast<DepositoNormal*> (it->second)->inserirDistancia(*(chaves.begin()), dist);
//                }
//            }
//            cont++;
//            it3++;
//        }
//    }
} 
    


