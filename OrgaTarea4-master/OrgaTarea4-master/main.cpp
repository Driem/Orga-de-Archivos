// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

//Fuente del XML:
//http://openweathermap.org/current

//Sugerencia: investigar sobre la funcion atof para convertir string a float

//Dado el formato xml en el ejemplo clima.xml realizar los siguientes ejercicios:
//Devuelve el attributo value del tag temperature
float getTemperature(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("temperature");
    return atof(current_element->Attribute("value"));
}

//Devuelve el attributo value del tag humidity
int getHumidity(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("humidity");
    return atoi(current_element->Attribute("value"));
}

//Devuelve el attributo value del tag pressure
int getPressure(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("pressure");
    return atoi(current_element->Attribute("value"));
}

//Devuelve el attributo value del tag speed dentro del tag wind
float getWindSpeed(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("wind")->FirstChildElement("speed");
    return atof(current_element->Attribute("value"));
}

//Devuelve el attributo name del tag city
string getCityName(string nombre_archivo)
{
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("city");
    return current_element->Attribute("name");

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
