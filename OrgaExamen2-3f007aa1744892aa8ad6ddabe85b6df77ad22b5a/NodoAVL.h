#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>

class NodoAVL
{
    public:
        int num;
        NodoAVL *izq;
        NodoAVL *der;
        NodoAVL(int num)
        {
            this->num = num;
            izq = NULL;
            der = NULL;
        }
};

#endif // NODOAVL_H
