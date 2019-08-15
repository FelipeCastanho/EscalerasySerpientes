/*
  Nombre: Jugador.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include <iostream>
#include "Serpiente.h"
#include "Escalera.h"
#include <vector>
#include <string>
#ifndef TABLERO_H
#define TABLERO_H
using namespace std;
using std::vector;
using std::string;

/*
   Clase: Tablero
   Responsabilidad:
    - Guardar los datos de las casillas correspondientes al juego teniendo en cuenta serpientes y escaleras.
   Colaboración: Juego.h
*/


class Tablero
{
    public:
        Tablero();
        void crearSerpientes();
        void crearEscaleras();
        vector <Serpiente> getSerpientes();
        vector <Escalera> getEscaleras();
        vector <string> getTablero();
        virtual ~Tablero();
    protected:
    private:
        vector <Serpiente> serpientes;
        vector <Escalera> escaleras;
        vector < string > tablero;
};

#endif // TABLERO_H
