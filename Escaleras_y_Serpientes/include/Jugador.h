/*
  Nombre: Jugador.h
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include <vector>
#include <string>
#ifndef JUGADOR_H
#define JUGADOR_H
using std::vector;
using std::string;

/*
   Clase: Jugador
   Responsabilidad:
    - Simular un jugador del juego con sus datos necesario tales como posicion, ficha, nombre entre otros.
    - almacenar los datos relevantes durante el juego para calcular su puntaje final.
   Colaboración: JugadorHumano.h y JugadorMaquina.h
*/



class Jugador
{
    public:
        Jugador(string,string,char);
        string getFicha();
        string getNombre();
        int getPosicion();
        int getPuntaje();
        int getEscaleras();
        int getSerpientes();
        int getAsesinatos();
        bool getGano();
        void setFicha(string);
        void setNombre(string);
        void setPosicion(int);
        void setPuntaje(int);
        void setEscaleras1(int);
        void setSerpientes1(int);
        void setAsesinatos1(int);
        void setEscaleras();
        void setSerpientes();
        void setAsesinatos();
        void setGano(bool);
        void setPosicionAnterior(int);
        int getPosicionAnterior();
        virtual char getTipoJugador()=0;
        void calcularPuntaje();
        void mover();
        void retroceder();
        virtual ~Jugador();
    protected:
        string ficha;
        string nombre;
        char tipoJugador;
        int posicionAnterior;
        int posicion;
        int puntaje;
        int cantidadEscaleras;
        int cantidadSerpientes;
        int cantidadAsesinatos;
        bool gano;
};

#endif // JUGADOR_H
