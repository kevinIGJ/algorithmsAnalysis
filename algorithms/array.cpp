#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int main() { 
    int n, * arr, * arr2, res=0;
    cout<<"Dame la cantidad de datos, debe ser par"<<endl;
    cin>>n;
    if (n % 2==0 ){
        arr = (int *) malloc (sizeof(int)*n); 
        arr2 = (int *) malloc (sizeof(int)*(n/2));
        for(int i=0; i<n; i++){
            cout<<"Dame el valor en la posicion "<<i<<endl;
            cin>>*(arr+i);
        }
        cout<<endl<<endl<<"Arreglo 1"<<endl;
        for(int i=0; i<n; i++){
            cout<<*(arr+i)<<endl;
        }
        for(int i=0,j=0; i<n; i+=2){ //crea arreglo 2
            *(arr2+j)= (*(arr+i) + *(arr+i+1))/2;
            j++;
        }
        cout<<endl<<endl<<"Arreglo 2"<<endl;
        for(int i=0; i<(n/2); i++)
            cout<< *(arr2+i)<<endl;
        for(int i=0; i<(n/2); i++){ //suma el res
            res += *(arr2+i);
        }
        cout<<endl<<endl<<"El resultado es "<<endl<<res<<endl;
    }else
        cout<<"Usa una cantidad n par";
    
    return 0; 
} 