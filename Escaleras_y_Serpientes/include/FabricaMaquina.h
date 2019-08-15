/*
  Nombre: FabricaMaquina.h
  Autores: Luis Felipe Casta�o 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificaci�n: Diciembre 6 de 2014
  Versi�n : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include "FabricaJugadores.h"
#ifndef FABRICAMAQUINA_H
#define FABRICAMAQUINA_H

/*
   Clase: FabricaMaquina
   Responsabilidad:
    - Crear un jugador maquina cuando se requiera
   Colaboraci�n: JugadorMaquina.h
*/


class FabricaMaquina: public FabricaJugadores
{
    public:
        FabricaMaquina();
        virtual ~FabricaMaquina();
    protected:
    private:
};

#endif // FABRICAMAQUINA_H
