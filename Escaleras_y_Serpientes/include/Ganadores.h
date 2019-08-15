/*
  Nombre: Ganadores.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificación: Diciembre 6 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#ifndef GANADORES_H
#define GANADORES_H


/*
   Clase: Ganadores
   Responsabilidad:
    - Cargar, Guardar y retornar los datos de los jugadores ganadores
   Colaboración: Juego.h
*/

#include "JugadorGanador.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using std::string;
using std::ifstream;
using std::vector;
using std::sort;
using std::ofstream;
using std::endl;

class Ganadores
{
    public:
        Ganadores();
        vector <JugadorGanador> getGanadores();
        bool cargarDatos();
        void guardarGanadores(JugadorGanador);
        virtual ~Ganadores();
    protected:
    private:
        vector <JugadorGanador> ganadores;

};

#endif // GANADORES_H
