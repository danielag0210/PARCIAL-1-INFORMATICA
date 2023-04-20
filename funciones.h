#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>

/* Estas 3 librerias son solo para actualizar la consola */
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

unsigned long long cursor();
char* copiartxt(unsigned long long end1);
char*** crearMatriz(int n, int m, int d, char* txt);
void limpiar(int seconds);
void menuHorario();
char** Gestionar(int n);
int contarSaltosDeLinea(char* arreglo);
void imprimirMatriz(char*** matriz, int filas, int columnas);
int preguntar(char*** matriz, int n);

#endif // FUNCIONES_H
