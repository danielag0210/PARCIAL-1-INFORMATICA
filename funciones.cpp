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

/*______________________________ MENU INICIAL Y BORRADOR DE CONSOLA____________________________________*/

void limpiar(int seconds) {
    std::system("cls||clear"); // limpiar la consola en Windows o Unix
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void menuHorario() {
    int m, n;
    bool a = true;

    while (a == true) {
        cout << "*----------------* Bienvenido *-------------------*" << endl;
        cout << "1. Crear Horario - 2.Gestionar Horario  - 3. Salir: " << endl;
        cout << "Escribe un numero del menu: ";
        cin >> m;
        limpiar(1.3);

        if (m == 1) {
            bool b = true;
            while (b == true) {
                cout << "*----------------* Crear Horario *-----------------*" << endl;
                cout << "¿Cuántas materias vas a ver este semestre?" << endl;
                cout << "Respuesta: ";
                cin >> n;
            }
        }
        else {
            cout << "Por favor ingresa un número válido." << endl;
        }
    }
}

char** Gestionar(int n) {
    char dias[7][11] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes","Sábado", "Domingo"};
    int h1, h2;
    cout << "¿A qué hora es tu primer clase? (por favor escríbelo en formato 24 horas): "<< endl;
    cin  >> h1;
    cout << "¿Hasta qué hora quieres estudiar como máximo? (por favor escríbelo en formato 24 horas): "<< endl;
    cin >> h2;

    int filas = h2 - h1;
    if (filas < 0) {
        filas += 24;
    }
    filas += 1;

    int columnas = 8;
    char **matriz = new char*[filas];

    /* Reservamos memoria para cada fila de la matriz */
    for(int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
    }
    /*  Escribos los dias de la semana en tabla */
    for(int j = 0; j < columnas; j++) {
        int i = 0;
        matriz[i][j] = dias[j-1][0];
    }

   for(int i = 0; i < filas; i++) {
        int j = 0;
        matriz[i][j] = (h1 + i) + '0';
    }

    return matriz;
}



