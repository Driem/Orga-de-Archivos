#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

void evaluar();

float getTemperature(string nombre_archivo);
int getHumidity(string nombre_archivo);
int getPressure(string nombre_archivo);
float getWindSpeed(string nombre_archivo);
string getCityName(string nombre_archivo);

#endif // EVALUADOR_H
