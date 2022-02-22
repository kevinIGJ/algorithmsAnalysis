#include "arbolBinario.h"
void ArbolABB::Podar(Nodo* &nodo){
	if (nodo) {
		Podar(nodo->izquierdo); // 
		Podar(nodo->derecho);   // 
		delete nodo;            // 
		nodo = NULL;
	}
}

// 
void ArbolABB::Insertar(const int dat)
{
	Nodo *padre = NULL;

	actual = raiz;
	while (!Vacio(actual) /* && dat != actual->dato */) {
		padre = actual;
		if (dat >= actual->dato) actual = actual->derecho;
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	if (!Vacio(actual)) return;
	if (Vacio(padre)) raiz = new Nodo(dat);
	else if (dat < padre->dato) padre->izquierdo = new Nodo(dat);
	else if (dat >= padre->dato) padre->derecho = new Nodo(dat);
}

// 
void ArbolABB::Borrar(const int dat)
{
	Nodo *padre = NULL;
	Nodo *nodo;
	int aux;

	actual = raiz;
	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) { // 
			if (EsHoja(actual)) { // 
				if (padre){ 
					if (padre->derecho == actual) padre->derecho = NULL;
					else if (padre->izquierdo == actual) padre->izquierdo = NULL;
				}
				delete actual; // 
				actual = NULL;
				return;
			}
			else { // 
			   // 
				padre = actual;
				// 
				if (actual->derecho) {
					nodo = actual->derecho;
					while (nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// 
				else {
					nodo = actual->izquierdo;
					while (nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// 
				// 
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		}
		else { // 
			padre = actual;
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
}

// Recorrido de árbol en inorden
// void (*func)(int&)
void ArbolABB::InOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
	func(nodo->dato);
	if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

// 
// void (*func)(int&)
void ArbolABB::PreOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	func(nodo->dato);
	if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// 
// void (*func)(int&)
void ArbolABB::PostOrden(void(*func)(int&), Nodo *nodo, bool r)
{
	if (r) nodo = raiz;
	if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
	if (nodo->derecho) PostOrden(func, nodo->derecho, false);
	func(nodo->dato);
}

// 
bool ArbolABB::Buscar(const int dat)
{
	actual = raiz;

	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) return true; // 
		else if (dat > actual->dato) actual = actual->derecho; // 
		else if (dat < actual->dato) actual = actual->izquierdo;
	}
	return false; // 
}

// 
int ArbolABB::Altura(const int dat)
{
	int altura = 0;
	actual = raiz;

	// 
	while (!Vacio(actual)) {
		if (dat == actual->dato) return altura; // 
		else {
			altura++; // 
			if (dat > actual->dato) actual = actual->derecho;
			else if (dat < actual->dato) actual = actual->izquierdo;
		}
	}
	return -1; // 
}

// 
const int ArbolABB::NumeroNodos()
{
	contador = 0;

	auxContador(raiz); // 
	return contador;
}

// 
void ArbolABB::auxContador(Nodo *nodo)
{
	contador++;  // 
	// 
	if (nodo->izquierdo) auxContador(nodo->izquierdo);
	if (nodo->derecho)   auxContador(nodo->derecho);
}

// 
const int ArbolABB::AlturaArbol()
{
	altura = 0;

	auxAltura(raiz, 0); // 
	return altura;
}

// 
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
	// 
	if (nodo->izquierdo) auxAltura(nodo->izquierdo, a + 1);
	if (nodo->derecho)   auxAltura(nodo->derecho, a + 1);
	// 
	if (EsHoja(nodo) && a > altura) altura = a;
}



