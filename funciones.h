#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

unsigned long long cursor();
char* copiartxt(unsigned long long end1);
void crearMatriz(char* txt2[53][5], char* txt);
void limpiar(int seconds);
void menuHorario();
char** Gestionar(int n);
#endif // FUNCIONES_H
