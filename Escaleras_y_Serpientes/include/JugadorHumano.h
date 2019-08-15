/*
  Nombre: JugadorHumano.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificación: Diciembre 6 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H
#include "Jugador.h"
/*
   Clase: JugadorHumano
   Responsabilidad:
    - Tiene todas las responsibilidades que la clase Jugador pero siendo un humano
   Colaboración: Juego.h
*/

class JugadorHumano: public Jugador
{
    public:
        JugadorHumano(string,string,char);
        virtual ~JugadorHumano();
        char getTipoJugador();
    protected:
    private:
};

#endif // JUGADORHUMANO_H
