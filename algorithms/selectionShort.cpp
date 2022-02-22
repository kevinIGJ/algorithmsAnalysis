#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std; 
void swap(int *&xp, int *&yp) { 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 
void selectionSort(int *&arr, int n) { 
	for (int j, min_idx,i = 0; i < n-1; i++) { 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
            if (*(arr+j) < *(arr+min_idx)) 
                min_idx = j; 
		swap(*(arr+min_idx), *(arr+i)); 
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
	selectionSort(a, n); 
	printArray(a, n); 
	return 0; 
} 