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
    void getNumeroDepositosFrescos(int &min, int &max)const;
    void getNumeroDepositosNormais(int &min, int &max)const;
    void getNumeroPaletes(int &min, int &max)const;
    void getArea(int &min, int &max)const;
    void getCapacidadeMaxima(int &min, int &max)const;
    void getNumeroProdutos(int &min, int &max) const;
    void getDistancias(int &min, int &max)const;
    
    
    
    
private:
    string fileName;
};

#endif	/* LERFICHEIRO_H */

