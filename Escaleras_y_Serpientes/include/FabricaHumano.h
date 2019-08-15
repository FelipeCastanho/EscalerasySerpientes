/*
  Nombre: FabricaHumano.h
  Autores: Luis Felipe Casta�o 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificaci�n: Diciembre 6 de 2014
  Versi�n : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#include "FabricaJugadores.h"
#ifndef FABRICAHUMANO_H
#define FABRICAHUMANO_H

/*
   Clase: FabricaHumano
   Responsabilidad:
    - Crear un jugador humano cuando se requiera
   Colaboraci�n: JugadorHumano.h
*/


class FabricaHumano: public FabricaJugadores
{
    public:
        FabricaHumano();
        virtual ~FabricaHumano();
    protected:
    private:
};

#endif // FABRICAHUMANO_H
