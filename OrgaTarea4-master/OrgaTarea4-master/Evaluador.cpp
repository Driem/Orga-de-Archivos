#include "Evaluador.h"

//bool compararListas(list<Cumpleanios*>l1, list<Cumpleanios*>l2)
//{
//    if(l1.size()!=l2.size())
//        return false;
//
//    list<Cumpleanios*>::iterator j = l2.begin();
//    for(list<Cumpleanios*>::iterator i = l1.begin();
//            i!=l1.end();
//            i++)
//    {
//        if((*i)->cumpleaniero != (*j)->cumpleaniero
//            || (*i)->mes != (*j)->mes
//            || (*i)->dia != (*j)->dia)
//            return false;
//        j++;
//    }
//    return true;
//}

void evaluar()
{
    int nota = 0;

//    list<Cumpleanios*>cumpleanios;
//    cumpleanios.push_back(new Cumpleanios("rufino",20,11));
//    cumpleanios.push_back(new Cumpleanios("julian",10,2));
//    cumpleanios.push_back(new Cumpleanios("tribilin",40,5));
//
//    escribir("prueba_evaluador", cumpleanios);
//

    cout<<"getTemperature:\t";
    if(getTemperature("clima.xml")==295.09f && getTemperature("clima2.xml")==279.71f)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"getHumidity: \t";
    if(getHumidity("clima.xml")==78 && getHumidity("clima2.xml")==87)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"getPressure: \t";
    if(getPressure("clima.xml")==1018 && getPressure("clima2.xml")==1023)
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"getWindSpeed: \t";
    if(getWindSpeed("clima.xml")==4.1f && getWindSpeed("clima2.xml")==1.5f)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"getCityName: \t";
    if(getCityName("clima.xml")=="Tegucigalpa" && getCityName("clima2.xml")=="London")
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/7"<<endl;
}
