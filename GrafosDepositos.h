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


class GrafosDepositos : public graphStl<Deposito *,double > {
public:
    GrafosDepositos();
    GrafosDepositos(const GrafosDepositos& orig);
    void ConstruirGrafo(Armazem armazem);
    virtual ~GrafosDepositos();
private:

};

#endif	/* GRAFOSDEPOSITOS_H */

