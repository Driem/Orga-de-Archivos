// queue::push/pop
#include "Monstruo.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto monstruo (dado) en el archivo binario nombre_archivo (dado) en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Monstruo*monstruo, int posicion)
{
    /*this->cabezas=cabezas;
    this->brazos=brazos;
    this->piernas=piernas;
    this->nombre=nombre;
    this->apodo=apodo;
    this->es_carnivoro=es_carnivoro;*/
    ofstream Pika(nombre_archivo.c_str(),ios::in|ios::binary);
    if(!Pika.is_open()){
        cout<<"Upps Tuvimos un problema vuelva a intentar crear el archivo"<<endl;
    }
    Pika.seekp(33*posicion);
    Pika.write((char*)&monstruo->cabezas,4);
    Pika.write((char*)&monstruo->brazos,4);
    Pika.write((char*)&monstruo->piernas,4);
    Pika.write(monstruo->nombre.c_str(),10);
    Pika.write(monstruo->apodo.c_str(),10);
    Pika.write((char*)&monstruo->es_carnivoro,1);
    Pika.close();

    }

//Devuelve un monstruo previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Monstruo* leer(string nombre_archivo, int posicion)
{
     ifstream chu(nombre_archivo.c_str());
    chu.seekg(33*posicion);
    int NCabeza;
    int NBrazos;
    int NPiernas;
    char nombre[10];
    char apodo[10];
    bool EsPerro;

    chu.read((char*)&NCabeza,4);
    chu.read((char*)&NBrazos,4);
    chu.read((char*)&NPiernas,4);
    chu.read(nombre,10);
    chu.read(apodo,10);
    chu.read((char*)&EsPerro,1);

    chu.close();

    return new Monstruo(NCabeza,NBrazos,NPiernas,nombre,apodo,EsPerro);
}

//Devuelve el nombre del monstruo con mas cabezas previamente escrito (con la funcion escribir) en el archivo dado
string getMonstruoConMasCabezas(string nombre_archivo)
{
    list<Monstruo*>aux;
    ifstream Pikachu(nombre_archivo.c_str());
    Pikachu.seekg(0,ios::end);
    int tam = Pikachu.tellg()/33;
    Pikachu.seekg(0);

    int NCabeza;
    int NBrazos;
    int NPiernas;
    char nombre[10];
    char apodo[10];
    bool EsPerro;
    for(int i = 0; i < tam;i++){

    Pikachu.read((char*)&NCabeza,4);
    Pikachu.read((char*)&NBrazos,4);
    Pikachu.read((char*)&NPiernas,4);
    Pikachu.read(nombre,10);
    Pikachu.read(apodo,10);
    Pikachu.read((char*)&EsPerro,1);

    aux.push_back(new Monstruo(NCabeza,NBrazos,NPiernas,nombre,apodo,EsPerro));
    }
    int temp = 0;
    for(list<Monstruo*>::iterator i = aux.begin();i != aux.end();i++){
        if(temp < (*i)->cabezas){
            temp =(*i)->cabezas;
        }
    }
    for(list<Monstruo*>::iterator i = aux.begin();i != aux.end();i++){
        if(temp == (*i)->cabezas )
            return (*i)->nombre;
    }

}


int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
