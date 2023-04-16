#include "funciones.h"

/*______________________________ FUNCIONES DE LECTURA____________________________________*/

/* Esta función ubica el cursor al final y retorna un int de dicha posicion */
unsigned long long cursor(){
    unsigned long long size;
    ifstream archivo("C:/Users/danielatg/OneDrive/Escritorio/PARCIAL_INFOII/Pensum.txt.txt", ios::ate);
    if (archivo.is_open()) {
        size = archivo.tellg();
        archivo.close();
        return size;
    }
    else {
         archivo.close();
         std::cout << "Error al abrir el archivo." << endl;
         return 0;
    }
}

/* Esta función lee todo el texto y almacena todo en un array */
char* copiartxt(unsigned long long end1) {
    ifstream archivo("C:/Users/danielatg/OneDrive/Escritorio/PARCIAL_INFOII/Pensum.txt.txt");
    char* txt = new char[end1 + 1];
    char A;
    unsigned long long i = 0;

    while (i < end1) {
        archivo.get(A);
        if (A == '*') {
            break;
        }
        if (A != '\r') {
            txt[i] = A;
            i++;
        }
    }
    txt[i] = '\0';
    archivo.close();
    return txt;
}

/* Esta función toma el array y lo almacena en un matriz todo estará todo el pensum */
void crearMatriz(char* txt2[53][5], char* txt) {
    char A[100];
    int i = 0, j = 0, d = 0, z = 0;

    while (txt[d] != '\0') {
        if (txt[d] == '\n') {
            A[z] = '\0';
            txt2[i][j] = new char[z + 1];
            std::copy(A, A + z + 1, txt2[i][j]);
            i++;
            j = 0;
            z = 0;
        } else if (txt[d] == ';') {
            A[z] = '\0';
            txt2[i][j] = new char[z + 1];
            std::copy(A, A + z + 1, txt2[i][j]);
            j++;
            z = 0;
        } else {
            A[z] = txt[d];
            z++;
        }
        d++;
    }
}
