/*
  Nombre: Jugador.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include "Jugador.h"

Jugador::Jugador(string f, string n, char t)
{
     ficha = f;
     nombre = n;
     tipoJugador = t;
     posicion = 99;
     puntaje = 0;
     cantidadEscaleras = 0;
     cantidadSerpientes = 0;
     cantidadAsesinatos = 0;
     gano = false;
}

Jugador::~Jugador()
{
    //dtor
}

//getters

string Jugador::getFicha()
{
    return ficha;
}

string Jugador::getNombre()
{
    return nombre;
}

int Jugador::getPosicion()
{
    return posicion;
}

int Jugador::getPuntaje()
{
    return puntaje;
}

int Jugador::getEscaleras()
{
    return cantidadEscaleras;
}

int Jugador::getSerpientes()
{
    return cantidadSerpientes;
}

int Jugador::getAsesinatos()
{
    return cantidadAsesinatos;
}

bool Jugador::getGano()
{
    return gano;
}

void Jugador::setPosicion(int cambio)
{
    posicion = cambio;
}

void Jugador::setPuntaje(int cambio)
{
    puntaje = cambio;
}

void Jugador::setEscaleras()
{
    cantidadEscaleras+=1;
}

void Jugador::setSerpientes()
{
    cantidadSerpientes +=1;
}

void Jugador::setAsesinatos()
{
    cantidadAsesinatos +=1;
}

void Jugador::setGano(bool cambio)
{
    gano = cambio;
}

void Jugador::setNombre(string cambio)
{
    nombre = cambio;
}

void Jugador::setFicha(string cambio)
{
    ficha = cambio;
}

void Jugador::calcularPuntaje()
{
    puntaje = (cantidadEscaleras*50)+(cantidadAsesinatos*60)+(cantidadSerpientes*-50)+(gano*1000);
}

void Jugador::mover()
{
    posicion--;
}
void Jugador::retroceder()
{
    posicion++;
}

void Jugador::setPosicionAnterior(int cambio)
{
    posicionAnterior = cambio;
}

int Jugador::getPosicionAnterior()
{
    return posicionAnterior;
}

char Jugador::getTipoJugador()
{
    return tipoJugador;
}

void Jugador::setEscaleras1(int cambio)
{
    cantidadEscaleras = cambio;
}

void Jugador::setSerpientes1(int cambio)
{
    cantidadSerpientes = cambio;
}

void Jugador::setAsesinatos1(int cambio)
{
    cantidadAsesinatos = cambio;
}

