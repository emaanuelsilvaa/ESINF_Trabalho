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

Deposito::Deposito() {
    this->area=0;
    this->capacidadeMaxima=0;
    this->chave="0000";
    this->numeroPaletes=0;
    
}

Deposito::Deposito(const Deposito& orig) {
    this->area=orig.area;
    this->capacidadeMaxima=orig.capacidadeMaxima;
    this->chave=orig.chave;
    this->distancias=orig.getDistancias();
    this->numeroPaletes=orig.numeroPaletes;

}

Deposito::Deposito(int numeroPaletes, map<string, double> distancias) {
    this->numeroPaletes = numeroPaletes;
    this->distancias = map<string, double> (distancias);
}

Deposito::Deposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias) {
    this->chave = chave;
    this->area = area;
    this->capacidadeMaxima = capacidadeMaxima;
    this->numeroPaletes = numeroPaletes;
    this->distancias = map<string, double> (distancias);
}

Deposito::~Deposito() {
    this->distancias.clear();
}

Deposito * Deposito::clone() const{
    return new Deposito(*this);
}

int Deposito::getNumeroPaletes() const {
    return this->numeroPaletes;
}

void Deposito::setNumeroPaletes(int numeroPaletes) {
    this->numeroPaletes = numeroPaletes;
}

string Deposito::getChave() const {
    return this->chave;
}

void Deposito::setChave(string chave) {
    this->chave = chave;
}

double Deposito::getArea() const {
    return this->area;
}

void Deposito::setArea(double area) {
    this->area = area;
}

int Deposito::getCapacidade() const {
    return this->capacidadeMaxima;
}

void Deposito::setCapacidade(int capacidadeMaxima) {
    this->capacidadeMaxima = capacidadeMaxima;
}

map<string, double> Deposito::getDistancias() const {
    map<string, double> copia (this->distancias);
    return copia;
}

void Deposito::getDistancias(map<string,double>& dist){
    dist=this->distancias;
}

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

