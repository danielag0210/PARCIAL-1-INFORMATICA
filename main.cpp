#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    unsigned long long end = cursor();
    char* txt = leer(end);
    int j = contarSaltosDeLinea(txt) + 1; /* Se agrega 1 para incluir la última línea sin salto de línea */
    char*** matriz = crearMatriz(j, 5, 100, txt);
   /* imprimirMatriz(matriz, j, 5);  */
    void menuHorario(/* matriz */);

                          /* el primer 0 es cada linea del texto, el segundo es cada grupito separado con; / el 3 cero es cada letra, las posciones de
                          las letras van desde 0 a  x letras, antes de cada ; hay una posicion vacio, luedo esta el /0 y luego esta la letra siguiente*/
    char elemento = matriz[0][0][1];
    cout << elemento << endl;
    preguntar(matriz, j);

}











