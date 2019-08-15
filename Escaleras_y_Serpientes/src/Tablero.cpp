/*
  Nombre: Tablero.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include "Tablero.h"

Tablero::Tablero()
{

    for(int i = 0;i < 100 ; i++)
    {
        tablero.push_back("  ");
    }
    crearSerpientes();
    crearEscaleras();
}

Tablero::~Tablero()
{
    //dtor
}

vector <Serpiente> Tablero::getSerpientes()
{
    return serpientes;
}

vector <Escalera> Tablero::getEscaleras()
{
    return escaleras;
}

vector <string> Tablero::getTablero()
{
    return tablero;
}

void Tablero::crearSerpientes()
{
    char nombre[] = "a0";
    nombre[0] = char(245);

    Serpiente serpiente1(99,79,nombre);
    serpientes.push_back(serpiente1);
    nombre[1] = '1';
    Serpiente serpiente2(88,66,nombre);
    serpientes.push_back(serpiente2);
    nombre[1] = '2';
    Serpiente serpiente3(74,5,nombre);
    serpientes.push_back(serpiente3);
    nombre[1] = '3';
    Serpiente serpiente4(62,34,nombre);
    serpientes.push_back(serpiente4);
    nombre[1] = '4';
    Serpiente serpiente5(67,49,nombre);
    serpientes.push_back(serpiente5);
    nombre[1] = '5';
    Serpiente serpiente6(39,3,nombre);
    serpientes.push_back(serpiente6);
    nombre[1] = '6';
    Serpiente serpiente7(31,11,nombre);
    serpientes.push_back(serpiente7);

    int cambio1 =0;
    int cambio2 = 0;
  for(int j = 0; j < serpientes.size(); j++)
    {
        Serpiente s1 = serpientes[j];
        cambio1 = s1.getPosicionCabeza();
        tablero[cambio1] = s1.getNombre();
        cambio2 = s1.getPosicionCola();
        tablero[cambio2]= s1.getNombre();

    }
}

void Tablero::crearEscaleras()
{

    char nombre[] = "a0";
    nombre[0] = char(35);
    //escaleras
    Escalera Escalera1(97,75,nombre);
    escaleras.push_back(Escalera1);
    nombre[1] = '1';
    Escalera Escalera2(93,86,nombre);
    escaleras.push_back(Escalera2);
    nombre[1] = '2';
    Escalera Escalera3(90,69,nombre);
    escaleras.push_back(Escalera3);
    nombre[1] = '3';
    Escalera Escalera4(82,78,nombre);
    escaleras.push_back(Escalera4);
    nombre[1] = '4';
    Escalera Escalera5(65,37,nombre);
    escaleras.push_back(Escalera5);
    nombre[1] = '5';
    Escalera Escalera6(60,42,nombre);
    escaleras.push_back(Escalera6);
    nombre[1] = '6';
    Escalera Escalera7(52,47,nombre);
    escaleras.push_back(Escalera7);
    nombre[1] = '7';
    Escalera Escalera8(32,7,nombre);
    escaleras.push_back(Escalera8);
    nombre[1] = '8';
    Escalera Escalera9(26,14,nombre);
    escaleras.push_back(Escalera9);
    nombre[1] = '9';
    Escalera Escalera10(23,16,nombre);
    escaleras.push_back(Escalera10);
    int cambio1 =0;
    int cambio2 = 0;
  for(int j = 0; j < escaleras.size(); j++)
    {
        Escalera s1 = escaleras[j];
        cambio1 = s1.getPosicionCima();
        tablero[cambio1] = s1.getNombre();
        cambio2 = s1.getPosicionBase();
        tablero[cambio2]= s1.getNombre();

    }

}
