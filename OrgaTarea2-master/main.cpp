// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
#include "Cumpleanios.h"
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{   //La forma en que resolvi este ejercicio esta tomada de los ejemplos vistos en clase
    ofstream out(nombre_archivo.c_str());// se declara una variable ofstream para crear un archivo y recibe como parametro el nombre que le queremos asignar a este.
    for(list<Cumpleanios*>::iterator i = cumpleanios.begin();i != cumpleanios.end();i++ ){//Se crea el ciclo con iterador para que recorra toda la lista
        out<<(*i)->cumpleaniero<<" "<<(*i)->mes<<" "<<(*i)->dia<<endl;
        //Se usa el operador sobrecargador << para ingresar los elementos dentro del archivo
    //Se utiliza la lista para que los ingrese de manera mas ordenada

    }
    out.close();
    //Cierra el archivo

}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
list<Cumpleanios*> leer(string nombre_archivo)
{
    //La forma en que resolvi este ejercicio esta tomada de los ejemplos vistos en clase
    list<Cumpleanios*>cumpleanios;// Se declara la lista de objetos cumpleaños
    cumpleanios.clear();//Se limpia la lista
    ifstream in(nombre_archivo.c_str());// se abre el archivo en moda lectura
    string cumpleaniero;//
        int mes;//Se declaran las variables para que se le asignen valores con el operador sobrecargado >>
        int dia;//
    while(in>>cumpleaniero){
            in>>mes;
            in>>dia;

    cumpleanios.push_back(new Cumpleanios(cumpleaniero,dia,mes));// Se ingresa el cumpleañero el la lista de cumpleanios
    }
    return cumpleanios;// retorna la lista con todos los cumpleañeros que estaban en el archivo


}

int main ()
{

    evaluar();
    return 0;
}
