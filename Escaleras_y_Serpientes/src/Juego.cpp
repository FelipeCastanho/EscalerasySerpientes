/*
  Nombre: Juego.cpp
  Autores: Luis Felipe Castaño 1455721 - Angelica Ocampo Escobar  1455975- Ivan Andres Reyes 1455722.(Grupo 1)
  Fecha Creacion: Noviembre 3 de 2014
  Fecha Modificación: Noviembre 5 de 2014
  Versión : 2.0
  Email: castano.luis@correounivalle.edu.co , ocampo.angelica@correounivalle.edu.co, ivan.andres95@hotmail.com
*/

#include "Juego.h"

Juego::Juego()
{
    datos.cargarDatos();
    system ("color 3f");
    gameOver = false;
    turno = 2;
    opcion = 0;
    salir = false;
    tengo = 0;
    tuve = 0;
}

Juego::~Juego()
{
    //dtor
}

//opcines del menu principal
void Juego::seleccionarOpcionMenu()
{
    system("cls");
    cout << "SERPIENTES Y ESCALERAS" <<endl<<endl;
    cout << "1. - Iniciar partida" <<endl;
    cout << "2. - Ver puntuaciones" <<endl;
    cout << "3. - Salir" <<endl;
     do{
        cout << "Introduzca Opcion: ";
        cin >> opcion;
    }while (!((opcion>=1) && (opcion <=3)));
}

void Juego::menu()
{
    vector <JugadorGanador> ganadores1;
    do
    {
        seleccionarOpcionMenu();
        //delete jugador1;
        jugador1=0;
        //delete jugador2;
        jugador2=0;
        gameOver = true;
        switch (opcion)
        {
        case 1:
            jugar();
            system("pause");
            break;
        case 2:
            cout << "estamos viendo los puntos"<<endl;
            ganadores1 = datos.getGanadores();
            for(int i =0; i < ganadores1.size();i++)
            {
                cout <<endl<< "Puesto #"<<i+1<<endl;
                cout <<"Nombre: "<< ganadores1[i].getNombre()<<endl;
                cout <<"Puntaje: "<< ganadores1[i].getPuntaje()<<endl<<endl;

            }
            system("pause");
            break;
        default:
            break;
        }

    }while(opcion != 3);

}

//si se selecciona Jugar en el menu principal se llama a este metodo
void Juego::jugar()
{
    gameOver=false;
    ingresarDatos();//se ingresan los datos de los jugadores
    string desicion = "";//esta variable es para la opcion de salir del juego al menu principal
    bool lanzar = false;// esta variable es para controlar el dado cuando el jugador es maquina o es jugador
    do
    {

        imprimirDatos();//estos son los datos que aparecen en la parte de arriba del tablero
        dibujarTablero();//este metodo dibuja todo el tablero

                if(turno%2==0 && jugador1->getTipoJugador()=='J')lanzar=true;//estas condiciones activan
                if(turno%2==1 && jugador2->getTipoJugador()=='J')lanzar=true;//la pregunta del dado si el jugador es humano

        if(lanzar)//si el jugador es humano lanzar es true
        {
            do
            {
                cout <<"si desea salir del juego digite la palabra"<<char(34) <<"salir"<<char(34) <<endl<< endl;
                if(turno%2==0)cout <<jugador1->getNombre()<<" ";
                else cout <<jugador2->getNombre()<<" ";
                cout << "desea lanzar el dado? SI/NO"<<endl;
                cin >> desicion;
                if (desicion=="salir")gameOver=true;

            }while(!((desicion == "SI") || (desicion == "si")) && (gameOver==false));

        lanzar = false;
        }

        if (gameOver==true)break;//si se digito salir gameover es true y se vuelve al menu principal

        int resultadoDado = dado();// se llama al metodo del dado y se asigna a una variable
//        cout<<"este dado esta modificado ingrese el numero deseado: ";
//        int resultadoDado = 0;
//        cin >> resultadoDado;

        if(turno%2==0)cout <<jugador1->getNombre()<<": ";
        else cout <<jugador2->getNombre()<<": ";
        cout <<"el dado arrojo: " << resultadoDado;
        Sleep(1500);

          if(turno%2==0)
            {
            moverFicha(resultadoDado,1);// este metodo permite que la ficha se mueva posicion a posicion
            validar(1,resultadoDado);// este metodo valida las reglas del juego con respecto a la ficha del jugador 1
            }
        else if (turno%2==1)
            {
            moverFicha(resultadoDado,2);// este metodo permite que la ficha se mueva posicion a posicion
            validar(2,resultadoDado);// este metodo valida las reglas del juego con respecto a la ficha del jugador 2
            }
        turno+=1;
    }while(!gameOver);
}

// Este metodo pide a los usuarios los datos necesarios para jugar
void Juego::ingresarDatos()
{

    system("cls");
    string ficha = "";
    string nombre = "";
    int opcion2 = 0;
     do
    {
        system("cls");
        cout <<"1- Jugador vs Jugador"<<endl;
        cout <<"2- Jugador vs Maquina"<<endl;
        cout <<"3- Maquina vs Jugador"<<endl;
        cout <<"4- Maquina vs Maquina"<<endl;
        cout <<"Introduzca la opcion: ";
        cin >> opcion2;

    }while(opcion2==0 || opcion2 > 4);
    string ficha1 = "";
     switch(opcion2)
    {
    case 1: //Jugador vs Jugador
        fabriquita = new FabricaHumano();

        do
        {
            cout << "Ingrese la ficha del jugador 1(dos caracteres)" <<endl;
            cin >>ficha;
        }while(ficha.size()!=2);

        cout << "Digite nombre del jugador 1: "<<endl;
        cin >> nombre;
        jugador1 = fabriquita->crear(ficha,nombre,'J');
        ficha="";
        nombre="";
        ficha1 = jugador1->getFicha();
        do
        {
            cout << "Ingrese la ficha del jugador 2(dos caracteres)" <<endl;
            cin >>ficha;
        }while(ficha.size()!=2 || ficha==ficha1);

        cout << "Digite nombre del jugador 2: "<<endl;
        cin >> nombre;
        jugador2 = fabriquita->crear(ficha,nombre,'J');
        delete fabriquita;
        fabriquita = 0;
        break;
    case 2: // Jugador vs Maquina
        fabriquita = new FabricaHumano();
        ficha1 = "M1";
        do
        {
            cout << "Ingrese la ficha del jugador 1(dos caracteres)" <<endl;
            cin >>ficha;
        }while(ficha.size()!=2 || ficha==ficha1);

        cout << "Digite nombre del jugador 1: "<<endl;
        cin >> nombre;
        jugador1 = fabriquita->crear(ficha,nombre,'J');
        delete fabriquita;
        fabriquita = 0;
        fabriquita = new FabricaMaquina();
        jugador2 = fabriquita->crear("M1","JugadorMaquina",'M');
        delete fabriquita;
        fabriquita = 0;
        break;
    case 3: // Maquina vs Jugador
        fabriquita = new FabricaMaquina();
        ficha1 = "M1";
        do
        {
            cout << "Ingrese la ficha del jugador 2(dos caracteres)" <<endl;
            cin >>ficha;
        }while(ficha.size()!=2 || ficha==ficha1);

        cout << "Digite nombre del jugador 2: "<<endl;
        cin >> nombre;
        jugador2 = fabriquita->crear(ficha,nombre,'J');
        delete fabriquita;
        fabriquita = 0;
        fabriquita = new FabricaHumano();
        jugador1 = fabriquita->crear("M1","JugadorMaquina",'M');
        delete fabriquita;
        fabriquita = 0;
        break;
    case 4://Maquina vs Maquina
        fabriquita = new FabricaMaquina();
        jugador1 = fabriquita->crear("M1","JugadorMaquina",'M');
        jugador2 = fabriquita->crear("M2","JugadorMaquina2",'M');
        delete fabriquita;
        fabriquita = 0;
        break;
    default:
        break;
    }
    system("cls");
}

//Este metodo imprime la ficha y el puntaje en tiempo real en el juego
void Juego::imprimirDatos()
{
    system("cls");
    jugador1->calcularPuntaje();
    jugador2->calcularPuntaje();
    cout << "Ficha1:  " <<jugador1->getFicha();
    cout <<"                                "<<"Ficha2:  "<<jugador2->getFicha()<<endl;
    cout << "Puntaje: " <<jugador1->getPuntaje();
    cout <<"                                 "<<"Puntaje: "<<jugador2->getPuntaje()<<endl<<endl;
}

//Este metodo imprime el tablero y sus fichas, escaleras y serpientes
//aunque en general este metodo imprime la plantilla del tablero y llama a imprimirObjetos() para las
//fichas, escaleras y serpientes
void Juego::dibujarTablero()
{
    // El tablero se manejo como un vector para facilitar la validacion de las reglas por esto
    // al momento de imprimir el tablero debemos usar varios for para lograr el movimiento en s de las
    // fichas
    int a = 0;
    for(int i = 0 ; i < 100 ; i+=10)
    {
        if(a==0)
        {
            cout << char(201); //esquina izquierda arriba
            cout << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(203) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(203);
            cout  << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(203) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(203);
            cout  << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(203) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(203);
            cout  << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(203) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(203);
            cout  << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(203) << char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205);

            cout<<char(187)<<endl;//187 esquina derecha arriba
        }
        cout << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "
             << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<<endl;

        if (a%2==0)
        {
            for(int j = i ; j <= (i+9) ; j++)
            {
                cout << char(186)<<"  ";
                imprimirObjetos(j);
                cout <<"  ";
            }
            cout << char(186)<<endl;
            cout << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "
                 << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<<endl;


               cout << char(204);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205);
       cout << char(185)<<endl;

        }
        else
        {
            for(int k = i+9; k >= i ; k--)
            {
                cout << char(186)<<"  ";
                imprimirObjetos(k);
                cout <<"  ";
            }
            cout << char(186)<<endl;
            cout << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "
                 << char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<< char(186)<<"      "<<endl;


              if(a!=9){  cout << char(204);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(206);
       cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205);
       cout << char(185)<<endl;}
        }



        a++;
        if(a==10)
        {
           cout << char(200);//esquina izquierda abajo
            cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(202)<<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(202);
            cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(202)<<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(202);
            cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(202)<<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(202);
            cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(202)<<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<<char(202);
            cout <<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(202)<<char(205)<< char(205)<< char(205)<< char(205)<< char(205)<< char(205);
            cout <<char(188);// 188 esquina derecha abajo
        }

    }
    cout << endl;
}


// Este metodo se llama en imprimir tablero y es el encargado de imprimir las fichas escaleras o serpientes
// del tablero
void Juego::imprimirObjetos(int indice)
{
    vector <string> vectorCasillas = tablero1.getTablero();
    bool imprimio =  false;
    if (indice == jugador1->getPosicion())
    {
        cout << jugador1->getFicha();
        imprimio = true;
    }
    if (indice == jugador2->getPosicion() && !imprimio)
    {
        cout << jugador2->getFicha();
        imprimio = true;
    }
    if (!imprimio)cout << vectorCasillas[indice];
}

//Este metodo es el encargardo de retornar un numero del 1 al 6 es decir el dado
//ademas se ha impuesto una condicion para evitar que los numero se repitan por esto se guarda el numero pasado
//y se compara con el actual y si son iguales se repite el random claro esta que esto se hace una sola vez, es decir
// aun es posible que el dado arroje numeros repetidos pero esto sucedera con menos frecuencia
int Juego::dado()
{
	srand(time(0));
		tengo =1 + (rand()%6);
		if(tuve == tengo)
		{
			tengo = 1 + (rand()%6);
		}
		tuve = tengo;
	return tengo;
}

//Este metodo mueve la ficha posicion a posicion recibiendo la cantidad arrojada por el dado
//y el jugador que va a mover
void Juego::moverFicha(int movimiento,int jugador)
{
    bool retroceder = false;//Esta varible se activa si la cantidad retornada por el dado es mas
                            //de la necesaria para ganar
    int cambio =0;// esta varible se usa para guardar la posicion anterior del jugador
    switch(jugador)
    {

    case 1:
        cambio = jugador1->getPosicion();
        jugador1->setPosicionAnterior(cambio);// la posicion anterior del jugador se guarda en caso de ser
                                              // necesaria en las validaciones de las reglas
        for(int i = 0; i < movimiento;i++)
        {
            if (jugador1->getPosicion() == 0)retroceder = true;
            if(!retroceder) jugador1->mover();
            else jugador1->retroceder();
            imprimirDatos();
            dibujarTablero();
            Sleep(800);
        }
         break;
    case 2:
        // se repite el proceso pero este es en caso que el jugador a mover sea el 2
        cambio = jugador2->getPosicion();
        jugador2->setPosicionAnterior(cambio);
         for(int i = 0; i < movimiento;i++)
        {
            if (jugador2->getPosicion() == 0)retroceder = true;
            if(!retroceder) jugador2->mover();
            else jugador2->retroceder();
            imprimirDatos();
            dibujarTablero();
            Sleep(800);
        }
         break;
    default:
        break;
    }
}

//Este metodo valida las reglas del juego
void Juego::validar(int jugador,int resultadoDado)
{
    vector <Serpiente> validarS = tablero1.getSerpientes();
    vector <Escalera> validarE = tablero1.getEscaleras();
    bool valido = false;
    //se valida las posiciones de las serpientes con los jugadores

    for(int i = 0; i < validarS.size() && !valido ; i++)// se valida si el jugador cayo en una serpiente
    {
        if (jugador == 1)//para jugador uno
        {
            if (jugador1->getPosicion() == validarS[i].getPosicionCola())
            {
                jugador1->setSerpientes();
                int cambio = validarS[i].getPosicionCabeza();
                jugador1->setPosicion(cambio);
                cout<<jugador1->getNombre() <<" ha caido en una serpiente!!!!!!!!!!! :("<<endl;
            }
        }
        else// para jugador 2
        {
                if (jugador2->getPosicion() == validarS[i].getPosicionCola())
                {
                     jugador2->setSerpientes();
                     int cambio = validarS[i].getPosicionCabeza();
                     jugador2->setPosicion(cambio);
                     cout<<jugador2->getNombre()<<" ha caido en una serpiente!!!!!!!!!!! :("<<endl;
                }
        }
    }
    valido = false;
    //se valida las posiciones de las escaleras con los jugadores
    for(int i = 0; i < validarE.size() && !valido ; i++)
    {
        if (jugador == 1)//para jugador uno
        {
            if (jugador1->getPosicion() == validarE[i].getPosicionBase())
            {
                jugador1->setEscaleras();
                int cambio = validarE[i].getPosicionCima();
                jugador1->setPosicion(cambio);
                cout<<jugador1->getNombre() <<" ha alcanzado en una escalera!!!!!!!!!!! :)"<<endl;
            }

        }
        else//para jugardor 2
        {
                if (jugador2->getPosicion() == validarE[i].getPosicionBase())
                {
                    jugador2->setEscaleras();
                     int cambio = validarE[i].getPosicionCima();
                     jugador2->setPosicion(cambio);
                     cout<<jugador2->getNombre() <<" ha alcanzado en una escalera!!!!!!!!!!! :)"<<endl;
                }
        }
    }
    valido = false;

//se valida si un jugador asesino a otro
    if(jugador1->getPosicion()==jugador2->getPosicion())
    {
        int cambio = 0;
        if (jugador == 1)
        {
            cambio = jugador1->getPosicionAnterior();
            cout<<jugador1->getNombre() << " ha asesinado al jugador 2"<<endl;
            jugador2->setPosicion(cambio);
            jugador1->setAsesinatos();
        }
        else
        {
            cambio = jugador2->getPosicionAnterior();
            cout<<jugador2->getNombre() << " ha asesinado al jugador 1"<<endl;
            jugador1->setPosicion(cambio);
            jugador2->setAsesinatos();
        }
    }
    // se valida si el jugador uno llego a la casilla cero
    if (jugador1->getPosicion()==0)
    {
        cout<<jugador1->getNombre() << " ha ganado!!!!!!!!!!! :)"<<endl;
        jugador1->setGano(true); // se cambia la variable gano del jugador a true
        jugador1->calcularPuntaje();// se actualiza el puntaje
        string nombreG = jugador1 -> getNombre();// se crea una variable nombreganador
        stringstream ss;
        ss << jugador1->getPuntaje();
        string puntajeG = ss.str();// se crea un string puntaje apartir del int puntaje del jugador ganador
        JugadorGanador ganador1; // se crea un objeto jugadorganador que se ingresara en el vector de jugadores
        ganador1.setNombre(nombreG);//ganadores de la clase ganador
        ganador1.setPuntaje(puntajeG);
        datos.guardarGanadores(ganador1);// se guarda el nuevo ganador en la lista
        gameOver = true;
    }
    //se valida si el jugador 2 llego a la casilla cero
    // se repite el proceso de arriba pero en caso de jugador 2
    if (jugador2->getPosicion()==0)
    {
        cout<<jugador2->getNombre() << " ha ganado!!!!!!!!!!! :)"<<endl;
        jugador2->setGano(true);
        jugador2->calcularPuntaje();
        string nombreG = jugador2 -> getNombre();
        stringstream ss;
        ss << jugador2->getPuntaje();
        string puntajeG = ss.str();
        JugadorGanador ganador1;
        ganador1.setNombre(nombreG);
        ganador1.setPuntaje(puntajeG);
        datos.guardarGanadores(ganador1);
        gameOver = true;

    }
    Sleep(1000);
}

