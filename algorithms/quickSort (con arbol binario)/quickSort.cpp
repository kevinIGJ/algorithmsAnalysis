#include "arbolBinario.h"
void Mostrar(int &d){
	cout << d << "   ";
}
int main(){
	ArbolABB ArbolInt;
	int n;
    cout<<"Dame el tamaño del array"<<endl;
    cin>>n;
    cout<<endl<<endl;
    for(int v,i=0; i<n; i++){
        cout<<"Dame el valor "<< i+1<< endl;
		cin>>v;
        ArbolInt.Insertar(v);
    }
	cout<<endl<<endl;
	ArbolInt.InOrden(Mostrar);
	cout << endl;
	return 0;
}