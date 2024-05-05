#include "funciones.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Aqui haremos las definiciones/implementaciones de las funciones


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
    int puntos_ronda[2]={0};


    for (int j=1; j<=5; j++) //BUCLE DE 5 RONDAS POR JUGADOR MIENSTRAS NO SE CUMPLA LA CONDICION DEL WHILE
    {
        for (int i = 0; i <=1; i++)
        {
            continuar='s';
            while (continuar != 'n' && continuar != 'N')
            {

                cout<<"GRAN CERDO"<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<vec_Nombres[0] << " TRUFAS ACUMULADAS " << vec_puntos[0] << "                     " ;
                cout<<vec_Nombres[1] << " TRUFAS ACUMULADAS "<< vec_puntos[1]<<endl;
                cout<<endl;
                cout<<"TURNO DE: "<<vec_Nombres[i]<<endl;
                cout<<"+--------------------+"<<endl;
                cout<<"RONDA NUMERO " <<j<<endl;
                cout<<"TRUFAS DE LA RONDA: "<<endl;
                cout<<"LANZAMIENTO: "<<endl;
                cout<<"+--------------------+"<<endl;
                cout<<"LANZAMIENTO #"<<endl;
                cout<<endl;
                for (int m = 0; m < cantDados; m++)
                {
                    mat_dados[i][m]=PrimerLanzDado();
                    cout<<mat_dados[i][m]<<"  ";
                }


                switch (determinarPuntajes(mat_dados, cantDados, i)) //determinar puntaje nos devuelve la combinacion generada por los dados. envia la matriz de dados, la cantidad de dados y la (i) posiion del jugador
                {
                case 1:

                    if (cantDados==2 || cantDados == 3)
                    {
                        vec_puntos[i]+=mat_dados[i][0]+mat_dados[i][1];
                    }
                    else
                    {

                        vec_puntos[i]+=mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2];
                    }


                    cout<<"Las caras son distintas entre si y ninguna es ase";


                    break;

                case 2:
                   if (cantDados==2 || cantDados == 3)
                    {
                        vec_puntos[i]+= (mat_dados[i][0]+mat_dados[i][1])*2;
                    }
                    else
                    {

                        vec_puntos[i]+=mat_dados[i][0]+mat_dados[i][1]+mat_dados[i][2];
                    }
                    cout<<"Las caras son iguales entre si y no son ases";
                    break;
                case -1:
                    cout<<"Las caras son distintas entre si y hay 1 ase";
                    break;
                case -2:
                    cout<<"Las 2 caras son iguales y son ases";
                    break;
                case -3:

                    cout<<"Las 3 caras son iguales y son ases";
                    break;

                }
                cout<<endl;
                cout<<endl;
                cout<<"DESEA CONTINUAR (s/n): ";
                cin>>continuar;



                cout<<endl;




                system("pause");
                system("cls");
            }
        }

    }


}



//FUNCION PARA LANZAR DADO

int PrimerLanzDado ()
{
    return rand() % 6 + 1;

}

//FUNCION PARA DETERMINAR QUIEN COMIENZA LA TIRADA

int dadoMasAlto (int jugador1_d1, int jugador1_d2, int jugador2_d1, int jugador2_d2)
{

    if (jugador1_d1>jugador1_d2 && jugador1_d1 > jugador2_d1 && jugador1_d1 > jugador2_d2)
    {
        return 1;
    }
    else if (jugador1_d2 > jugador2_d1 && jugador1_d2 > jugador2_d2)
    {
        return 1;
    }
    else if (jugador2_d1>jugador1_d1 && jugador2_d1 > jugador1_d2 && jugador2_d1 > jugador2_d2)
    {
        return 2;
    }
    else if (jugador2_d2>jugador1_d1 && jugador2_d2 > jugador1_d2)
    {
        return 2;
    }
    else
        return 0;






}
//FUNCION PARA DETERMINAR QUIEN COMIENZA
int determinarComienzo (string j1, string j2)
{

    int jugador1_d1 = PrimerLanzDado();
    int jugador1_d2 = PrimerLanzDado();
    int jugador2_d1 = PrimerLanzDado();
    int jugador2_d2 = PrimerLanzDado();

    int sumaJ1 = jugador1_d1 + jugador1_d2;
    int sumaJ2 = jugador2_d1 + jugador2_d2;

    cout<<"PRIMER DADO LANZADO POR " << j1<< ": ";
    cout<< jugador1_d1 << endl;
    cout<<"SEGUNDO DADO LANZADO POR " << j1<< ": ";
    cout<< jugador1_d2 << endl;
    cout<<"SUMA TOTAL DE LOS DADOS: " << jugador1_d1+jugador1_d2 << endl;
    cout<<"--------------------------------------------" << endl;
    cout<<"--------------------------------------------" << endl;
    cout<<"PRIMER DADO LANZADO POR " << j2<< ": ";
    cout<< jugador2_d1  <<endl;
    cout<<"SEGUNDO DADO LANZADO POR " << j2<< ": ";
    cout<< jugador2_d2 << endl;
    cout<<"SUMA TOTAL DE LOS DADOS: " << jugador2_d1+jugador2_d2 << endl;

    system ("pause>>NULL");
    cout<<"------------------------------------------------" << endl;

    if (sumaJ1 > sumaJ2)
    {
        cout<<"COMIENZA EL JUGADOR: ";
        return 1;
    }
    else if (sumaJ2 > sumaJ1)
    {
        cout<<"COMIENZA EL JUGADOR: ";

        return 2;
    }
    else if (dadoMasAlto(jugador1_d1, jugador1_d2,jugador2_d1,jugador2_d2) == 1)
    {
        cout<<"COMIENZA EL JUGADOR: ";

        return 1;
    }
    else if (dadoMasAlto(jugador1_d1, jugador1_d2,jugador2_d1,jugador2_d2) == 2)
    {
        cout<<"COMIENZA EL JUGADOR: ";

        return 2;
    }
    else
    {
        cout<<"HUBO EMPATE, POR FAVOR LANZAR  NUEVO: " << endl;
        system("pause");
        system("cls");
        return determinarComienzo( j1, j2);
    }


}

int determinarPuntajes(int mat_dados[2][3], int cant_dados, int posicion_jugador) // FUNCION SUMA PUNTAJES recibe la matriz y la cantidad de dados
{

    if (cant_dados==2)
    {
        if (mat_dados [posicion_jugador][0] != mat_dados[posicion_jugador][1])
        {
            if (mat_dados [posicion_jugador][0] != 1 && mat_dados [posicion_jugador][1] != 1)
            {

                return 1; // 1 SE CUMPLIO QUE LAS 2 CARAS SON DISTINTAS Y NO HAY ASES
            }
            else
            {
                return -1; // -1 PERDIO ESTA RONDA
            }

        }
        else
        {
            if (mat_dados [posicion_jugador][0] != 1 && mat_dados [posicion_jugador][1] != 1)
            {

                return 2; //  2 SE CUMPLE QUE LAS CARAS SON IGUALES Y NO HAY ASES
            }
            else
            {
                return -2; // -2 SIGNIFICA QUE PERDIO TODO
            }

        }
    }
    else
    {
        if (mat_dados [posicion_jugador][0] != mat_dados[posicion_jugador][1] && mat_dados[posicion_jugador][1] != mat_dados[posicion_jugador][2] && mat_dados[posicion_jugador][0] != mat_dados[posicion_jugador][2])
        {
            if (mat_dados [posicion_jugador][0] != 1 && mat_dados [posicion_jugador][1] != 1 && mat_dados[posicion_jugador][2] !=1)
            {

                return 1; // 1 SE CUMPLIO QUE LAS 3 CARAS SON DISTINTAS Y NO HAY ASES
            }
            else
            {
                return -1;// -1 PERDIO ESTA RONDA
            }

        }
        else if (mat_dados [posicion_jugador][0] == mat_dados[posicion_jugador][1] && mat_dados[posicion_jugador][1] == mat_dados[posicion_jugador][2] && mat_dados[posicion_jugador][0] == mat_dados[posicion_jugador][2])
        {
            if (mat_dados [posicion_jugador][0] != 1 && mat_dados [posicion_jugador][1] != 1 && mat_dados[posicion_jugador][2] !=1)
            {
                return 2; //LAS 3 CARAS SON IGUALES Y NO HAY NINGUN ASES
            }
            else if (mat_dados [posicion_jugador][0] == 1 && mat_dados [posicion_jugador][1] == 1 && mat_dados[posicion_jugador][2] ==1)
            {
                return -3; // si las 3 caras son iguales y las 3 son ases,  pierde todo y se lo pasa al otro jugador
            }
        }

    }


}



/*cout<<"GRAN CERDO"<< endl;
cout<<"-------------------------------------"<< endl;
cout<<"HITO                 PEPPA                GEORGE"<< endl;//NOMBRE DE LOS JUGADORES
cout<<"--------------------------------------"<< endl;
cout<<"MAS TRUFAS EN TOTAL           "<< endl;
cout<<"CADA 50 TRUFAS"<< endl;
cout<<"OINK"<< endl;
cout<<"CERDO CODICIOSO"<< endl;
cout<<"---------------------------------------------"<< endl;
cout<<"TOTAL " << endl; //TOTAL PUNTAJES
///cout<<"GANADOR"<</*NOMBRE DEL JUGADOR*/ ///<<cout<<"CON " /*PUNTOS TOTAL*/ cout<<"PUNTOS DE VICTORIA" endl;
/*cout<<"INGRESE Oink para continuar..."<< endl;*/

