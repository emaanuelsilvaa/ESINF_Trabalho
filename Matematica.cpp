/* 
 * File:   Matematica.cpp
 * Author: Paulo
 * 
 * Created on 18 de Novembro de 2014, 10:16
 */

#include <stddef.h>
#include <fstream>
#include "Matematica.h"

using namespace std;

Matematica::Matematica() {
}

Matematica::Matematica(const Matematica& orig) {
}

Matematica::~Matematica() {
}

/**
 * Método que origina um valor aleatório entre o valor minimo e o valor maximo.
 * @param min valor minimo  
 * @param max valor maximo
 * @return número aleatorio
 */
int Matematica::valorAleatorio(int min, int max) {
    int num;
    srand(time(NULL));
    num = rand() % ((max + 1) - min) + min;
    return num;
}
