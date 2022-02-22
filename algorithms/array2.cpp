#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int main() { 
    int n;
    cout<<"Dame la cantidad de datos, debe ser par"<<endl;
    cin>>n;
    if (n % 2==0 ){  //numero de operaciones:  
        int * arr = (int *) malloc (sizeof(int)*n), * arr2 = (int *) malloc (sizeof(int)*(n/2)), res;
        for(int i=0, j=0; i<n; i++){
            cout<<"Dame el valor en la posicion "<<i<<endl;
            cin>>*(arr+i);
            if (i>=1 && i % 2 != 0){
                *(arr2+j)= (*(arr+i-1) + *(arr+i))/2;
                res += *(arr2+j);
                j++;
            }
        }   
        /* cout<<endl<<endl<<"Arreglo 1"<<endl;
        for(int i=0; i<n; i++){
            cout<<*(arr+i)<<endl;
        }
        cout<<endl<<endl<<"Arreglo 2"<<endl;
        for(int i=0; i<(n/2); i++)
            cout<< *(arr2+i)<<endl; */    
        cout<<endl<<endl<<"El resultado es "<<endl<<res<<endl;
    }else
        cout<<"Usa una cantidad n par";
    return 0; 
} 