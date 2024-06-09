#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdlib>
#include <time.h>
#include <conio.h>


//FUNCION PARA LANZAR DADO
int dadosJugNro1()
{
    return 1;
}

int PrimerLanzDado()
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
void dibujarDados(int num);
int determinarComienzo (string j1, string j2)
{
        cout<<"Presione una tecla para lanzar su primer dado, jugador "<< j1 << endl;
    _getch();
    int jugador1_d1 = dadosJugNro1();
    dibujarDados(jugador1_d1);
    //system("pause");

        cout<<"Presione una tecla para lanzar su segundo dado, jugador "<< j1 << endl;
    _getch();
    int jugador1_d2 = dadosJugNro1();
    dibujarDados(jugador1_d2);

    int sumaJ1 = jugador1_d1 + jugador1_d2;
    cout<<"La suma de sus dados lanzados son: "<< sumaJ1<<endl;
    system("pause");
    system("cls");
        cout<<"Presione una tecla para lanzar su primer dado, jugador: "<< j2<< endl;
    _getch();

    int jugador2_d1 = PrimerLanzDado();

    dibujarDados(jugador2_d1);
    //system("pause");

        cout<<"Presione una tecla para lanzar su segundo dado, jugador: "<< j2 << endl;
    _getch();
    int jugador2_d2 = PrimerLanzDado();
    dibujarDados(jugador2_d2);

    int sumaJ2 = jugador2_d1 + jugador2_d2;

    cout<<"La suma de sus dados lanzados son: "<< sumaJ2<<endl;
    system("pause");
    system("cls");



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


//DETERMINAR PUNTAJES // SUMA PUNTAJES

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
        if (mat_dados [posicion_jugador][0] != mat_dados[posicion_jugador][1] || mat_dados[posicion_jugador][1] != mat_dados[posicion_jugador][2] || mat_dados[posicion_jugador][0] != mat_dados[posicion_jugador][2])
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


void dibujarDados (int num)
{

    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string BLACK_BACKGROUND = "\033[40m";
    switch (num)
    {
    case 1:
        cout << BLACK_BACKGROUND << RED;
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   x   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << RESET << endl;

        break;
    case 2:

        cout<<"+-------+"<< endl;
        cout<<"| x     |"<< endl;
        cout<<"|       |"<< endl;
        cout<<"|     x |"<< endl;
        cout<<"+-------+"<< endl;



        break;
    case 3:

        cout<<"+-------+"<< endl;
        cout<<"| x     |"<< endl;
        cout<<"|   x   |"<< endl;
        cout<<"|     x |"<< endl;
        cout<<"+-------+"<< endl;


        break;
    case 4:

        cout<<"+-------+"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"|       |"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"+-------+"<< endl;


        break;
    case 5:
        cout<<"+-------+"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"|   x   |"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"+-------+"<< endl;


        break;
    case 6:

        cout<<"+-------+"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"| x   x |"<< endl;
        cout<<"+-------+"<<endl;

        break;


    }


}


void puntajesFinales (string vec_Nombres[], int vec_puntos[], int contOinks[], int vec_Lanz[], string *nombreMax, int *puntajeMax)
{

    int cant_Puntos_Finales[2]= {0};
    int gano_mas_trufas[2]= {0};
    string oink;
    int cada_50[2]= {0};
    int cant_lanzamiento[2]={0};



    if (vec_puntos[0] > vec_puntos[1])
    {
        cant_Puntos_Finales[0]+=5;
        gano_mas_trufas[0]=5;
    }
    else if(vec_puntos[1] > vec_puntos[0])
    {
        cant_Puntos_Finales[1]+=5;
        gano_mas_trufas[1]=5;
    }
    else
    {

        cant_Puntos_Finales[0]+=5;
        cant_Puntos_Finales[1]+=5;
        gano_mas_trufas[0]=5;
        gano_mas_trufas[1]=5;

    }

    cada_50[0]=vec_puntos[0]/50;
    cada_50[1]=vec_puntos[1]/50;
    cant_Puntos_Finales[0] += contOinks[0] * 2;
    cant_Puntos_Finales[1] += contOinks[1] * 2;
    cant_Puntos_Finales[0]+=cada_50[0];
    cant_Puntos_Finales[1]+=cada_50[1];

    if (vec_Lanz[0]>vec_Lanz[1]){
        cant_lanzamiento[0]=3;
        cant_Puntos_Finales[0]+=3;
    }
    else if (vec_Lanz[1]>vec_Lanz[0]){
        cant_lanzamiento[1]=3;
        cant_Puntos_Finales[1]+=3;
    }
    else {
        cant_lanzamiento[0]=3;
        cant_Puntos_Finales[0]+=3;
        cant_lanzamiento[1]=3;
        cant_Puntos_Finales[1]+=3;

    }


    cout<<"GRAN CERDO"<< endl;
    cout<<"-----------------------------------------------------------------------------------------"<< endl;
    cout<<"HITO                      "<< vec_Nombres[0] << "                       " << vec_Nombres[1] << endl;//NOMBRE DE LOS JUGADORES
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<< endl;
    cout<<"MAS TRUFAS EN TOTAL       "<< gano_mas_trufas[0] <<" PDV ("<<vec_puntos[0] << " TRUFAS)" <<"           "<<gano_mas_trufas[1]<<" PDV ("<<vec_puntos[1] << " TRUFAS)" <<endl;
    cout<<"CADA 50 TRUFAS            "<< cada_50[0] << " PDV (" <<vec_puntos[0]-(vec_puntos[0]%50) << " TRUFAS)" <<"          "<< cada_50[1] << " PDV (" <<vec_puntos[1]-(vec_puntos[1]%50) << " TRUFAS)" <<endl;
    cout<<"OINK                      "<< contOinks[0] * 2 << " PDV ("<<contOinks[0]<< " OINKS)" << "            "<< contOinks[1]*2 << " PDV ("<<contOinks[1] << " OINKS)" << endl;
    cout<<"CERDO CODICIOSO           "<< cant_lanzamiento[0] << " PDV ("<<vec_Lanz[0] << " LANZAMIENTOS)" << "     "<< cant_lanzamiento[1] << " PDV ("<<vec_Lanz[1] << " LANZAMIENTOS)" << endl;
    cout<<"-----------------------------------------------------------------------------------------"<< endl;
    cout<<"TOTAL                     " << cant_Puntos_Finales[0] <<" PDV                      "<< cant_Puntos_Finales[1] << " PDV "<<  endl; //TOTAL PUNTAJES
    cout<<endl;
    if (cant_Puntos_Finales[0]>cant_Puntos_Finales[1]){
        cout<<"GANADOR: "<<vec_Nombres[0] << " CON " << cant_Puntos_Finales[0] << " PUNTOS DE VICTORIA " << endl;
        *nombreMax=vec_Nombres[0];
        *puntajeMax=cant_Puntos_Finales[0];

    }
    else {
        cout<<"GANADOR: "<<vec_Nombres[1] << " CON " << cant_Puntos_Finales[1] << " PUNTOS DE VICTORIA " << endl;
        *nombreMax=vec_Nombres[1];
        *puntajeMax=cant_Puntos_Finales[1];
    }
    cout<<endl;
    cout<<"INGRESE Oink para continuar..."<< endl;
    cin>>oink;

}

#endif // FUNCIONES_H_INCLUDED
