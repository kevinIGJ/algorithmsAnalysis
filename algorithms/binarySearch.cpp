#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int binarySearch(int *arr, int l, int r, int x) {  //recibe | el puntero al arreglo, limite izquierdo, limite derecho, valor a buscar
	if (r >= l) { //verifica que existan elementos entre los cuales buscar aun 
		int mid = l + (r - l) / 2; //posicion media
		if (*(arr+mid) == x) //si el elemento esta en el medio, se retorna la posicion
			return mid; 
		if (*(arr+mid) > x) //si el valor buscado es menor que el medio, se busca en la mitad izquierda
			return binarySearch(arr, l, mid - 1, x); 
		return binarySearch(arr, mid + 1, r, x); //si el valor buscado es mayor que el medio, se busca en la mitad derecha
	} 
	return -1; //si no se encontro el elemento y ya no quedan elementos donde buscar 
} 
int main() { 
    int *a,n,x;
    cout<<"Dame el tamaño del array"<<endl;
    cin>>n;
    cout<<endl<<endl;
    a=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        cout<<"Dame el valor "<< i+1<< endl;
        cin>> *(a+i);
    }
    cout<<endl<<endl<<"Dame el numero a buscar en el arreglo"<<endl;
    cin>>x;	
    cout<<endl<<endl;
	int result = binarySearch(a, 0, n - 1, x); 
	if(result == -1) 
        cout << "El elemento no esta en el arreglo";
    else
        cout << "El elemento esta en el indice  " << result<<"  (posicion  "<<result+1<<")"; 
	return 0; 
} 
 