#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std; 
void insertionSort(int *&arr, int n) { 
	for (int x, j, i = 1; i < n; i++) {     // x valor que se esta comparando
		x = *(arr+i);                       // j posicion anterior con la que se compara
		j = i - 1;                          // i la posicion a comprarar 
		while (j >= 0 && *(arr+j) > x) { 
			*(arr+j + 1) = *(arr+j); 
			j = j - 1; 
		} 
		*(arr+j + 1) = x; 
	} 
} 
void printArray(int *&arr, int n) { 
    cout << endl<< endl;
	for (int i = 0; i < n; i++) 
		cout << *(arr+i) << "   "; 
	cout << endl; 
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
	insertionSort(a, n); 
	printArray(a, n); 
	return 0; 
} 


