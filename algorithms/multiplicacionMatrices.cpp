#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int main() {
    int **a,**b;
    a=(int**)malloc(sizeof(int*)*3);
    b=(int**)malloc(sizeof(int*)*3);
    for(int i=0;i<3;i++){     //creacion de dos matrices 
        *(a+i)=(int *)malloc(sizeof(int)*3);
        *(b+i)=(int *)malloc(sizeof(int)*3);
    }

    for(int i=0;i<3;i++)   //asignacion de valores a las matrices
        for(int j=0;j<3;j++){
            *(*(a+i)+j)=i;
            *(*(b+i)+j)=j;
        }

    for(int i=0;i<3;i++){  //multiplicacion de matrices 
        for(int j=0;j<3;j++){
            int c=0;
            for(int k=0; k<3; k++)
               c+= *(*(a+i)+k) *  *(*(b+k)+j);
            cout<<"  "<<c<<"  ";
        }      
        cout<<endl;
    }
    return 0; 
} 