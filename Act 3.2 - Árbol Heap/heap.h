#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	//Tamaño del arreglo
	unsigned int tam;
	//Cantidad de espacios ocupados en el arreglo.
	unsigned int count;
	//Función que regresa el padre de un valor en el arreglo.
	unsigned int parent(unsigned int) const;
	//Función que regresa el left de un valor.
	unsigned int left(unsigned int) const;
	//Función que regresa el right de un valor.
	unsigned int right(unsigned int) const;
	//Función que organiza el arreglo.
	void heapify(unsigned int);
	//Función que intercambia las posiciones de dos valores en un arreglo.
	void swap(unsigned int, unsigned int);
	
public:
	//Constructor.
	Heap(unsigned int) throw (OutOfMemory);
	//Destructor.
	~Heap();
	//Función que verifica si el arreglo no tiene valores.
	bool empty() const;
	//Función que verifica si el arreglo ya tiene la cantidad máxima de valores.
	bool full() const;
	//Función que agrega un valor al arreglo y lo acomoda usando parent.
	void push(T) throw (Overflow);
	//Función que elimina el primer valor del arreglo y lo vuelve a organizar usando heapify.
	T pop() throw (NoSuchElement);
	//Función que regresa el primer valor del arreglo.
	unsigned int top() const;
	//Función que regresa el tamaño (count) del arreglo.
	int size() const;
	//Función que reinicia el count del arreglo.
	void clear();
	//Función que convierte el arreglo en un string.
	std::string toString() const;
};

//Se crea un arreglo con un tamaño específico.
template <class T>
Heap<T>::Heap(unsigned int t) throw (OutOfMemory) {
	tam = t;
	data = new T[tam];
	if (data == 0) {
		throw OutOfMemory();
	}
	//El arreglo está vacío.
	count = 0;
}

template <class T>
Heap<T>::~Heap() {
	//Se borra el objeto data, se apunta a NULL, tam y count se vuelven 0.
	delete [] data;
	data = 0;
	tam = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const {
	//Si count es 0, el arreglo está "vacío".
	return (count == 0);
}

template <class T>
bool Heap<T>::full() const {
	//Si count es igual al tamaño máximo especificado, el arreglo está lleno.
	return (count == tam);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return (1 + (pos * 2));
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return (2 + (pos * 2));
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	//Cambia los valores de los índices a utilizar en el swap en base a ciertas condiciones.
	if (le <= count && data[le] < data[min]){
		min = le;
	}
	if (ri <= count && data[ri] < data[min]){
		min = ri;
	}
	if (min != pos) {
		//Cambia los valores de posición.
		swap(pos, min);
		//Vuelve a organizar el arreglo.
		heapify(min);
	}
}

template <class T>
void Heap<T>::push(T val) throw (Overflow) {
	unsigned int pos;
	if (full()) {
		throw Overflow();
	}
	
	pos = count;
	count++;
	//Mientras el arreglo no esté vacío y el valor agregado sea menor al parent del último valor en el arreglo.
	while (pos > 0 && val < data[parent(pos)]){
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Heap<T>::pop() throw (NoSuchElement) {
	if (empty()) {
		throw NoSuchElement();
	}
	T aux = data[0];
	
	//Se reemplaza el primer valor, se disminuye el count.
	data[0] = data[--count];
	//Se organiza el arreglo.
	heapify(0);
	return aux;
}

template <class T>
unsigned int Heap<T>::top() const {
	return data[0];
}

template <class T>
int Heap<T>::size() const {
	return count;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}
	

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	
	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}

#endif
	
