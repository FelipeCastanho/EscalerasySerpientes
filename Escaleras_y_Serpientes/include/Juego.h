/*
  Nombre: Juego.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include <string>
#include <vector>
#include<sstream>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "JugadorGanador.h"
#include "Ganadores.h"
#include "FabricaJugadores.h"
#include "FabricaHumano.h"
#include "FabricaMaquina.h"
#include "Tablero.h"
#ifndef JUEGO_H
#define JUEGO_H

/*
   Clase: Juego
   Responsabilidad:
    -  Asignar nombres y fichas a los jugadores.
    - Controlar el desarrollo del juego(asignar turno, mover ficha).
    - Imprimir el tablero con todas sus caracteristicas.
    - validar las reglas del juego.
    - Guardar los datos de los jugadores que han ganado.
   Colaboración: Juego.h
*/

using namespace std;
using std::string;
using std::vector;
using std::sort;
using std::ofstream;
using std::endl;

class Juego
{
    public:
        Juego();
        void menu();
        void seleccionarOpcionMenu();
        void jugar();
        void ingresarDatos();
        void imprimirDatos();
        void dibujarTablero();
        void imprimirObjetos(int);
        int dado();
        void moverFicha(int,int);
        void validar(int,int);
        bool validarCasillaFinal(int,int);
        void mostrarPuntajes();
        virtual ~Juego();
    protected:
    private:
       Ganadores datos;
       Tablero tablero1;
       FabricaJugadores *fabriquita;
       Jugador *jugador1;
       Jugador *jugador2;
       bool gameOver;
       bool salir;
       int turno;
       int opcion;
       int tengo;
       int tuve;
};

#endif // JUEGO_H
