/* 
 * File:   MenuUI.h
 * Author: Miguel
 *
 * Created on 6 de Dezembro de 2014, 0:56
 */

#ifndef MENUUI_H
#define	MENUUI_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "SimuladorArmazem.h"
#include "GrafosDepositos.h"
#include "Armazem.h"

using namespace std;

class MenuUI {
public:
    MenuUI();
    MenuUI(const MenuUI& orig);
    virtual ~MenuUI();
    void menu(SimuladorArmazem* SimArm);
private:
    GrafosDepositos grafo;
    Armazem armazem;

};

#endif	/* MENUUI_H */

