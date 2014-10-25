/* 
 * File:   DepositoNormal.cpp
 * Author: Miguel
 * 
 * Created on 20 de Outubro de 2014, 10:49
 */

#include "DepositoNormal.h"
#include <iostream>
using namespace std;

/**
 * Construtor vazio da classe DepositoNormal que invoca o construtor vazio da classe Deposito.
 */
DepositoNormal::DepositoNormal() : Deposito() {
    this->ordemProduto = 0;
    criarPaletes();
}

/**
 * Construtor copia da classe DepositoNormal que invoca o construtor copia da classe Deposito.
 * @param orig deposito normal a copiar.
 */
DepositoNormal::DepositoNormal(const DepositoNormal& orig) : Deposito(orig) {
    this->ordemProduto = 0;
    criarPaletes();
}

/**
 * Construtor da classe DepositoNormal que invoca o construtor da classe Deposito.
 * @param numeroPaletes do deposito.
 * @param chave do deposito.
 * @param area area do deposito.
 * @param capacidadeMaxima capacidade maxima das paletes do deposito.
 * @param distancias distancias dos depositos vizinhos.
 */
DepositoNormal::DepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) : Deposito(numeroPaletes, chave, area, capacidadeMaxima, distancias) {
    this->ordemProduto = 0;
    criarPaletes();
}

/**
 * Destrutor da classe DepositoNormal.
 */
DepositoNormal::~DepositoNormal() {
    this->paletes.clear();
}

/**
 * Metodo que cria paletes num deposito normal.
 */
void DepositoNormal::criarPaletes() {
    int paletesACriar = getNumeroPaletes() - paletes.size();
    for (int i = 0; i < paletesACriar; i++) {
        stack< Produto> conjunto;
        this->paletes.push_back(conjunto);
    }
}

/**
 * Metodo que devolve a ordem do produto.
 * @return ordem do produto.
 */
double DepositoNormal::getOrdemProduto()const {
    return this->ordemProduto;
}

/**
 * Metodo que modifica a ordem de um produto de um deposito normal.
 * @param ordem nova ordem do produto.
 */
void DepositoNormal::setOrdemProduto(int ordem) {
    this->ordemProduto = ordem;
}

/**
 * Metodo que devolve as paletes do deposito normal.
 * @return paletes.
 */
vector<stack<Produto> > DepositoNormal::getPaletes()const {
    return this->paletes;
}

/**
 * Metodo que modifica o numero de paletes do deposito normal.
 * @param numeroPaletes novo numero de paletes.
 */
void DepositoNormal::setNumeroPaletes(int numeroPaletes) {
    this->Deposito::setNumeroPaletes(numeroPaletes);
    criarPaletes();
}

/**
 * Metodo que verifica se o deposito normal esta cheio.
 * @return true se estiver cheio, false se nao estiver cheio.
 */
bool DepositoNormal::verificarDepositoCheio() {


    for (int i = 0; i < getNumeroPaletes(); i++) {
        if (getPaletes().at(i).size() != getCapacidade()) {
            return false;
        }
    }
    return true;
}

/**
 * Metodo que insere produto num deposito normal.
 * @param produto a inserir
 * @return  true se inseriu, false se nao.
 */
bool DepositoNormal::inserirProduto(Produto& produto) {

    int it;

    for (it = 0; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() < getCapacidade()) {
            paletes.at(it).push(produto);
            ordemProduto++;
            return true;
        }
    }
    for (it = 1; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() < getCapacidade() / 2) {
            paletes.at(it).push(produto);
            ordemProduto++;
            return true;
        }
    }
    return false;
}

/**
 * Metodo que insere produtos num deposito normal.
 * @param produtos produtos a inserir.
 * @return true se inseriu todos, false se nao.
 */
bool DepositoNormal::inserirProdutos(vector<Produto> produtos) {
    int i;

    for (i = 0; i < produtos.size(); i++) {

        if (!inserirProduto(produtos.at(i))) {
            return false;
        }
    }
    return true;
}

/**
 * Metodo que expede um produto.
 * @return produto expedido.
 */
Produto DepositoNormal::expedir() {
    Produto produto("SEM PRODUTO");

    if (ordemProduto == 0) {
        return produto;
    }

    int it;

    for (it = 1; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() > 0) {
            produto = paletes.at(it).top();
            paletes.at(it).pop();
            return produto;
        }
    }
    for (it = 0; it < paletes.size(); it = it + 2) {
        if (paletes.at(it).size() > 0) {
            produto = paletes.at(it).top();
            paletes.at(it).pop();
            return produto;
        }
    }

    return produto;
}

/**
 * Metodo que devolve o numero maximo de produtos de um deposito normal.
 * @return numero maximo de produtos.
 */
int DepositoNormal::getMaximoProdutos() const{
    int numeroPal=this->getNumeroPaletes();
    int capacidadeMax=this->getCapacidade();
    int maxProdutos=0;
    if(numeroPal%2 ==0){
        maxProdutos= (numeroPal/2)*capacidadeMax;
        maxProdutos+=(numeroPal/2)*capacidadeMax/2;
    }else{
        maxProdutos= ((numeroPal/2)+1)*capacidadeMax;
        maxProdutos+=(numeroPal-(numeroPal/2)+1)*capacidadeMax/2;
    }
    return maxProdutos;
}

/**
 * Metodo que expede vários produtos.
 * @param numeroExpedicoes no deposito normal.
 * @return lista de produtos expedidos.
 */
vector<Produto> DepositoNormal::expedirVarios(int numeroExpedicoes) {
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
 * Metodo que escreve no ecran a estrutura do deposito normal.
 * @param out variavel de escrita.
 */
void DepositoNormal::escrever(ostream& out) const {
    this->Deposito::escrever(out);
    out << "\nTIPO DE DEPÓSITO: DEPÓSITO NORMAL" << endl;
    out << "Listagem de Paletes:";
    if(this->paletes.empty()){
        out << "\n---Sem Paletes---"<<endl;
    }
    for (int i = 0; i<this->getNumeroPaletes(); i++) {
        out << "\n-Palete Nº:" << i << endl;
        if (!paletes.at(i).empty()) {
            stack< Produto> copia(paletes.at(i));
            while (!copia.empty()) {
                Produto produto = copia.top();
                out << "Produto:" << produto.getProduto() << "---" << endl;
                copia.pop();
            }
        } else {
            out << "\n---Palete Vazia---" << endl;
        }
    }
    out << "\n ----------Fim de Depósito----------" << endl;
}

bool DepositoNormal::operator==(const DepositoNormal& d)const{

    if (!this->Deposito::operator==(d)) {
        return false;
    }
    if (!verificarIgualdadePaletes(d)){
        return false;
    }

    return(this->ordemProduto== d.ordemProduto);
}

/**
 * Metodo que verifica se dois depositos têm as mesmas paletes.
 * @param d deposito normal
 * @return true se se verificar a igualdade, false se nao.
 */
bool DepositoNormal::verificarIgualdadePaletes(const DepositoNormal& d)const{

    if (this->paletes.size()!=d.getPaletes().size()){
        return false;
    }
    
    for (int i = 0; i < paletes.size(); i++) {
        if (paletes.at(i).size() != d.getPaletes().at(i).size()) {
            return false;
        } else {
            
            stack<Produto> copia(paletes.at(i));
            stack<Produto> copia2(d.getPaletes().at(i));
            while(!copia.empty()){
                Produto copiaProduto= copia.top();
                Produto copiaProduto2= copia2.top();
                if(copiaProduto.getProduto()!=copiaProduto2.getProduto()){
                    return false;
                }
               
                copia.pop();
                copia2.pop();
            }
        }
           
    }
    return true;   
}

DepositoNormal& DepositoNormal::operator =(const DepositoNormal& d){
    if(&d==this){
        return *this;
    }
    
    (*this).Deposito::operator =(d);
    this->ordemProduto=d.ordemProduto;
    vector<stack<Produto> > paletes (d.getPaletes());
}              

ostream& operator<<(ostream& out, const DepositoNormal& d) {
    d.escrever(out);
    return out;
}
