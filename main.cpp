#include <iostream>
#include "funciones.h"
using namespace std;

int main()
{ unsigned long long end = cursor();
    char* txt = copiartxt(end);
    char* txt2[53][5] = {};
    crearMatriz(txt2, txt);

    for (int x = 0; x < 53; x++) {
        for (int y = 0; y < 5; y++) {
            std::cout << txt2[x][y] << " ";
        }
        std::cout << std::endl;
    }

    for (int x = 0; x < 53; x++) {
        for (int y = 0; y < 5; y++) {
            delete[] txt2[x][y];
        }
    }

    return 0;
}











