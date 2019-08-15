/*
  Nombre: Ganadores.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: diciembre 6 de 2014
  Fecha Modificación:  diciembre 6 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include "Ganadores.h"

Ganadores::Ganadores()
{

}

Ganadores::~Ganadores()
{
    //dtor
}

vector <JugadorGanador> Ganadores::getGanadores()
{
    return ganadores;
}

bool Ganadores::cargarDatos()
{
    string nombreArchivo = "ganadores.txt";
    ifstream archivo(nombreArchivo.c_str()); //c_str hace que algo que esta en string se pasa a caracter4if(!archivo.is_open()) //is_open sirve para saber si realmente abrio el archivo
   if(!archivo.is_open()) //is_open sirve para saber si realmente abrio el archivo
    {
      return false;
    }
    string palabra;
    int contador = 1;
    JugadorGanador J1;
    while(archivo>>palabra)
    {

        if (contador%2 != 0)
        {
            J1.setNombre(palabra);
        }
        else
            {
                J1.setPuntaje(palabra);
                 ganadores.push_back(J1);
            }
        contador++;
    }
    archivo.close();
    return true;

}

void Ganadores::guardarGanadores(JugadorGanador J1)
{
    ganadores.push_back(J1);
    int longitud = ganadores.size();
    JugadorGanador aux;
    if(ganadores.size()>1)
    {

    for (int h = 0; h < longitud; h++)
    {
        for (int j = 0; j < longitud - 1 ; j++)
        {
            int puntaje1 = atoi(ganadores[j].getPuntaje().c_str());
            int puntaje2 = atoi(ganadores[j+1].getPuntaje().c_str());
            if ( puntaje1 < puntaje2 )
            {
                aux = ganadores[j];
                ganadores[j] = ganadores [j+1];
                ganadores[j+1] = aux;
            }
        }
    }}

    string nombreArchivo2 = "ganadores.txt";
    ofstream archivo2(nombreArchivo2.c_str());
    for (int i=0; i<ganadores.size(); i++)
    {
        archivo2 <<ganadores[i].getNombre()<< endl;
        archivo2 <<ganadores[i].getPuntaje()<< endl;
    }
    archivo2.close();
}
