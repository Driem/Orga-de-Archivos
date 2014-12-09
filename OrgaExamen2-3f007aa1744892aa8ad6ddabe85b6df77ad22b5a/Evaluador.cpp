#include "Evaluador.h"

void evaluar()
{
    int nota = 0;

    NodoAVL* n10 = new NodoAVL(10);
    NodoAVL* n5  = new NodoAVL(5);
    NodoAVL* n20 = new NodoAVL(20);
    NodoAVL* n1 = new NodoAVL(1);
    NodoAVL* n7 = new NodoAVL(7);
    NodoAVL* n8 = new NodoAVL(8);

    n10->izq = n5;
    n10->der = n20;

    n5->izq = n1;
    n5->der = n7;

    n7->der = n8;

    cout<<"obtenerNumeroAnterior:\t";
    if(obtenerNumeroAnterior(n10)==8
        && obtenerNumeroAnterior(n5)==1
        )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"obtenerNumeroSiguiente:\t";
    if(obtenerNumeroSiguiente(n10)==20
        && obtenerNumeroSiguiente(n5)==7
        )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"contarMayoresDeEdadXML:\t";
    if(contarMayoresDeEdadXML("usuarios.xml")==2
        && contarMayoresDeEdadXML("usuarios2.xml")==3)
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/12"<<endl;
}
