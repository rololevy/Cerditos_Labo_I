#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "funciones.h"


using namespace std;


int main()
{

// Aquí deberíamos hacer los llamados a las funciones

    srand(time(NULL));

    int opc=1;


    while(opc!=0)
    {

        system ("cls");

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

        cin>>opc;

        switch (opc)
        {
        case 1:

            ejecutarJuego();

            break;

        case 2:
            cout<<"EL MAYOR PUNTAJE OBTENIDO CORRESPONDE A: ";
            break;

        case 3:
            cout<<"DESARROLADORES: " << endl;
            cout<<"----------------------------------" << endl;
            cout<<"ALUMNO: BIANCHI NICOLAS" << endl;
            cout<<"::::::::::::::::::::::::::::::::::" << endl;
            cout<<"ALUMNO: BALDOCCHI LUIS" << endl;
            cout<<"::::::::::::::::::::::::::::::::::" << endl;
            cout<<"ALUMNO: CATTANEO CARLOS" << endl;
            cout<<"::::::::::::::::::::::::::::::::::" << endl;
            cout<<"ALUMNO: ORLANDO AGUILERA" << endl;
            cout<<"::::::::::::::::::::::::::::::::::" << endl;
            cout<<"ALUMNO: RIOS EVER" << endl;
            break;

        case 0:
            cout<<"Ingreso un 0 como opcion, estamos saliendo del programa...";
            break;

        default:
            cout<<"No ingreso una opcion valida."<<endl;
            break;

        }
        system("pause");

    }

    return 0;
}
