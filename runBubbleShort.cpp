#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <iomanip> 
#include "algorithms/bubbleShort.h"
#include "algorithms/bubbleShortEnhanced.h"
#include "algorithms/dynamicArray.h"
using namespace std;

int main()
{
    clock_t t1, t2; //variables de tiempo en ciclos de reloj
    int *a, n;

    cout << "Dame el tamaño del array" << endl;
    cin >> n;
    cout << endl;
 
    a = dynamicArray(n); //Llama a la funcion que crea y llena el array de tamaño n 
    int *b = (int*)malloc(sizeof(int)*n); //crea un array del mismo tamaño que a
    memcpy(b, a, sizeof(int)*n); // copia el array sin ordenar "a" en el nuevo array "b" 

    t1 = clock();
    a = bubbleShort(a,n); //ejecuta el algoritmo bubble short
    t1 = clock() - t1;

    t2 = clock();
    b = bubbleShortEnhanced(b,n); //ejecuta el algoritmo bubble short enhanced
    t2 = clock() - t2;

    cout << endl << "Datos ordenados con bubble short"  << endl;
    for (int i = 0; i < n; i++)
        cout << *(a + i) << endl; //imprime el array "a"
    cout << endl << "Datos ordenados con bubble short enhanced"  << endl;
    for (int i = 0; i < n; i++)
        cout << *(b + i) << endl; //imprime el array "b"

    cout << fixed << endl << "Tiempo transcurrido para odenar con bubble short " << (float)t1 / CLOCKS_PER_SEC << " segundos" << endl;
    cout << fixed << endl << "Tiempo transcurrido para odenar con bubble short enhanced " << (float)t2 / CLOCKS_PER_SEC << " segundos" << endl;

    return 0;
}