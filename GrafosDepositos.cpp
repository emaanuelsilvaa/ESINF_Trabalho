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

queue <stack <string> > GrafosDepositos::diferentesCaminhos2Depositos(const string& dep1, const string& dep2){
    
    queue <stack<string> > todosCaminhosDistintos;
    stack <string> caminhoDoisVertices;
    bitset<MAX_VERTICES> s1;
    
    list < graphVertex <string,double> >::iterator itI;
    this->getVertexIteratorByContent(itI,dep1);
            
    list < graphVertex <string, double> >::iterator itF;
    this->getVertexIteratorByContent(itF, dep2);

    this->diferentesCaminhos2DepositosRecursivo(itI, itF, s1, caminhoDoisVertices, todosCaminhosDistintos);

   return todosCaminhosDistintos;      
}

void GrafosDepositos::diferentesCaminhos2DepositosRecursivo(list < graphVertex <string, double> >::iterator itvo,  list < graphVertex <string, double> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <string> &s, queue < stack <string> > &qr){
     taken.set(itvo->getVKey(),1);
     s.push(itvo->getVContent());

    list < graphEdge <string, double> >::iterator adjacentesBegin = itvo->getAdjacenciesBegin();
    while ( adjacentesBegin != itvo->getAdjacenciesEnd()) {       
        if (adjacentesBegin->getVDestination()== itvd ) {           
            s.push(adjacentesBegin->getVDestination()->getVContent());
            qr.push(s);
            s.pop();     
        } else {
            if (taken._Unchecked_test(adjacentesBegin->getVDestination()->getVKey()) == false) {                 
                this->diferentesCaminhos2DepositosRecursivo(adjacentesBegin->getVDestination(), itvd, taken, s, qr);
            }
        }
        
        adjacentesBegin++;
    }
    
    taken.set(itvo->getVKey(), 0);
    s.pop();
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

/**
 *  Método Para A Devolução Do Caminho Mais Curto Entre Dois Grafos.
 * @param origem Depósito Destino
 * @param destino Depósito Origem
 * @return Caminho Mais Curto com as chaves de cada depósito.
 */
stack<string> GrafosDepositos::caminhoMaisCurto(const string& origem, const string& destino){
    stack<string> s;
    queue<stack<string> > q;
    q = diferentesCaminhos2Depositos(origem, destino);
    stack<string> ret(q.front());

    double min = 500;
    double soma = 0;
    queue<stack<string> > qCopia(q);
    
    while (!qCopia.empty()) {
        stack<string> s(qCopia.front());
        stack<string> sOrdenada;
        soma = 0;
        while (!s.empty()) {
            sOrdenada.push(s.top());
            s.pop();
        }

        stack<string> s2(sOrdenada);
        while (!sOrdenada.empty()) {
            s2.pop();
            double content;
            if (!s2.empty()) {
                this->getEdgeByVertexContents(content, sOrdenada.top(), s2.top());
                soma = soma + content;
            }
            sOrdenada.pop();
        }

        if (soma < min) {
            ret=qCopia.front();
            min = soma;
        }
        qCopia.pop();
    }

    return ret;
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




