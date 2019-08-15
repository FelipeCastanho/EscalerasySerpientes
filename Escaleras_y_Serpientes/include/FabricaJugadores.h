/*
  Nombre: FabricaJugadores.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificación: Diciembre 6 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#ifndef FABRICAJUGADORES_H
#define FABRICAJUGADORES_H
#include "Jugador.h"
#include "JugadorMaquina.h"
#include "JugadorHumano.h"

/*
   Clase: FabricaJugadores
   Responsabilidad:
    - Crear un jugador cuando se requiera
   Colaboración: FabricaHumano.h y FabricaJugadores.h
*/

class FabricaJugadores
{
     public:
        enum Tipo {Humano,Maquina};
        FabricaJugadores();
        FabricaJugadores(Tipo);
        Jugador *crear(string,string,char);
        virtual ~FabricaJugadores();
    protected:
    private:
        Tipo tipo;
};

#endif // FABRICAJUGADORES_H
