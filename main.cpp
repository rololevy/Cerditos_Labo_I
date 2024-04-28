#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "funciones.h"


using namespace std;


int main(){

// Aquí deberíamos hacer los llamados a las funciones

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
    switch (opc) {
    case 1:

            ejecutarJuego();



    break;

    case 2:
        cout<<"EL MAYOR PUNTAJE OBTENIDO CORRESPONDE A: ";
        break;

    case 3:
        cout<<"DESARROLADORES: " << endl;
        cout<<"----------------------------------" << endl;
        cout<<"ALUMNO: " << endl;
        cout<<"::::::::::::::::::::::::::::::::::" << endl;
        cout<<"ALUMNO: " << endl;
        cout<<"::::::::::::::::::::::::::::::::::" << endl;
        cout<<"ALUMNO: " << endl;
        cout<<"::::::::::::::::::::::::::::::::::" << endl;
        cout<<"ALUMNO: " << endl;
        cout<<"::::::::::::::::::::::::::::::::::" << endl;
        cout<<"ALUMNO: " << endl;
    break;

    default:
        cout<<"LA OPCION INGRESADA ES INCORRECTA. REINTENTE.";
    }


    return 0;
}

