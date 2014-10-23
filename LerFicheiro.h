/* 
 * File:   LerFicheiro.h
 * Author: Miguel
 *
 * Created on 23 de Outubro de 2014, 9:56
 */

#ifndef LERFICHEIRO_H
#define	LERFICHEIRO_H

#include <string>
using namespace std;

class LerFicheiro {
public:
    LerFicheiro();
    LerFicheiro(const LerFicheiro& orig);
    virtual ~LerFicheiro();
    
    string getNomeArmazem()const;
    bool getNumeroDepositosFrescos(int &min, int &max)const;
    bool getNumeroDepositosNormais(int &min, int &max)const;
    bool getNumeroPaletes(int &min, int &max)const;
    bool getArea(int &min, int &max)const;
    bool getCapacidadeMaxima(int &min, int &max)const;
    bool getNumeroProdutos(int &min, int &max) const;
    bool getDistancias(int &min, int &max)const;
    
    bool validarFicheiro() const;
    
    
    
private:
    string fileName;
};

#endif	/* LERFICHEIRO_H */

