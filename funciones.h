#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string>

// Aquí tendremos las declaraciones/encabezados de la funciones

int ejecutarJuego();
int determinarComienzo(std::string j1, std::string j2);
int determinarPuntajes(int mat_dados[2][3], int cant_dados, int posicion_jugador);
int PrimerLanzDado();
int dadoMasAlto(int jugador1_d1, int jugador1_d2, int jugador2_d1, int jugador2_d2);

#endif  // FUNCIONES_H_INCLUDED


