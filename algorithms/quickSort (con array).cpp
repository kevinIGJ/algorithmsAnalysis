#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
void swap(int *&xp, int *&yp) { 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
}
int partition (int *&arr, int low, int high){ 
	int pivot = *(arr+high); 
	int i = (low - 1); 
	for (int j = low; j < high ; j++) { 
		if (*(arr+j) < pivot){ 
			i++; 
			swap(*(arr+i), *(arr+j)); 
		} 
	} 
	swap(*(arr+i + 1), *(arr+high)); 
	return (i + 1); 
} 
void quickSort(int *&arr, int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
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
	quickSort(a, 0, n - 1); 
	printArray(a, n); 
	return 0; 
} 
