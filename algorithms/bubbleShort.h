#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int * bubbleShort( int *a, int n)
{
    for (int j = 0; j < n; j++)
    { //  complejidad O(n^2)
        for (int i = 0, p; i < n - 1; i++)
        {
            if (*(a + i) > *(a + i + 1))
            {
                p = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = p;
            }
        }
    }
    return a;
}