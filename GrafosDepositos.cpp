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

queue <stack <Deposito> > GrafosDepositos::diferentesCaminhos2Depositos(const string& dep1, const string& dep2){
    
    queue <stack<Deposito> > todosCaminhosDistintos;
    stack <Deposito> caminhoDoisVertices;
    bitset<MAX_VERTICES> s1;
    
    list < graphVertex <string,double> >::iterator itI;
    this->getVertexIteratorByContent(itI,dep1);
            
    list < graphVertex <string, double> >::iterator itF;
    this->getVertexIteratorByContent(itF, dep2);

    //this->diferentesCaminhos2DepositosRecursivo(itI, itF, s1, caminhoDoisVertices, todosCaminhosDistintos);

    return todosCaminhosDistintos;      
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




