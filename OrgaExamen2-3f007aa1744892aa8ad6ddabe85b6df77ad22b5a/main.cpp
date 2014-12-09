// queue::push/pop
#include "Evaluador.h"
#include "NodoAVL.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

//Devuelve la cantidad de usuarios que tiene 18 anios o mas dado el nombre de un archivo XML
int contarMayoresDeEdadXML(string nombre_archivo)
{
    int  edad = 0;

    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* Usuarios_element = doc.FirstChildElement("Usuarios");

    for(XMLElement* usuario_element = Usuarios_element->FirstChildElement("Usuario");
         usuario_element!= NULL;
         usuario_element = usuario_element->NextSiblingElement("Usuario")){
            if(atoi(usuario_element->Attribute("edad")) >= 18)

          edad ++;
         }
         return edad;
}

//Devuelve el numero anterior del nodo raiz de un Arbol dado
int obtenerNumeroAnterior(NodoAVL* raiz)
{
    int temp1 = 0,temp2 = 0;



    if(temp1 < raiz->izq->num){
        temp1 = raiz->izq->num;
        return temp1;
    }

    if(temp2 < raiz->der->num){
        temp1 = raiz->der->num;
        return temp2;
    }
    temp1 = obtenerNumeroAnterior(raiz->izq);
    temp2 = obtenerNumeroAnterior(raiz->der);
    if(temp1 > temp2 || temp1 < raiz->num)
        return temp1;

     if(temp2 > temp1 || temp2 < raiz->num)
        return temp2;


}

//Devuelve el numero siguiente del nodo raiz de un Arbol dado
int obtenerNumeroSiguiente(NodoAVL* raiz)
{
     if(raiz->der == NULL)
        {
            return raiz->izq->num;
        }else{
            return raiz->der->num;
                    }
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
