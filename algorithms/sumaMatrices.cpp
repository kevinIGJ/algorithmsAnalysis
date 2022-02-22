#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int main() {
    int **a,**b;
    a=(int**)malloc(sizeof(int*)*3);
    b=(int**)malloc(sizeof(int*)*3);
    for(int i=0;i<3;i++){
        *(a+i)=(int *)malloc(sizeof(int)*3);
        *(b+i)=(int *)malloc(sizeof(int)*3);
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            *(*(a+i)+j)=i;
            *(*(b+i)+j)=j;
        }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<a[i][j]+b[i][j]<<"   ";
        cout<<endl;
    }
    return 0; 
} 