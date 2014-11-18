/* 
 * File:   Armazem.cpp
 * Author: 1130647 e 1130648
 * 
 * Created on 21 de Outubro de 2014, 11:45
 */

#include "Armazem.h"

/**
 * Construtor vazio que inicia o numero de depositos frescos e normais a zero.
 */
Armazem::Armazem() {
    this->numDepositosFrescos = 0;
    this->numDepositosNormais = 0;

}

/**
 * Construtor cópia da classe Armazem
 * @param orig Armazem a ser copiado.
 */
Armazem::Armazem(const Armazem& orig) {
    this->nome = orig.nome;
    this->maxDepositosFrescos = orig.maxDepositosFrescos;
    this->maxDepositosNormais = orig.maxDepositosNormais;
    this->numDepositosFrescos = orig.numDepositosFrescos;
    this->numDepositosNormais = orig.numDepositosNormais;
    this->conjuntoDepositos = orig.getDepositos();

}

/**
 * Construtor completo da classe Armazem.
 * @param nome nome do armazem
 * @param maxDepositosFrescos numero máximo de depositos frescos
 * @param maxDepositosNormais numero maximo de depositos normais
 */
Armazem::Armazem(string nome, int maxDepositosFrescos, int maxDepositosNormais) {
    this->numDepositosFrescos = 0;
    this->numDepositosNormais = 0;
    this->maxDepositosFrescos = maxDepositosFrescos;
    this->maxDepositosNormais = maxDepositosNormais;
    this->nome = nome;
}

/**
 * Destrutor da classe Armazem.
 */
Armazem::~Armazem() {
    conjuntoDepositos.clear();
}

/**
 * Método que cria depósito fresco.
 * @param numeroPaletes do deposito.
 * @param chave do deposito.
 * @param area do deposito.
 * @param capacidadeMaxima das paletes do deposito.
 * @param distancias distancias dos depositos.
 * @return deposito fresco.
 */
DepositoFresco Armazem::criarDepositoFresco(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {

    DepositoFresco *dF = new DepositoFresco(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoFresco dF2(*dF);
    if (this->numDepositosFrescos < maxDepositosFrescos) {
        this->conjuntoDepositos[chave] = dF;
        numDepositosFrescos++;
    }

    return dF2;
}

/**
 * Método que cria depósito normal.
 * @param numeroPaletes do deposito.
 * @param chave do deposito.
 * @param area do deposito.
 * @param capacidadeMaxima das paletes do deposito.
 * @param distancias distancias dos depositos.
 * @return deposito normal.
 */
DepositoNormal Armazem::criarDepositoNormal(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {

    DepositoNormal *dN = new DepositoNormal(numeroPaletes, chave, area, capacidadeMaxima, distancias);
    DepositoNormal dN2(*dN);
    if (this->numDepositosNormais < maxDepositosNormais) {
        this->conjuntoDepositos[chave] = dN;
        numDepositosNormais++;
    }

    return dN2;
}

/**
 * Metodo que devolve o conjunto de depositos.
 * @return conjunto de depositos.
 */
map<string, Deposito*> Armazem::getDepositos() const {
    return this->conjuntoDepositos;
}

/**
 * Metodo que atribui os depositos existentes ao conjunto de depositos vazio passado por parametro.
 * @param map onde serao colocados por referencia os depositos do armazem.
 */
void Armazem::getDepositosReferencia(map<string, Deposito*>& depositos) const {
    depositos = this->conjuntoDepositos;
}

/**
 * Metodo que devolve o numero de depositos normais.
 * @return numero de depositos normais.
 */
int Armazem::getNumDepositosNormais() const {
    return this->numDepositosNormais;
}

/**
 * Metodo que devolve o numero de depositos frescos.
 * @return numero de depositos frescos.
 */
int Armazem::getNumDepositosFrescos() const {
    return this->numDepositosFrescos;
}

/**
 * Método que escreve no ecran a estrutura do armazem.
 * @param out variavel de escrita
 */
void Armazem::escrever(ostream& out) const {
    out << "\n--------------------Estrutura do Armazem: " << nome << " --------------------" << endl;
    out << "-Numero de Depositos:" << conjuntoDepositos.size() << "-" << endl;
    out << "-Numero De Depositos Frescos:" << numDepositosFrescos << "(Máximo:" << maxDepositosFrescos << ")-" << endl;
    out << "-Numero De Depositos Normais:" << numDepositosNormais << "(Máximo:" << maxDepositosNormais << ")-" << endl;
    out << "\n----------LISTAGEM DOS DEPÓSITOS:----------" << endl;
    map<string, Deposito*>::const_iterator it;
    it = conjuntoDepositos.begin();
    for (it = conjuntoDepositos.begin(); it != conjuntoDepositos.end(); it++) {
        if (typeid (*(it->second)) == typeid (DepositoFresco)) {
            dynamic_cast<DepositoFresco*> (it->second)->escrever(out);
            continue;
        }

        if (typeid (*(it->second)) == typeid (DepositoNormal)) {
            dynamic_cast<DepositoNormal*> (it->second)->escrever(out);
            continue;
        }

    }

    out << "\n ----------Fim da Estrutura do Armazem: " << nome << "----------" << endl;
}

/**
 * Método que insere produtos num armazem
 * @param produtos lista de produtos.
 * @return true se adicionar todos os produtos, se nao retorna false.
 */
bool Armazem::inserirProdutos(vector<Produto> produtos) {
    int cont = 0;
    for (int i = 0; i < produtos.size(); i++) {
        map<string, Deposito*>::const_iterator it;
        it = conjuntoDepositos.begin();
        for (it = conjuntoDepositos.begin(); it != conjuntoDepositos.end(); it++) {
            
            if (typeid (*(it->second)) == typeid (DepositoFresco)) {
                if (!dynamic_cast<DepositoFresco*> (it->second)->verificarDepositoCheio()) {
                    dynamic_cast<DepositoFresco*> (it->second)->inserirProduto(produtos.at(i));
                    cont++;
                    break;
                }
            }

            if (typeid (*(it->second)) == typeid (DepositoNormal)) {
                if (!dynamic_cast<DepositoNormal*> (it->second)->verificarDepositoCheio()) {
                    dynamic_cast<DepositoNormal*> (it->second)->inserirProduto(produtos.at(i));
                    cont++;
                    break;
                }
            }
        }

    }

    if (cont != produtos.size()) {
        return false;
    }
    return true;

}

/**
 * Método que permite expedir produtos do armazem.
 * @param numProdutos numero de produtos a expedir.
 * @return  produtos expedidos.
 */
vector<Produto> Armazem::expedir(int numProdutos) {
    vector<Produto> produtosExpedidos;
    vector<Produto> produtoRetornado;
    int max = 0;
    map<string, Deposito*>::const_iterator it;
    it = conjuntoDepositos.begin();
    for (it = conjuntoDepositos.begin(); it != conjuntoDepositos.end(); it++) {
        if (typeid (*(it->second)) == typeid (DepositoFresco)) {
            max = dynamic_cast<DepositoFresco*> (it->second)->getMaximoProdutos();
            if (max >= numProdutos) {
                produtosExpedidos = dynamic_cast<DepositoFresco*> (it->second)->expedirVarios(numProdutos);
                break;
            } else {
                produtoRetornado = dynamic_cast<DepositoFresco*> (it->second)->expedirVarios(numProdutos);
                produtosExpedidos.insert(produtosExpedidos.end(), produtoRetornado.begin(), produtoRetornado.end());
                numProdutos = numProdutos - max;
                continue;
            }
        }

        if (typeid (*(it->second)) == typeid (DepositoNormal)) {
            max = dynamic_cast<DepositoNormal*> (it->second)->getMaximoProdutos();
            if (max >= numProdutos) {
                produtosExpedidos = dynamic_cast<DepositoNormal*> (it->second)->expedirVarios(numProdutos);
                break;
            } else {
                produtoRetornado = dynamic_cast<DepositoNormal*> (it->second)->expedirVarios(numProdutos);
                produtosExpedidos.insert(produtosExpedidos.end(), produtoRetornado.begin(), produtoRetornado.end());
                numProdutos = numProdutos - max;
                continue;
            }
        }
    }
    return produtosExpedidos;
}

Armazem& Armazem::operator=(const Armazem& d) {
    if (&d == this) {
        return *this;
    }
    this->maxDepositosFrescos = d.maxDepositosFrescos;
    this->maxDepositosNormais = d.maxDepositosNormais;
    this->nome = d.nome;
    this->numDepositosFrescos = d.numDepositosFrescos;
    this->numDepositosNormais = d.numDepositosNormais;

    map<string, Deposito*> conjuntoDepositos(d.conjuntoDepositos);
}

bool Armazem::operator==(const Armazem& d) const {
    return (this->maxDepositosFrescos == d.maxDepositosFrescos &&
            this->maxDepositosNormais == d.maxDepositosNormais &&
            this->nome == d.nome &&
            this->numDepositosFrescos == d.numDepositosFrescos &&
            this->numDepositosNormais == d.numDepositosNormais &&
            std::equal(this->conjuntoDepositos.begin(), this->conjuntoDepositos.end(), d.conjuntoDepositos.begin()));
}

ostream& operator<<(ostream& out, const Armazem& a) {
    a.escrever(out);
    return out;
}
