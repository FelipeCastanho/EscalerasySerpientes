/*
  Nombre: Escalera.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include <string>
#ifndef ESCALERA_H
#define ESCALERA_H

using std::string;
/*
   Clase: Escalera
   Responsabilidad:
    - Simular una escalera del juego con sus datos necesario tales como posicion de la base y posicion de la cima
   Colaboración: Tablero.h
*/


class Escalera
{
    public:
        Escalera(int,int,string);
        int getPosicionBase();
        int getPosicionCima();
        string getNombre();
        virtual ~Escalera();
    protected:
    private:
        string nombre;
        int posicionBase;
        int posicionCima;
};

#endif // ESCALERA_H
