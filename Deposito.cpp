/* 
 * File:   Deposito.cpp
 * Author: Paulo
 * 
 * Created on 20 de Outubro de 2014, 11:17
 */

#include "Deposito.h"
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Construtor vazio da classe Deposito.
 */
Deposito::Deposito() {
    this->area=0;
    this->capacidadeMaxima=0;
    this->chave="0000";
    this->numeroPaletes=0;
    
}

/**
 * Construtor cópia da classe Deposito.
 * @param orig deposito a ser copiado.
 */
Deposito::Deposito(const Deposito& orig) {
    this->area=orig.area;
    this->capacidadeMaxima=orig.capacidadeMaxima;
    this->chave=orig.chave;
    this->distancias=orig.getDistancias();
    this->numeroPaletes=orig.numeroPaletes;

}

/**
 * Construtor da classe Deposito.
 * @param numeroPaletes numero de paletes do deposito.
 * @param distancias dos depositos vazios.
 */
Deposito::Deposito(int numeroPaletes, map<string, double> distancias) {
    this->numeroPaletes = numeroPaletes;
    this->distancias = map<string, double> (distancias);
}

/**
 * Construtor completo da classe Deposito.
 * @param numeroPaletes numero de paletes do deposito.
 * @param chave do deposito.
 * @param area area do deposito.
 * @param capacidadeMaxima das paletes do deposito.
 * @param distancias dos depositos vizinhos.
 */
Deposito::Deposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    this->chave = chave;
    this->area = area;
    this->capacidadeMaxima = capacidadeMaxima;
    this->numeroPaletes = numeroPaletes;
    this->distancias = map<string, double> (distancias);
}

/**
 * Construtor vazio da classe Deposito.
 */
Deposito::~Deposito() {
    this->distancias.clear();
}

/**
 * Método que clona um deposito.
 * @return o deposito.
 */
Deposito * Deposito::clone() const{
    return new Deposito(*this);
}

/**
 * Metodo que devolve o numero de paletes.
 * @return numero paletes.
 */
int Deposito::getNumeroPaletes() const {
    return this->numeroPaletes;
}

/**
 * Metodo que modifica o numero de paletes.
 * @param numeroPaletes novo numero de paletes.
 */
void Deposito::setNumeroPaletes(int numeroPaletes) {
    this->numeroPaletes = numeroPaletes;
}

/**
 * Metodo que devolve a chave do deposito.
 * @return chave do deposito.
 */
string Deposito::getChave() const {
    return this->chave;
}

/**
 * Metodo que modifica a chave do deposito.
 * @param chave nova chave do deposito.
 */
void Deposito::setChave(string chave) {
    this->chave = chave;
}

/**
 * Metodo que devolve a area do deposito.
 * @return area do deposito.
 */
double Deposito::getArea() const {
    return this->area;
}

/**
 * Metodo que modifica a area do deposito.
 * @param area nova area do deposito.
 */
void Deposito::setArea(double area) {
    this->area = area;
}

/**
 * Metodo que devolve a capacidade maxima das paletes do deposito. 
 * @return capacidade maxima das paletes.
 */
int Deposito::getCapacidade() const {
    return this->capacidadeMaxima;
}

/**
 * Metodo que modifica a capacidade maxima das paletes do deposito.
 * @param capacidadeMaxima noca capacidade maxima.
 */
void Deposito::setCapacidade(int capacidadeMaxima) {
    this->capacidadeMaxima = capacidadeMaxima;
}

/**
 * Método que devolve uma copia das distancias dos depositos.
 * @return copia da map com as distancias e a chave.
 */
map<string, double> Deposito::getDistancias() const {
    map<string, double> copia (this->distancias);
    return copia;
}

/**
 * Metodo que insere a distancia num map vazio recebido por parametro.
 * @param dist map vazio.
 */
void Deposito::getDistancias(map<string,double>& dist){
    dist=this->distancias;
}
/**
 * Metodo que irá inserir distanciabnum deposito.
 * @param chave do deposito.
 * @param distancia distancia do deposito.
 * @return true se inserir distancia, false se nao inserir(porque já tem as duas distancias dos depositos vizinhos.)
 */ 
bool Deposito::inserirDistancia(string  chave, double distancia) {
    if (this->distancias.size() < 2) {
        this->distancias[chave] = distancia;
        return true;
    }
    return false;

}

Deposito& Deposito::operator=(const Deposito& d) {
    if (&d == this) {
        return *this;
    }
    this->area = d.getArea();
    this->capacidadeMaxima = d.getCapacidade();
    this->chave = d.getChave();
    this->distancias=d.getDistancias();
    this->numeroPaletes = d.getNumeroPaletes();

    return *this;

}

bool Deposito::operator==(const Deposito& d) const {
    return (this->area == d.getArea() && this->capacidadeMaxima == d.getCapacidade() && this->chave == d.getChave() && this->numeroPaletes == d.getNumeroPaletes()
            && std::equal(this->distancias.begin(), this->distancias.end(), d.getDistancias().begin()));
}

/**
 * Metodo que vai escrever no ecran a estrutura do Deposito.
 * @param out variavel de escrita.
 */
void Deposito::escrever(ostream& out) const {
    out << "\n----------Depósito:---------- " << endl;
    string chave = "SEM CHAVE";
    chave = this->chave;
    out << "Chave:" << chave << endl;
    int numeroP = 0;
    numeroP = this->numeroPaletes;
    out << "Numero Paletes:" << numeroP << endl;
    double area = 0;
    area = this->area;
    out << "Area:" << area << endl;
    out << "Distâncias: " << endl;

    map<string, double>::iterator it;
    map<string, double> copia(this->distancias);
    if (!copia.empty()) {
        for (it = copia.begin(); it != copia.end(); it++) {
            out << "    Chave do Deposito:" << it->first << " está a " << it->second << " metros de distância." << endl;
        }
    } else {
        out << "--Sem Depósitos Vizinhos--" << endl;
    }
}

ostream& operator<<(ostream& out, const Deposito& d) {
    d.escrever(out);
    return out;
}

