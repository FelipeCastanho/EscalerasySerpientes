/*
  Nombre: FabricaJugadores.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: diciembre 6 de 2014
  Fecha Modificación:  diciembre 6 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include "FabricaJugadores.h"

FabricaJugadores::FabricaJugadores()
{
    //ctor
}

FabricaJugadores::FabricaJugadores(Tipo t)
{
    tipo = t;
}

FabricaJugadores::~FabricaJugadores()
{
    //dtor
}

Jugador * FabricaJugadores::crear(string f,string n,char t)
{
    Jugador *j;
    switch(tipo)
    {
    case Maquina:
        j = new JugadorMaquina (f,n,t);
        break;
    case Humano:
        j = new JugadorHumano (f,n,t);
        break;
    }

        return j;

}
