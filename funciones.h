#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

unsigned long long cursor();
char* leer(unsigned long long end1);
char*** crearMatriz(int n, int m, int d, char* txt);
void limpiar(int seconds);
void menuHorario();
char ***Gestionar(int filas,int h1);
int preguntar(char ***horario, int n);
int contarSaltosDeLinea(char* arreglo);

#endif // FUNCIONES_H
