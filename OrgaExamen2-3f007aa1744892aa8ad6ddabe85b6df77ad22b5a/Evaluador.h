#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
#include "NodoAVL.h"
using namespace std;
using namespace tinyxml2;

void evaluar();

int contarMayoresDeEdadXML(string nombre_archivo);
int obtenerNumeroAnterior(NodoAVL* raiz);
int obtenerNumeroSiguiente(NodoAVL* raiz);

#endif // EVALUADOR_H
