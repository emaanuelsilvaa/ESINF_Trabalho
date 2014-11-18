/* 
 * File:   Matematica.h
 * Author: Paulo
 *
 * Created on 18 de Novembro de 2014, 10:16
 */

#ifndef MATEMATICA_H
#define	MATEMATICA_H

class Matematica {
public:
    Matematica();
    Matematica(const Matematica& orig);
    virtual ~Matematica();
    int valorAleatorio(int min, int max);
private:

};

#endif	/* MATEMATICA_H */

