/* 
 * File:   Deposito.h
 * Author: Paulo
 *
 * Created on 20 de Outubro de 2014, 11:17
 */

#ifndef DEPOSITO_H
#define	DEPOSITO_H

#include <map>
#include <string>
#include "Produto.h"
#include <vector>
using namespace std;

class Deposito {
public:
    Deposito();
    Deposito(const Deposito& orig);
    Deposito(int numeroPaletes, map<string, double> distancias);
    Deposito(int numeroPaletes, string chave, double area, int capacidadeMaxima, map<string, double> distancias);
    virtual ~Deposito();

    int getNumeroPaletes() const;
    void setNumeroPaletes(int numeroPaletes);
    string getChave() const;
    void setChave(string chave);
    double getArea() const;
    void setArea(double area);
    int getCapacidade() const;
    void setCapacidade(int capacidadeMaxima);
    map<string, double> getDistancias() const;
    void getDistancias(map<string, double>& dist);
    void setDistancias(const map<string, double> distancias);
    bool inserirDistancia(string chave, double distancia);

    virtual Deposito * clone() const;

    bool inserirProduto(Produto &produto);
    bool inserirProdutos(vector<Produto>& produtos);
    Produto expedir();
    vector<Produto> expedirVarios(int numeroExpedicoes);


    virtual void escrever(ostream& out) const;
    // Operadores
    virtual bool operator==(const Deposito& d) const;
    virtual Deposito& operator=(const Deposito& d);




private:
    int numeroPaletes;
    string chave;
    double area;
    int capacidadeMaxima;
    map<string, double> distancias;

};
ostream& operator<<(ostream& out, const Deposito& d);

#endif	/* DEPOSITO_H */

