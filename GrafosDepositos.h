/* 
 * File:   GrafosDepositos.h
 * Author: Paulo
 *
 * Created on 17 de Novembro de 2014, 22:45
 */

#ifndef GRAFOSDEPOSITOS_H
#define	GRAFOSDEPOSITOS_H

#include "graphStl.h"
#include "Deposito.h"
#include "Armazem.h"
#include "Matematica.h"

using namespace std;


class GrafosDepositos : public graphStl<string, double > {
public:
    GrafosDepositos();
    GrafosDepositos(const GrafosDepositos& orig);
    void construirGrafo(Armazem& armazem );
    virtual ~GrafosDepositos();
    
    string getTipoDeposito(string chave);
private:
    Matematica math;
};
ostream& operator<<(ostream& out,  GrafosDepositos & g);

#endif	/* GRAFOSDEPOSITOS_H */

