/*
Actividad 1.1 - Funciones Iterativas, Recursivas y su Análisis de Complejidad

Aarón Gonzalo Ramírez Tafolla
A01351621

25/08/2020
*/

#ifndef SUMA_H
#define SUMA_H

#include <iostream>

/*

La función sumaIterativa recibe n como input y hace una suma de 1 a n aumentando los pasos de
1 en 1 y almacenando el resultado de cada paso en la variable cont. Por cada paso, resta 1 a n
para sumarlo en el paso siguiente.

*/
class Funciones {
	public:
		int sumaIterativa(int n);
		int sumaRecursiva(int n);
		int sumaDirecta (int n);
};
int Funciones::sumaIterativa(int n) {					//Declaración de la función
	int cont = 0;
	int aux = n;
	for (int i = 0; i <= aux; i++) {			//Establece que n es el 'tope' del ciclo.
		cont = cont + n;
		n = n - 1;							//Suma al contador y cambio de n
	}
	
	return cont;							//Regresa el contador.
}

/*
La función sumaRecursvia recibe n como input. Primero, como caso base, verifica que el valor de
n no sea igual o mayor a 1. Si lo es, regresa como resultado 1 y se acaba la función. Si no lo
es, va a regresar el resultado de la suma de n mas el resultado de la misma función evaluada
en n-1. El proceso se repite hasta que se evalúe la función con sumaRecursiva(1), en cuyo caso
va a regresar un 1 y se realizarán las sumas pendientes de los casos alternativos.
*/

int Funciones::sumaRecursiva(int n) {					//Declaración de la función
	if (n < 1) {							
		return 0;							//Caso base
	} else {
		return n + sumaRecursiva(n - 1);	//Función recursiva
	}
}

/*
La función sumaDirecta recibe n como input y lo mete a la fórmula para sumar enteros de manera
directa, sin hacer ciclos ni llamar a otra función.
*/

int Funciones::sumaDirecta(int n) {					//Declaración de la función
	return (n*(n+1))/2;						//Fórmula
}

#endif