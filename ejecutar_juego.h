#ifndef EJECUTAR_JUEGO_H_INCLUDED
#define EJECUTAR_JUEGO_H_INCLUDED
#include "funciones.h"

///FUNCION PRINCIPAL DEL JUEGO



int ejecutarJuego ()
{

    string jugador1;
    string jugador2;



    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << "**                                                **" << endl;
    cout << "**            BIENVENIDOS A GRAN CERDO            **" << endl;
    cout << "**                                                **" << endl;
    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << endl;


    cout<<"POR FAVOR INGRESE EL NOMBRE DEL JUGADOR 1: ";
    cin>>jugador1;
    cout<<"POR FAVOR INGRESE EL NOMBRE DEL JUGADOR 2: ";
    cin>>jugador2;
    system ("cls");

    string vec_Nombres[2]; //vector para asignar los nombres de los jugadores
    int vec_puntos[2]= {0};



    if (determinarComienzo (jugador1, jugador2) == 1) //EL GANADOR COMIENZA A LANZAR LOS DADOS. JUGADOR 1 POSICION 0. JUGADOR 2 POSICION 1.
    {
        cout<< jugador1;
        vec_Nombres[0]=jugador1;  //SI COMIENZA EL JUGADOR 1 SE ASIGNA A LA POSICION 0 PARA QUE EMPIEZE A LANZAR LOS DADOS
        vec_Nombres[1]=jugador2;
    }

    else
    {
        cout<<jugador2;
        vec_Nombres[0]=jugador2; // SI COMIENZA EL JUGADOR 2 SE LE ASIGNA A LA POSICION 0 PARA QUE COMIENCE A LANZAR LOS DADOS
        vec_Nombres[1]=jugador1;

    }
    system("pause>>NULL");
    system("cls");

    int mat_dados[2][3]; //MATRIZ DE DADOS
    int cantDados=2; //CANTIDAD DE DADOS =2
    char continuar = 's';
    int puntos_ronda[2]= {0};
    int lanzamientos=0; //incrementa a medida que va lanzando
    int contOink[2]= {0};
    string oinkParaCont;



    for (int j=1; j<=4; j++) //BUCLE DE 5 RONDAS POR JUGADOR MIENSTRAS NO SE CUMPLA LA CONDICION DEL WHILE
    {
        puntos_ronda[0]=0; //reiniciar a 0 las rondas
        puntos_ronda[1]=0;


        for (int i = 0; i <=1; i++)
        {
            continuar='s';
            lanzamientos=1; //acumula lanzamientos
            while (continuar != 'n' && continuar != 'N')
            {

                cout<<"GRAN CERDO"<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<vec_Nombres[0] << " TRUFAS ACUMULADAS "<< vec_puntos[0] << "                     " ;
                cout<<vec_Nombres[1] << " TRUFAS ACUMULADAS "<< vec_puntos[1]<<endl;
                cout<<endl;
                cout<<"TURNO DE: "<<vec_Nombres[i]<<endl;
                cout<<"+--------------------+"<<endl;
                cout<<"RONDA NUMERO " <<j<<endl;
                cout<<"TRUFAS DE LA RONDA: "<< puntos_ronda[i]<<endl;
                cout<<"LANZAMIENTO: "<<lanzamientos<<endl;
                cout<<"+--------------------+"<<endl;
                cout<<"LANZAMIENTO #"<<endl;
                cout<<endl;
                for (int m = 0; m < cantDados; m++)

                {

                    mat_dados[i][m]=PrimerLanzDado();
                    dibujarDados(mat_dados[i][m]);




                }


                switch (determinarPuntajes(mat_dados, cantDados, i)) //determinar puntaje nos devuelve la combinacion generada por los dados. envia la matriz de dados, la cantidad de dados y la (i) posiion del jugador
                {
                case 1:

                    if (cantDados==2)
                    {
                        puntos_ronda[i]+=mat_dados[i][0]+mat_dados[i][1];
                        vec_puntos[i]+=mat_dados[i][0]+mat_dados[i][1];

                    }
                    else
                    {
                        puntos_ronda[i]+=mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2];
                        vec_puntos[i]+=mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2];

                    }


                    cout<<"Las caras son distintas entre si y ninguna es ase";


                    break;



                case 2:

                    if (cantDados==2)  //VIERNES. 2DO PUNTO CON 2 JUGADORES
                    {

                        puntos_ronda[i]+=(mat_dados[i][0]+mat_dados[i][1])*2;
                        vec_puntos[i]+=(mat_dados[i][0]+mat_dados[i][1])*2;



                    }
                    else
                    {
                        puntos_ronda[i]+=(mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2])*2;
                        vec_puntos[i]+=(mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2])*2;


                    }
                    contOink[i]++;

                    cout<<"Oink!! " << endl;
                    cout<<"FELICIDADES!!! DUPLICASTE TUS TRUFAS..." << endl;

                    cout<<"Las caras son iguales entre si y no son ases";
                    break;
                case -1:

                    vec_puntos[i]=vec_puntos[i]-puntos_ronda[i];




                    cout<<"PERDISTE LOS PUNTOS DE ESTA RONDA Y PERDISTE EL TURNO!!" << endl;
                    cout<<"Las caras son distintas entre si y hay 1 ase";

                    continuar='n';


                    break;
                case -2:


                    vec_puntos[i]=0;


                    cout<<"LAMENTO DECIRTE QUE PERDISTE TODOS TUS PUNTOS!!-----TE DESEO SUERTE EN LA SIGUIENTE RONDA" << endl;

                    continuar='n';


                    cout<<"Las 2 caras son iguales y son ases";
                    break;
                case -3: //Si se está lanzando con tres dados y tres de las caras son iguales entre sí y son ases: Aplica la misma quita de puntos que en el caso anterior pero dichos puntos se acumulan al otro cerdo en dicha ronda.


                    if (i == 0)
                    {

                        vec_puntos[1]+=vec_puntos[0]; //si esta jugando el jugador 1 pasa al jugador pos 2

                    }
                    else
                    {
                        vec_puntos[0]+=vec_puntos[1]; //jugando el jugador 2 pasapuntos al jugador 1
                    }

                    vec_puntos[i]=0;




                    cout<<"Las 3 caras son iguales y son ases";
                    break;

                }
                cout<<endl;
                if (continuar=='s')
                {
                    cout<<"DESEA CONTINUAR (s/n): ";
                    cin>>continuar;
                }

                cout<<endl;
                cout<<endl;




                cout<<endl;

                lanzamientos++;

                if (vec_puntos[0] > 50 && vec_puntos[1]> 50)
                {

                    cantDados=3;



                }

                system("pause");
                system("cls");
            }

        }

    }
    system("cls");

    puntajesFinales(vec_Nombres, vec_puntos);


}

#endif // EJECUTAR_JUEGO_H_INCLUDED
