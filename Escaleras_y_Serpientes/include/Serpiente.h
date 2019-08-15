/*
  Nombre: Serpiente.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include <string>
#ifndef SERPIENTE_H
#define SERPIENTE_H
using std::string;

/*
   Clase: Serpiente
   Responsabilidad:
    - Simular una serpiente del juego con sus datos necesario tales como posicion de la cola y posicion de la cabeza
   Colaboración: Tablero.h
*/


class Serpiente
{
    public:
        Serpiente(int,int,string);
        int getPosicionCola();
        int getPosicionCabeza();
        string getNombre();
        virtual ~Serpiente();
    protected:
    private:
        string nombre;
        int posicionCola;
        int posicionCabeza;
};

#endif // SERPIENTE_H
