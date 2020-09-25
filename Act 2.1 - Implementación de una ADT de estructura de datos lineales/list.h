/*

Aarón Gonzalo Ramírez Tafolla - A01351621

Actividad 2.1
Fecha de entrega: 28/09/2020

*/

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
//Librería de excepciones por el profesor Pedro Óscar Pérez Murrieta.
#include "exception.h"

template <class T> class List;

template <class T>
class Nodo {
	private:
		//Constructor default para crear una estructura con un valor apuntando al vacío.
		Nodo(T);
		//Constructor para crear una estructura con un valor y un apuntador al siguiente nodo.
		Nodo(T, Nodo<T>*);

		//Atributos del nodo: valor y apuntador al siguiente nodo.
		T valor;
		Nodo<T> *next;
		
		//La clase lista puede acceder al private de Nodo.
		friend class List<T>;

};

template <class T>
Nodo<T>::Nodo(T val){
	valor = val;
	next = 0;
}

template <class T>
Nodo<T>::Nodo(T val, Nodo* nxt){
	valor = val;
	next = nxt;
}

template <class T>
class List {
	public:
		//Constructor por default. Crea una lista vacía.
		List();
		//Destructor de la lista.
		~List();
		
		//Función que elimina todos los elementos de la lista.
		void clear();
		//Función que convierte la lista a un string.
		std::string toString() const;
		//Función que checa si la lista está vacía o no.
		bool empty() const;
		//Función que agrega un nodo al principio de la lista.
		void addFirst(T val) throw (OutOfMemory);
		//Función que agrega un nodo a la lista.
		void add(T) throw (OutOfMemory);
		//Función que busca la posición de un valor en la lista.
		int find(T) const;
		//Función que cambia un valor por otro de acuerdo con su posición en la lista.
		void update(int, T) throw (IndexOutOfBounds);
		//Función que elimina el primer elemento de una lista y regresa su valor.
		T removeFirst() throw (NoSuchElement);
		//Función que elimina un nodo de la lista de acuerdo con su posición en ella y regresa su valor.
		T remove(int) throw (IndexOutOfBounds);
		
	private:
		//Apuntador que va al principio de la lista.
		Nodo<T> *head;
		//Variable que indica el número de nodos en la lista.
		int tam;
};

template <class T>
List<T>::List(){
	head = 0;
	tam = 0;
}

template <class T>
List<T>::~List(){
	clear();
}

template <class T>
void List<T>::clear() {
	Nodo<T> *p, *q;
	
	//p comienza en el principio de la lista.
	p = head;
	//p va borrando cada elemento de la lista, auxiliándose con q para manejar las posiciones de ella.
	while(p != 0){
		q = p->next;
		delete p;
		p = q;
	}
	//head apunta al vacío.
	head = 0;
	//El tamaño de la lista de vuelve 0.
	tam = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Nodo<T> *p;
	
	//p comienza en head
	p = head;
	aux << "[";
	
	//Se recorre la lista hasta que p sea NULL.
	while (p != 0) {
		//El valor del nodo al cual apunta p se mete en aux.
		aux << p->valor;
		//Después de introducir el valor, si el siguiente no es NULL, se le agrega una ", " para separar cada elemento en el string final.
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	//Si ya se pasaron todos los elementos, se cierra el string con un "]".
	aux << "]";
	//Se imprime el string.
	return aux.str();
}

template <class T>
bool List<T>::empty() const{
		//Regresa true si head está apuntando a NULL, indicando que la lista está vacía.
		return (head == 0);
}

template <class T>
void List<T>::addFirst(T val) throw (OutOfMemory) {
	Nodo<T> *newNodo;
	
	newNodo = new Nodo<T>(val);
	//Si el nodo apunta a NULL es porque se acabó la memoria. Regresa un error.
	if (newNodo == 0){
		throw OutOfMemory();
	}
	//el next del nuevo nodo apunta al vacío, que es a donde apuntaba head.
	newNodo->next = head;
	//head apunta al nodo nuevo.
	head = newNodo;
	//La lista aumenta en tamaño.
	tam++;
}

///ADD///////////////////////////////////////////////////////////////////////////////////
template <class T>
void List<T>::add(T val) throw (OutOfMemory){
	//Además del newNodo, se crea un apuntador auxiliar.
	Nodo<T> *newNodo, *p;
	
	newNodo = new Nodo<T>(val);
	//Si el nodo apunta a NULL es porque se acabó la memoria. Regresa un error.
	if(newNodo == 0){
		throw OutOfMemory();
	}
	
	//Si la lista está vacía, manda llamar la función anterior.
	if(empty()){
		addFirst(val);
		return;
	}
	
	//Se le asigna a p la dirección a la que apunta head.
	p = head;
	//p recorre la lista hasta que llega al final de ella.
	while (p->next != 0){
		p = p->next;
	}
	
	//Después de llegar al final de la lista, el next del nuevo nodo lo apunta al vacío.
	newNodo->next = 0;
	//El nodo entra en la dirección en la que se quedó apuntando p.
	p->next = newNodo;
	//La lista aumenta en tamaño.
	tam++;
}

///FIND//////////////////////////////////////////////////////////////////////////////////
template <class T>
int List<T>::find(T val) const {
	int i;
	Nodo<T> *p;
	
	i = 0;
	//p comienza al principio de la lista
	p = head;
	//Ciclo while que se ejecuta mientras p no apunte a NULL
	while(p != 0){
		//Si el valor del nodo en la dirección de memoria a la que apunta p es igual al valor que busca el usuario, regresa su posición (i).
		if(p->valor == val) {
			return i;
		}
		//Si no, busca en el siguiente.
		i++;
		p = p->next;
	}
	//Si no existe, regresa -1.
	return -1;
}

///UPDATE////////////////////////////////////////////////////////////////////////////////
template <class T>
void List<T>::update(int i, T val) throw (IndexOutOfBounds){
	int pos;
	Nodo<T> *p;
	
	//Si el índice solicitado por el usuario no entra en los límites de la lista, se regresa un error.
	if (i < 0 || i >= tam){
		throw IndexOutOfBounds();
	}
	
	p = head;
	pos = 0;
	
	//Ciclo while para buscar que la variable pos sea igual que la i (solicitada por el usuario).
	while(pos != i){
		//Como la posición no es igual al índice del usuario en este nodo, se pasa al siguiente.
		p = p->next;
		pos++;
	}
	
	//El valor del nodo al que apunta p se cambia por el valor introducido por el usuario.
	p->valor = val;
	return;
}

template <class T>
T List<T>::removeFirst() throw (NoSuchElement){
	T val;
	Nodo<T> *p;
	
	//Regresa un error si no existe un primer elemento.
	if (empty()){
		throw NoSuchElement();
	}
	
	p = head;
	
	//head apunta al elemento que le sigue al que se va a borrar
	head = p->next;
	//Se registra el valor a borrar en una variable auxiliar para poder regresarla después de borrar el nodo.
	val = p->valor;
	
	//Se elimina el nodo.
	delete p;
	//La lista disminuye su tamaño.
	tam--;
	
	//Se regresa el valor eliminado.
	return val;
}

///REMOVE////////////////////////////////////////////////////////////////////////////////
template <class T>
T List<T>::remove(int i) throw (IndexOutOfBounds){
	int pos;
	T val;
	Nodo<T> *p, *q;
	
	//Si el índice solicitado por el usuario no entra en los límites de la lista, se regresa un error.
	if (i < 0 || i >= tam){
		throw IndexOutOfBounds();
	}
	
	//Se llama la función anterior si el usuario pide remover el primer elemento.
	if (i == 0){
		return removeFirst();
	}
	
	p = head; q = 0;
	pos = 0;
	//p recorre la lista hasta que la variable pos coincida con el índice solicitado por el usuario.
	while(pos != i){
		q = p;
		p = p->next;
		pos++;
	}
	
	//Se registra el valor a borrar en una variable auxiliar para poder regresarla después de borrar el nodo.
	val = p->valor;
	//q apunta al mismo valor que apunta p para no perder la lista al eliminar p.
	q->next = p->next;
	
	//Se elimina p.
	delete p;
	
	//La lista disminuye su tamaño.
	tam--;
	
	//Se regresa el valor eliminado.
	return val;
}
#endif