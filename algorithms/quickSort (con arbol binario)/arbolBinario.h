#pragma once
#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;

class ArbolABB {
private:
	class Nodo {
	public:
		Nodo(const int dat, Nodo *izq = NULL, Nodo *der = NULL) :
			dato(dat), izquierdo(izq), derecho(der) {}
		int dato;
		Nodo *izquierdo;
		Nodo *derecho;
	};
	Nodo *raiz;
	Nodo *actual;
	int contador;
	int altura;

public:
	ArbolABB() : raiz(NULL), actual(NULL) {}
	~ArbolABB() { Podar(raiz); }
	void Insertar(const int dat);
	void Borrar(const int dat); 
	bool Buscar(const int dat);
	bool Vacio(Nodo *r) { return r == NULL; }
	bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
	const int NumeroNodos();
	const int AlturaArbol();
	int Altura(const int dat);
	int &ValorActual() { return actual->dato; }
	void Raiz() { actual = raiz; }
	void InOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void PreOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
	void PostOrden(void(*func)(int&), Nodo *nodo = NULL, bool r = true);
private:
	void Podar(Nodo* &);
	void auxContador(Nodo*);
	void auxAltura(Nodo*, int);
};