#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int *  dynamicArray( int n)
{
    int *a;
    a = (int *)malloc(sizeof(int) * n);
    cout << "Datos sin ordenar" << endl;
    for (int i = 0; i < n; i++)
    {
        *(a + i) = rand() % n + 1;
        cout << *(a + i) << endl;
    }
   return a;
}