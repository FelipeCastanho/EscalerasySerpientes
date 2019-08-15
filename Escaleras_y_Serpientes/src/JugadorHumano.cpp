/*
  Nombre: JugadorGanador.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include "JugadorHumano.h"

JugadorHumano::JugadorHumano(string f,string n,char t):Jugador(f,n,t)
{
}

JugadorHumano::~JugadorHumano()
{
    //dtor
}

char JugadorHumano::getTipoJugador()
{
    return 'J';
}
