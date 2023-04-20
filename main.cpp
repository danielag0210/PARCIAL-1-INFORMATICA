#include <iostream>
#include <fstream>


/* Estas 3 librerias son solo para actualizar la consola */
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

/*______________________________ FUNCIONES DE LECTURA____________________________________*/

/* Esta función ubica el cursor al final y retorna un int de dicha posicion */
unsigned long long cursor() {
    unsigned long long size;
    ifstream archivo("Pensum.txt", ios::ate);
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
char* leer(unsigned long long end1) {
    ifstream archivo("Pensum.txt");
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

/*  Esta fun cion contara cuantos renglones tiene el texto */
int contarSaltosDeLinea(char* arreglo) {
    int j = 0;
    for (int i = 0; arreglo[i] != '\0'; i++) {
        if (arreglo[i] == '\n') {
           j++;
        }
    }
    return j;
} 
/* Esta función toma el array y lo almacena en un matriz todo estará todo el pensum */
char*** crearMatriz(int n, int m, int d, char* txt) {
    char*** matriz = new char**[n];

    for (int i = 0; i < n; i++) {
        matriz[i] = new char*[m];
        for (int j = 0; j < m; j++) {
            matriz[i][j] = new char[d];
        }
    }

    int i = 0, j = 0, k = 0, z = 0;

    while (txt[z] != '\0') {
        if (txt[z] == '\n') {
            matriz[i][j][k] = '\0';
            i++;
            j = 0;
            k = 0;
        } else if (txt[z] == ';') {
            matriz[i][j][k] = '\0';
            j++;
            k = 0;
        } else {
            matriz[i][j][k] = txt[z];
            k++;
        }
        z++;
    }

    matriz[i][j][k] = '\0';

    return matriz;
}

/* Esta funcion me imprimer cualquier matriz */
void imprimirMatriz(char*** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

char** Gestionar(int filas, int h1) {
    char dias[7] = {'L', 'M','W', 'J', 'V','S', 'D'};
    int columnas = 8;
    char **matriz;
    /* Reservamos memoria para cada fila de la matriz */
    matriz = new char* [filas];
    for(int i = 0; i < filas; i++) {
        matriz[i] = new char [columnas];
    }
    // Reserva memoria para cada columna de la matriz

    /*  Escribo los dias de la semana en tabla */
    for(int j = 0; j < columnas; j++) {
        int i = 0;
        matriz[i][j+1] = dias[j];
    }
    //anexo las horas en las que se trabajara
    matriz[0][0]=' ';
   for(int i = 0; i < filas; i++) {
        int j = 0;
        if((h1+i)<10){
        matriz[i+1][j] = (h1 + i)+48;
        }
        else {
            matriz[i+1][j] = ((h1+i)/10)+48;
        }
    }
   for(int i=1;i<filas;i++){
           int j=1;
           while (j<columnas){
               matriz[i][j]= ' ';
               j++;
           }
           cout <<endl;
   }
   for(int i=0;i<filas;i++){
           int j=0;
           while (j<columnas){
               cout << matriz[i][j]<<"---";
               j++;
           }
           cout <<endl;
   }
    return matriz;
}

void limpiar(int seconds) {
    std::system("cls||clear"); // limpiar la consola en Windows o Unix
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

/* Esta funcion imprime el menu */
void menuHorario(/* char matriz*** */) 
{   int m, n;
    char** horario= 0x0;
    do{
        cout << "*----------------* Bienvenido *-------------------*" << endl<< "- 1. Crear Horario"<<endl<<"- 2. Gestionar Horario "<<endl <<"- 3. Visualizar horario "<< endl<<"- 4. Salir: " << endl<< "Escribe un numero del menu: ";
        cin>> m;
        limpiar(1.3);
        switch (m) {
        case 1:
            do{
                cout << "*----------------* Crear Horario *-----------------*" << endl<< "¿Cuántas materias vas a ver este semestre?" << endl<< "Respuesta: ";
                cin >> n;
                limpiar(1.3);
                int h1, h2;
                cout << "¿A qué hora iniciaras a estudiar? (por favor escríbelo en formato 24 horas): "<< endl;
                cin  >> h1;
                cout << "¿Hasta qué hora quieres estudiar como máximo? (por favor escríbelo en formato 24 horas): "<< endl;
                cin >> h2;
                int filas = h2 - h1;
                if (filas < 0) {
                    filas += 24;
                }
                filas += 1;
                horario = Gestionar(filas,h1); 
                /* preguntar(n,horario,matriz); que esta funcion retorne si la materia es correcta o no
                si, si la pasamos a horario y que el usario ponga una fila y columna y se modifique en el horario */

                for (int i; i<= filas;i++ ){
                    delete[] horario[i];
                }
                delete horario;
                m =0;
            }while (m==1);
            break;
        case 2:

            break;
        default:
            break;
        }
    }while ((m =! 4));
}

int preguntar(char*** matriz, int n) {
    char codigo[9];
    int j = 0;
    bool encontrado = false;
   /* while (n<=c){  c es el numero de materias a comparar */
    while (!encontrado) {
        cout << "Escribe el codigo de una materia: ";
        cin >> codigo;

        int longitud = 0;
        for (int i=0; i < 9; i++) {
            if (codigo[i] == '\0') {
                longitud = i;
                break;
            }
        }
        if (longitud != 6) {
            cout << "El codigo de la materia no es valido, ingresalo nuevamente." << endl;
            continue;
        }

        /*bucar el código de materia en la matriz*/
        for (int i = 0; i<n; i++) {
            bool encontrado_fila = true;
            for (int k = 0; k <= 6; k++) {
                if (matriz[0][i][k] != codigo[k]) {
                    encontrado_fila = false;
                    break;}
            }
            if (encontrado_fila) {
                encontrado =true;
                j = i;
                break;
            }
            }

        if (!encontrado){
            cout << "La materia no esta en el sistema." << endl;
        }
    }

    return j; /*retorna la fila, ya sabriamos el resto de información*/
}

int main() {
   /*ofstream archivo("Pensum.txt"); */ /* para crear el archivo la primera vez */
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
