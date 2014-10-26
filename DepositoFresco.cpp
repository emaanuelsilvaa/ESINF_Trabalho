/* 
 * File:   DepositoFresco.cpp
 * Author: 1130647 e 1130648
 * 
 * Created on 21 de Outubro de 2014, 9:56
 */

#include "DepositoFresco.h"
#include <iostream>
using namespace std;

/**
 * Construtor vazio da classe Depositofresco que invoca o construtor vazio da classe Deposito.
 */
DepositoFresco::DepositoFresco() : Deposito() {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

/**
 * Construtor copia da classe DepositoFresco que invoca o construtor copia da classe Deposito.
 * @param orig deposito fresco a copiar.
 */
DepositoFresco::DepositoFresco(const DepositoFresco& orig) : Deposito(orig) {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

/**
 * Construtor da classe DepositoFresco que invoca o construtor da classe Deposito.
 * @param numeroPaletes do deposito.
 * @param chave do deposito.
 * @param area area do deposito.
 * @param capacidadeMaxima capacidade maxima das paletes do deposito.
 * @param distancias distancias dos depositos vizinhos.
 */
DepositoFresco::DepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) : Deposito(numeroPaletes, chave, area, capacidadeMaxima, distancias) {
    this->ordemProduto = 0;
    this->produtoInicial = 0;
    criarPaletes();
}

/**
 * Destrutor da classe DepositoFresco que invoca o destrutor da classe Deposito.
 */
DepositoFresco::~DepositoFresco() {
    this->Deposito::~Deposito();
    paletes.clear();
}


/**
 * Metodo que cria paletes num deposito fresco.
 */
void DepositoFresco::criarPaletes() {
    int paletesACriar = getNumeroPaletes() - paletes.size();
    for (int i = 0; i < paletesACriar; i++) {
        queue< map<double, Produto> > conjunto;
        this->paletes.push_back(conjunto);
    }
}

/**
 * Metodo que devolve a ordem do produto.
 * @return ordem do produto.
 */
double DepositoFresco::getOrdemProduto() const{
    return this->ordemProduto;
}

/**
 * Metodo que modifica o numero de paletes de um deposito fresco.
 * @param numeroPaletes novo numero de paletes.
 */
void DepositoFresco::setNumeroPaletes(int numeroPaletes) {
    this->Deposito::setNumeroPaletes(numeroPaletes);
    criarPaletes();
}

/**
 * Metodo que insere produto num deposito fresco.
 * @param produto a inserir
 * @return  true se inseriu, false se nao.
 */
bool DepositoFresco::inserirProduto(Produto& produto) {
    int posicaoMenorCarga = verificarMenorCarga();
        if (getNumeroPaletes()>0 &&paletes.at(posicaoMenorCarga).size() < getCapacidade()) {
            map<double, Produto> m;
            m[ordemProduto] = produto;
            paletes.at(posicaoMenorCarga).push(m);
            ordemProduto++;
            return true;
        }
    return false;
}

/**
 * Metodo que insere produtos num deposito fresco.
 * @param produtos produtos a inserir.
 * @return true se inseriu todos, false se nao.
 */
bool DepositoFresco::inserirProdutos(vector<Produto>& produtos){ 
    for(int i=0; i<produtos.size(); i++){
        if(!inserirProduto(produtos.at(i))){
            return false;
        }
    }
    return true;
}

/**
 * Metodo que verifica a palete com menor carga.
 * @return posicao de menor carga.
 */
int DepositoFresco::verificarMenorCarga() {
    int posicaoMenorCarga = 0;
    int it = 0;
    for (it = 0; it < paletes.size(); it++) {
        if (paletes.at(it).size() < paletes.at(posicaoMenorCarga).size()) {
            posicaoMenorCarga = it;
        }
    }
    return posicaoMenorCarga;
}

/**
 * Metodo que expede um produto.
 * @return produto expedido.
 */
Produto DepositoFresco::expedir() {
    Produto produto("SEM PRODUTO");

    if (produtoInicial > ordemProduto || ordemProduto == 0) {
        return produto;
    }

    for (int i = 0; i < paletes.size(); i++) {
        map<double, Produto> copia2 = paletes.at(i).front();
        map<double, Produto>::iterator it;
        it = copia2.begin();

        if (it->first == produtoInicial) {
            produto = it->second;
            paletes.at(i).pop();
            produtoInicial++;
            return produto;
        }
    }
    return produto;
}

/**
 * Metodo que expede vários produtos.
 * @param numeroExpedicoes no deposito fresco.
 * @return lista de produtos expedidos.
 */
vector<Produto> DepositoFresco::expedirVarios(int numeroExpedicoes) {
    vector<Produto> listaProdutos;

    for (int k = 0; k < numeroExpedicoes; k++) {
        Produto produto;
        produto = this->expedir();
        if (produto.getProduto() == "SEM PRODUTO") {
            return listaProdutos;
        } else {
            listaProdutos.push_back(produto);
        }

    }
    return listaProdutos;
}

/**
 * Metodo que escreve no ecran a estrutura do deposito fresco.
 * @param out variavel de escrita.
 */
void DepositoFresco::escrever(ostream& out) const {
    this->Deposito::escrever(out);
    out << "\nTIPO DE DEPÓSITO: DEPÓSITO FRESCO" <<endl;
    out << "Listagem de Paletes:";
    
    if(!paletes.empty()){
    for (int i = 0; i<this->getNumeroPaletes(); i++) {
        out << "\n-Palete Nº:" << i << endl;
        if (!paletes.at(i).empty()) {
                queue<map<double, Produto> > copia(paletes.at(i));
                while (!copia.empty()) {
                    map<double, Produto> copiaProduto = copia.front();
                    map<double, Produto>::iterator it = copiaProduto.begin();
                    out << "---" << "NºdeOrdem:" << it->first << ":" << " Produto:" << it->second.getProduto() << "---" << endl;
                    copia.pop();
                }
        } else {
            out << "\n---Palete Vazia---" << endl;
        }
    }
}else{
        out << "\n--Sem Paletes--" <<endl;
}
    out << "\n ----------Fim de Depósito----------" << endl;
}

/**
 * Metodo que devolve as paletes do deposito fresco.
 * @return paletes.
 */
vector<queue< map<double, Produto> > > DepositoFresco::getPaletes() const {
    return paletes;
}

/**
 * Metodo que modifica as paletes.
 * @param p novas paletes.
 */
void DepositoFresco::setPaletes(vector<queue<map<double, Produto> > > p) {
    vector<queue< map<double, Produto> > > paletes(p);
}

bool DepositoFresco::operator==(const DepositoFresco& d) const {
        if(!this->Deposito::operator ==(d)){
            return false;           
        }

    if (!verificarIgualdadePaletes(d)) {
        return false;
    }
    
    return (this->ordemProduto == d.ordemProduto && this->produtoInicial == d.produtoInicial);

}

DepositoFresco& DepositoFresco::operator =(const DepositoFresco& d){
    if(&d==this){
        return *this;
    }
    
    (*this).Deposito::operator =(d);
    this->ordemProduto=d.ordemProduto;
    this->produtoInicial=d.produtoInicial;
    vector<queue< map<double,Produto> > > paletes (d.getPaletes());
}

/**
 * Metodo que verifica se dois depositos têm as mesmas paletes.
 * @param d deposito fresco
 * @return true se se verificar a igualdade, false se nao.
 */
bool DepositoFresco::verificarIgualdadePaletes(const DepositoFresco& d)const {
    if (this->paletes.size() != d.getPaletes().size()) {
        return false;
    }
    
    for (int i = 0; i < paletes.size(); i++) {
        if (paletes.at(i).size() != d.getPaletes().at(i).size()) {
            return false;
        } else {

            queue<map<double, Produto> > copia(paletes.at(i));
            queue<map<double, Produto> > copia2(d.getPaletes().at(i));
            while (!copia.empty()) {
                map<double, Produto> copiaProduto = copia.front();
                map<double, Produto> copiaProduto2 = copia.front();
                map<double, Produto>::iterator it = copiaProduto.begin();
                map<double, Produto>::iterator it2 = copiaProduto2.begin();
                if (it->first != it2->first || it->second.getProduto() != it->second.getProduto()) {
                    return false;
                }
                copia.pop();
                copia2.pop();
            }
        }

    }
    return true;
}

/**
 * Metodo que devolve o numero maximo de produtos de um deposito fresco.
 * @return numero maximo de produtos.
 */
int DepositoFresco::getMaximoProdutos() const{
    int numeroPal=this->getNumeroPaletes();
    int capacidadeMax=this->getCapacidade();
    return capacidadeMax*numeroPal;
}

/**
 * Metodo que verifica se o deposito fresco esta cheio.
 * @return true se estiver cheio, false se nao estiver cheio.
 */
bool DepositoFresco::verificarDepositoCheio() {


    for (int i = 0; i < getNumeroPaletes(); i++) {
        if (getPaletes().at(i).size() != getCapacidade()) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& out, const DepositoFresco& d) {
    d.escrever(out);
    return out;
}

