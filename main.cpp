#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cstring>



#include <iostream>


using namespace std;

#include "ejecutar_juego.h"

int main()
{

    string salida;
    string nombreMax;
    int puntajeMax;
    bool huboJuego= false;

    while (true)
    {
        system("cls");

        srand(time(NULL));


        cout<<"GRAN CERDO" << endl;
        cout<<"------------------"<<endl;
        cout<<endl;
        cout<< "1 - JUGAR" << endl;
        cout<< "2 - ESTADISTICAS" << endl;
        cout<< "3 - CERDITOS" << endl;
        cout<< "0 - SALIR" << endl;
        cout<<"------------------" << endl;

        cout<<"ANTES DE CONTINUAR POR FAVOR INGRESE UNA OPCION: " << endl;
        cout<<"OPCION: ";
        int opc;
        cin>>opc;
        system ("cls");

        const string GREEN = "\033[32m";
        const string PURPLE = "\033[35m";
        const string WHITE = "\033[37m";

        const string RESET = "\033[0m";
        const string BOLD_PURPLE = "\033[1;35m";


        switch (opc)
        {
        case 1:
            huboJuego = true;
            ejecutarJuego(&nombreMax, &puntajeMax);



            break;

        case 2:
            if(huboJuego){
            cout << BOLD_PURPLE;
            cout << "****************************************************" << endl;
            cout << "****************************************************" << endl;
            cout << "**                                                **" << endl;
            cout << "**            PUNTAJES FINALES                    **" << endl;
            cout << "**                                                **" << endl;
            cout << "****************************************************" << endl;
            cout << "****************************************************" << endl;
            cout << RESET << endl;

            cout<<"NOMBRE DEL JUGADOR GANADOR: ";
            cout<<nombreMax<<endl;
            cout<<"PUNTOS DE VICTORIA: ";
            cout<<puntajeMax<<endl;
            cout<<endl;
            cout<<WHITE;

            system("pause");
            }
            else {
                cout << "No hay partidas recientes para mostrar puntaje."<<endl;
                system("pause");
                }

            break;

        case 3:

            cout <<"DESARROLADORES: " << endl;
            cout << endl;
            cout << "ALUMNO: " << GREEN << "Ever Benjamin Rios" << WHITE << endl;
            cout << endl;
            cout << "ALUMNO: " << GREEN << "Carlos Alberto Cattaneo"  << WHITE << endl;
            cout << endl;
            cout << "ALUMNO: " << GREEN << "Nicolás Emilio Bianchi" << WHITE << endl;
            cout << endl;
            cout << "ALUMNO: " << GREEN << "Orlando Aguilera"  << WHITE << endl;
            cout << endl;
            cout << "ALUMNO: " << GREEN << "Luis Baldocchi" << WHITE << endl;
            cout <<endl;

            system("pause");
            break;




        case 0:

            cout<<" ¿DESEA SALIR DEL JUEGO?  (S/N) ";
            cin>>salida;
            if (salida == "s" || salida == "S")
            {
                return 0;
            }

            break;


        default:
            cout<<"LA OPCION INGRESADA ES INCORRECTA. REINTENTE.";
        }

    }

    return 0;
}

