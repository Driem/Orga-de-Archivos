// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in|ios::binary);//Se abre el archivo en en modo binario
    out.seekp(24*posicion);//Se delimita la posicion donde se escribira por eje si la posicion es 2 se situara a los 48 bits del archivo
    out.write((char*)&mascota->edad,4);//Se escribe la edad de la mascota y se especifica la cantidad de bytes que utiliza
    out.write(mascota->nombre.c_str(),20);//Se escribe el nombre de la mascota y se especifica la cantidad de bytes que utiliza
    out.close();// Se cierra el Archivo


}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());//Se abre el archivo
    in.seekg(24*posicion);// Se situa en la posicion e bytes del archivo
        char nombre[20];//Variabe para guardar nombre de la mascosa
        int edad;// Variable para guardar edad de la mascota
    in.read((char*)&edad,4);//Aqui se obtiene la edad de la mascota y la guarda en la variable pero se tiene que castear por que se obtiene char y se pasa a int
    in.read(nombre,20);//Aqui se obtiene el nombre de la mascota y la guarda en la variable
    in.close();// Se cierra el archivo

    return new Mascota(edad,nombre);// Devuelve un objeto mascota al que se ingresa el nombre y la edad por su constructor
}


//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;//Se crea el vector
    //list<Mascota*>aux;
     ifstream in(nombre_archivo.c_str());// Se abre el archivo
    in.seekg(0,ios::end);// Nos situamos al final del programa
    int tam = in.tellg()/24;//Obtenemos el tamaño que tiene el archivo por que el tell.g() nos retorna la cantidad de bytes de archivo
    in.seekg(0);//
//Se abre el ciclo y se repite lo que se hizo en la funcion Leer();
    for(int i = 0; i < tam;i++)
    {
        int edad;
        char nombre[20];

        in.read((char*)&edad,4);
        in.read(nombre,20);

        respuesta.push_back(new Mascota(edad,nombre));//Se ingresa los objetos en el vector

        }
    //    aux.reverse();
//        for(list<Mascota*>::iterator i = aux.begin();i != aux.end();i++)
  //          respuesta.push_back(new Mascota((*i)->edad,(*i)->nombre));


    return respuesta;//Retorna el Vector
}

int main ()
{
    evaluar();
    return 0;
}
