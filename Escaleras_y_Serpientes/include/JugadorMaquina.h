/*
  Nombre: JugadorMaquina.h
  Autores: Luis Felipe Casta�o 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificaci�n: Diciembre 6 de 2014
  Versi�n : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#ifndef JUGADORMAQUINA_H
#define JUGADORMAQUINA_H
#include "Jugador.h"
/*
   Clase: JugadorMaquina
   Responsabilidad:
    - Tiene todas las responsibilidades que la clase Jugador pero siendo una Maquina
   Colaboraci�n: Juego.h
*/

class JugadorMaquina: public Jugador
{
    public:
        JugadorMaquina(string,string,char);
        virtual ~JugadorMaquina();
        char getTipoJugador();
    protected:
    private:
};

#endif // JUGADORMAQUINA_H
