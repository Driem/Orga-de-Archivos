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
//Codigo Tomado de Ejemplo visto en clase
float getTemperature(string nombre_archivo)
{


    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("temperature");// Se crea un elemento que apunta a current que es el elemento central o podemos decir que es la raiz
                                                                                                    //y este a su vez apunta al elemento temperatura
    return atof(current_element->Attribute("value"));//Retorna el attributo value del tag temperature y lo transforma a flotante gracias al metodo atof
}

//Devuelve el attributo value del tag humidity
int getHumidity(string nombre_archivo)
{
    XMLDocument doc; // Se crea la variable para mandar a llamar elemento
    doc.LoadFile(nombre_archivo.c_str());//Se abre el archivo XML
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("humidity");// Se crea un elemento que apunta a current que es el elemento central o podemos decir que es la raiz
                                                                                                    //y este a su vez apunta al elemento humidity
    return atoi(current_element->Attribute("value"));//Devuelve el attributo value del tag humidity y lo convierte a int gracias al metodo atoi
}

//Devuelve el attributo value del tag pressure
int getPressure(string nombre_archivo)
{
    XMLDocument doc; // Se crea la variable para mandar a llamar elemento
    doc.LoadFile(nombre_archivo.c_str());//Se abre el archivo XML
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("pressure");// Se crea un elemento que apunta a current que es el elemento central o podemos decir que es la raiz
                                                                                                    //y este a su vez apunta al elemento pressure
    return atoi(current_element->Attribute("value")); //Devuelve el attributo value del tag pressure y lo convierte a int gracias al metodo atoi
}

//Devuelve el attributo value del tag speed dentro del tag wind
float getWindSpeed(string nombre_archivo)
{
    XMLDocument doc; // Se crea la variable para mandar a llamar elemento
    doc.LoadFile(nombre_archivo.c_str());//Se abre el archivo XML
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("wind")->FirstChildElement("speed");// Se crea un elemento que apunta a current que es el elemento central o podemos decir que es la raiz
                                                                                                                         //y este a su vez apunta al elemento wind que tambien apunta a speed (Me gusto ahorrarme codigo :D)
    return atof(current_element->Attribute("value"));//Devuelve el attributo value del tag speed dentro del tag wind
}

//Devuelve el attributo name del tag city
string getCityName(string nombre_archivo)
{
    XMLDocument doc; // Se crea la variable para mandar a llamar elemento
    doc.LoadFile(nombre_archivo.c_str());//Se abre el archivo XML
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("city");// Se crea un elemento que apunta a current que es el elemento central o podemos decir que es la raiz
                                                                                                    //y este a su vez apunta al elemento city
    return current_element->Attribute("name");//Devuelve el attributo name del tag city

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
