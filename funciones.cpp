#include "funciones.h"

/*______________________________ FUNCIONES DE LECTURA____________________________________*/

/* Esta función ubica el cursor al final y retorna un int de dicha posicion */
unsigned long long cursor(){
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
                preguntar(horario,n);

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

void preguntar(char **horario, int n)
{

}
