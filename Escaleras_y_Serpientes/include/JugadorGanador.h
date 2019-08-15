/*
  Nombre: FabricaMaquina.h
  Autores: Luis Felipe Casta�o 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Diciembre 6 de 2014
  Fecha Modificaci�n: Diciembre 6 de 2014
  Versi�n : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/
#ifndef JUGADORGANADOR_H
#define JUGADORGANADOR_H
#include <string>
using std::string;

/*
   Clase: JugadorGanador
   Responsabilidad:
    - Manejar y retornar los datos (nombre y puntaje) de un jugador ganador
   Colaboraci�n: Juego.h
*/
class JugadorGanador
{
    public:
        JugadorGanador();
        void setNombre(string);
        void setPuntaje(string);
        string getNombre();
        string getPuntaje();
        virtual ~JugadorGanador();
    protected:
    private:
        string nombre;
        string puntaje;
};

#endif // JUGADORGANADOR_H
