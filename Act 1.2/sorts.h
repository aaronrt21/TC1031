#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>																					//Se crea la clase con un template para poder usar distintos tipos de datos.
class Sorts {
private:
	void swap(std::vector<T>&, int, int);															//Función para cambiar dos números de posición.
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);										//Función para copiar un arreglo.
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);								//Función para juntar un pedazo del arreglo final de manera ordenada.
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);									//Función para separar un pedazo del arreglo por la mitad.
	int auxBinaria(std::vector<T> src, const int val, int low, int high);							//Función auxiliar para la búsqueda binaria.
public:
	std::vector<T> ordenaBurbuja(std::vector<T>&);													//Función de ordenamiento por el método Burbuja que llama el usuario.
	std::vector<T> ordenaSeleccion(std::vector<T>&);												//Función de ordenamiento por el método Selección que llama el usuario.
	std::vector<T> ordenaMerge(std::vector<T>&);													//Función de ordenamiento por el método Merge que llama el usuario.
	int	busqSecuencial(std::vector<T>, const int);													//Función de búsqueda secuencial que llama el usuario.
	int busqBinaria(std::vector<T>, const int);														//Función de búsqueda binaria que llama el usuario.
};

template <class T>																					//Swap toma dos elementos en un arreglo y los intercambia.
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>																					//OrdenaBurbuja organiza un vector moviendo dos índices juntos a lo largo de él y moviendo el valor más
std::vector<T> Sorts<T>::ordenaBurbuja(std::vector<T>& source) {									//pequeño a la izquierda por medio de un swap.
	std::vector<T> v(source);
	
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	
	for (int i=0; i < v.size(); i++){
		source[i]=v[i];
	}
	
	return source;
}

template <class T>																					//OrdenaSeleccion organiza un vector fijando el índice correspondiente a un valor de este hasta que encuentre
std::vector<T> Sorts<T>::ordenaSeleccion(std::vector<T>& source) {									//otro índice correspondiente a un valor más pequeño. Cuando ya no existe uno más pequeño, el valor fijado (seleccionado)
	std::vector<T> v(source);																		//se mueve (por medio de un swap) hasta el extremo izquierdo, el cual va cambiando cada que se hace el swap.
	
	int pos;

	for (int i = v.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(v, i, pos);
		}
	}
	
	for (int i=0; i < v.size(); i++){
		source[i]=v[i];
	}
	
	return source;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {					//CopyArray hace una copia del vector para usarla en el ordenaMerge.
	for (int i = low; i <= high; i++) {																//El valor de B[0] se guardará en el de A[0] y así sucesivamente.
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {		
	int i, j, k;																					//Se crean variables para manejar los valores y límites de los arreglos.

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high) {																	//Ciclo que, en base a su condicional, ajusta los límites del arreglo a manejar.
		if (A[i] < A[j]) {
			B[k] = A[i];																			
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {																		//Caso base.
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);																		//Recursividad.
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);																//Se manda a llamar la función anterior.
	copyArray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T>& source) {										//Función simplificada para el usuario.
	std::vector<T> v(source);
	std::vector<T> aux(v.size());																	//Arreglo auxiliar en donde se almacenarán los valores conforme se vayan juntando por medio de MergeArray para
																									//después pasarlos al vector v.
	mergeSplit(v, aux, 0, v.size() - 1);
	for(int i = 0; i < v.size();i++){
		source[i] = v[i];
	}
	return source;
}

template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> source, const int valor){
	for(int i = 0; i <= source.size(); i++){														//Ciclo que busca el valor solicitado por el usuario de forma iterativa, comparándolo con cada valor del vector.
		if (source[i] == valor){	
			return i;																				//Regresa el índice en el cual se encuentra el valor que buscaba el usuario.
		} 
	}
	return -1;																						//Regresa -1 si el valor no existe dentro del arreglo.
}

template <class T>
int Sorts<T>::auxBinaria(std::vector<T> source, const int val, int low, int high) {					//Función que hace todo el trabajo para evitar que el usuario deba usar más de 2 valores de entrada.
    if (high >= low) { 																				//Comprobar que el arreglo tenga más de 1 elemento.
        int mid = (low + high) / 2; 																//Encontrar el valor medio para dividir el arreglo en dos.

        if (source[mid] == val){ 																	//Caso base. Si el valor del arreglo en mid es igual al valor buscado se regresa mid (el índice en donde se
            return mid;																				//encuentra ubicado).
		}

        if (source[mid] > val){																		//Compara el valor del arreglo en mid con el valor para saber en qué lado del arreglo se debe enfocar.
            return auxBinaria(source, val, low, mid - 1);											//Si source[mid] es más grande que val, quiere decir que val se encuentra en la mitad izquierda del arreglo (o no existe).
		}																							//Por esto, alllamarse la nueva función (recursividad) se le cambia el límite superior a mid-1.
  
        return auxBinaria(source, val, mid + 1, high); 												//Mismo razonamiento anterior, pero se cambia el límite inferior porque el valor se encuentra del lado derecho (o no existe).
    } 
	
	else {
		for(int i = 0; i < source.size();){															//Algoritmo que busca la posición en la que se debe de encontrar el valor después de encontrar que no existe en el arreglo.
			if (val > source[i]){
				i++;
			}
			else if (val < source[i]){
				i--;
				return i;
			}
		}
	}

} 

template < class T>
int Sorts<T>::busqBinaria(std::vector<T> source, const int valor){									//Función para el usuario. Recibe el vector y el valor que busca.
	return auxBinaria(source, valor, 0, source.size()-1);											//Se llama la función anterior.
}
#endif
