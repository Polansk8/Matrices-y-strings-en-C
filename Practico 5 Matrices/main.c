#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define DIM 10
#define COL_STRINGS 20
#define FIL_STRINGS 30

#define ESC 27



void imprimircabecera(char cabecera[]);
void replicaChar (char c, int cant);
void consolaColor(int colorin);
int randLeng (int min, int max);
void loadIntM (int f, int c, int m[][c]);///1)
void loadIntMRand (int f, int c, int m[][c]);///2)
void printIntM (int f, int c, int m[][c], char titulo[]);///3)
int sumaMatriz (int f, int c, int m[][c]);///4)
float promMatriz (int f, int c, int m[][c]);///5)
int searchDateM (int f, int c, int m[][c], int date);///6)
int loadAString (int dim, char pdp [][dim], int v, char titulo []);///7)
void printString (int dim, char string[][dim], int v, char titulo[]);///8)





int main()
{
    srand(time(NULL));

    char opcion = 0;

    int numerics [DIM][DIM];
    int datos [DIM][DIM];
    char strings[FIL_STRINGS][COL_STRINGS];

    int valStrings = 0;

    int flag = 0;
    int nombres = 0;

    int date;

    hidecursor(0);


    do{
        consolaColor(14);
        system("cls");
        imprimircabecera("TP 4.1: Matrices EEAAA");
        replicaChar('*', 54);
        printf("\n>>>1) Cargar una matriz-------------------------------");
        printf("\n>>>2) Mostrar la matriz-------------------------------");
        printf("\n>>>3) Cargar una matriz con numeros aleatorios--------");
        printf("\n>>>4) Sumar los elementos de la matriz----------------");
        printf("\n>>>5) Promedia los elementos de la matriz-------------");
        printf("\n>>>6) Busca un numero en una matriz-------------------");
        printf("\n>>>7) Carga nombres en un array de strings------------");
        printf("\n>>>8) Muestra un array de strings---------------------");
        printf("\n");
        replicaChar('*',54);
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case'1':
                loadIntM(numerics, DIM, DIM);
                printIntM(numerics, DIM, DIM, "A cargado la matriz con exito");
            break;
        case '2':
            printIntM(numerics, DIM, DIM, "Matriz NUMERICS");
            break;
        case '3':
                if(flag)
                    {
                    printIntM(datos, DIM, DIM, "Ya cargo previamente la matriz");
                    }
                else
                    {
                    loadIntMRand(datos, DIM, DIM);
                    flag = 1;
                    printIntM(datos, DIM, DIM, "Se cargo la matriz con numeros aleatorios");
                    }
            break;
        case '4':
                if(flag)
                    {
                    printIntM(datos, DIM, DIM, "SUMA DE ELEMENTOS DE LA MATRIZ");
                    printf("\n\n----La suma de los elementos de la matriz es <%d>", sumaMatriz(datos, DIM, DIM));
                    }
                else
                    {
                    printf(">>ERROR<< La matriz no esta cargada. Por favor carguela con la opcion <3>----");
                    }
            break;
        case '5':
                if(flag)
                    {
                    printIntM(datos, DIM, DIM, "PROMEDIO DE UNA MATRIZ");
                    printf("\n\nEl promedio de la matriz es: %.2f", promMatriz(datos, DIM, DIM));
                    }
                else
                    {
                    printf(">>ERROR<< La matriz no esta cargada. Por favor carguela con la opcion <3>");
                    }
            break;
        case '6':
                if(flag)
                    {
                    printf("----Ingrese el numero que desea buscar en la matriz>>> ");
                    scanf("%d", &date);
                    system("cls");
                    if(searchDateM(datos, DIM, DIM, date))
                        {
                        printIntM(datos, DIM, DIM, "RESULTADO DE LA BUSQUEDA DEL NUMERO");
                        printf("\n---El numero <%d> SI se encuentra en la matriz", date);
                        }
                    else
                        {
                        printIntM(datos, DIM, DIM, "RESULTADO DE LA BUSQUEDA DEL NUMERO");
                        printf("\n---El numero <%d> NO se encuentra en la matriz---", date);
                        }
                    }
                else
                    {
                    printf(">>>ERROR<<< La matriz no esta cargada. Por favor carguela con la opcion <3>");
                    }
            break;
        case '7':
                valStrings = loadAString(COL_STRINGS, strings,valStrings, "Ingrese un nombre");
                nombres = 1;
                printString(COL_STRINGS, strings, valStrings, "Nombres");
            break;
        case '8':
                if (nombres)
                    {
                    printString(COL_STRINGS, strings, valStrings, "Nombres");
                    }
                else
                    {
                    printf(">>>ERROR<<< No hay ningun nombre cargado. Por favor carguelo con la opcion <7>");
                    }
            break;
        case 27:
                printf("AAAAAAAAAAAAAAAAAAAA");
            break;
        default:
            imprimircabecera(">>ERROR<< A ingresado una opcion no valida...");
        }
        printf("\n\n\n<ESC> para salir o cualquier tecla para volver al menu principal---");
        opcion = getch();
    }while(opcion != ESC);
    return 0;
}








void imprimircabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for (i=0;i<50;i++)
        {
        printf("%c", 205);
        }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186, cabecera,186);
    printf("%c", 200);

    for (i=0;i<50;i++)
        {
        printf( "%c", 205);
        }
    printf("%c",188);
}
void replicaChar (char c, int cant)
{
    printf("\n");
    for (int i=0;i<cant;i++)
        {
        printf("%c", c);
        }
    printf("\n");
}
void consolaColor(int colorin)
{
    int x = 0;
    int y = 0;

    while (x<200)
            {
            gotoxy(x, y);
            color(colorin);
            x++;
            }
        while (y < 200)
            {
            gotoxy(x, y);
            color(colorin);
            y++;
            }
}




/** \brief Devuelve un numero aleatorio entre cierto rango de numeros
 *
 * \param Un numero de valor minimo
 * \param Un numero de valor maximo
 * \return Numero aleatorio
 *
 */
int randLeng (int min, int max)
{
    return rand() % (max-min) + min;
}






///1)
/** \brief Carga una matriz por intervencion del usuario
 *
 * \param Una matriz tipo INT
 * \param Cantidad de filas
 * \param Cantidad de columnas
 * \param Un encabezado de la matriz
 * \return No return
 *
 */
void loadIntM (int f, int c, int m[][c])
{
    for (int i=0;i<f;i++)
        {
        for (int j=0;j<c;j++)
            {
            printf("---Ingrese un valor en la posicion [%d] [%d]: ", i+1, j+1);
            scanf("%d", &m[i][j]);
            system("cls");
            }
        }
}





///2)
/** \brief Muestra una matriz por pantalla
 *
 * \param Una matriz de tipo INT
 * \param Cantidad de filas
 * \param Cantidad de columnas
 * \param Un encabezado para la matriz
 * \return No return
 *
 */
void printIntM (int f, int c, int m[][c], char titulo[])
{
    printf("\n");
    imprimircabecera(titulo);
    printf("\n");
    for(int i=0;i<f;i++)
        {
        for(int j=0;j<c;j++)
            {
            printf(" %02d |", m[i][j]);
            }
        printf("\n");
        }
}






///3)
/** \brief Carga una matriz con numeros aleatorios
 *
 * \param Una matriz de tipo INT
 * \param Cantidad de filas
 * \param Cantidad de columnas
 * \return No return
 *
 */
void loadIntMRand (int f, int c, int m[][c])
{
    for(int i=0;i<f;i++)
        {
        for(int j=0;j <c;j++)
            {
            m[i][j] = rand()%50;
            }
        }
}





///4)
/** \brief Suma los elementos de una matriz
 *
 * \param Una matriz tipo INT
 * \param Cantidad de filas
 * \param Cantidad de columnas
 * \return La suma
 *
 */
int sumaMatriz (int f, int c, int m[][c])
{
    int acum = 0;

    for(int i=0;i<f;i++)
        {
        for(int j=0;j<c;j++)
            {
            acum += m[i][j];
            }
        }
    return acum;
}



///5)
/** \brief Saca el promedio de una matriz
 *
 * \param Matriz tipo int
 * \param Cantidad de filas
 * \param Cantidad de columnas
 * \return El promedio de la matriz
 *
 */
float promMatriz (int f, int c, int m[][c])
{
    int acum = 0;
    int cant = f * c;

    float prom;

    for (int i=0;i<f;i++)
        {
        for (int j=0;j<c;j++)
            {
            acum += m[i][j];
            }
        }
    prom = (float) acum / cant;

    return prom;
}




///6)
/** \brief Busca un numero en una matriz
 *
 * \param Cantidad filas
 * \param Cantidad columnas
 * \param Matriz tipo INT
 * \return Flag
 *
 */
int searchDateM (int f, int c, int m[][c], int date)
{
    int flag = 0;
    int i = 0;
    int j = 0;

    while(i<f && !flag)
        {
        while (j<c && !flag)
            {
            if(m[i][j] == date)
                {
                flag = 1;
                }
            j++;
            }
        j = 0;
        i++;
        }
    return flag;
}



///7)
/** \brief Carga un array de strings
 *
 * \param Cantidad columnas
 * \param Array de strings
 * \param Una descripcion de lo que va a cargar
 * \return Validos de strings
 *
 */
int loadAString (int dim, char pdp [][dim], int v, char titulo [])
{
    char opcion = 0;
    int i=v;

    while (opcion != ESC)
        {
        printf("---%s>>> ", titulo);
        gets(pdp[i]);
        i++;
        printf("\n\n---Presione <ESC> para salir o cualquier tecla para continuar---");
        fflush(stdin);
        opcion = getch();
        system("cls");
        }

    return i;
}




///8)
/** \brief Muestra un array de strings
 *
 * \param Cantidad columnas
 * \param Un array de strings
 * \param Validos
 * \param Descripcion de lo que se muestra
 * \return No return
 *
 */
void printString (int dim, char string[][dim], int v, char titulo[])
{
    int i=0;
    printf("------%s-------", titulo);
    printf("\n");
    while (i<v)
        {
        printf("\n%d... %s", i+1, string[i]);
        i++;
        }
}
