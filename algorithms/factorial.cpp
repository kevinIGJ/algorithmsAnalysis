#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
int factorial(int n){
    if(n==0)
        return 1;
    else
        return (n*factorial(n-1));
}
int main() {
    int x;
    cout<<"Dame el numero"<<endl;
    cin>>x;
    cout<<factorial(x)<<endl;
    return 0; 
} 