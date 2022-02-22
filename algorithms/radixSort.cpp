#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
#define base 10
using namespace std; 
int mayor(int *&arr, int n){ 
	int mx = *arr; 
	for (int i = 1; i < n; i++) 
		if (*(arr+i) > mx) 
			mx = *(arr+i); 
	return mx; 
} 
void printArray(int *&arr, int n) { 
    cout << endl<< endl;
	for (int i = 0; i < n; i++) 
		cout << *(arr+i) << "   "; 
	cout << endl; 
} 
void countingSort(int *&arr, int n, int b) { 
	int i, *count=(int*)malloc(sizeof(int)*base), *output=(int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) 
		(*(count  + (*(arr+i)/b)%base)) ++;   //cuenta la cantidad de elementos que tienen la posicion como digito en la posicion quese esta evaluando
    //cout<<"Cantidad de elementos";
    //printArray(count,10);  

	for (i = 1; i < base; i++) 
		*(count+i) += *(count+i - 1);     //asigna las posiciones en las que se comensara a acomodar
    //cout<<"posiciones";
    //printArray(count,10);    

	for (i = n - 1; i >= 0; i--) { 
		(*(output+   *(count+ ( *(arr+i) /b)%base ) - 1)) = *(arr+i);      //posiciona en el array de salida 
		(*(count+ (*(arr+i)/b)%base ))--;     //reduce la posicion en la que se acomodara
	} 
	for (i = 0; i < n; i++) 
		*(arr+i) = *(output+i);      //pasa el array ordenado al array original
} 
void radixSort(int *&arr, int n) { 
	int m = mayor(arr, n); 
	for (int b = 1; m/b > 0; b *= base) 
		countingSort(arr, n, b); 
} 
int main() { 
    int *a,n;
    cout<<"Dame el tamaño del array"<<endl;
    cin>>n;
    cout<<endl<<endl;
    a=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        cout<<"Dame el valor "<< i+1<< endl;
        cin>> *(a+i);
    }
	radixSort(a, n); 
	printArray(a, n); 
	return 0; 
} 