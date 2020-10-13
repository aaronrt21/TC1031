#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include <sstream>

template <class T> class BST;

template <class T>
class Node {
	private:
		//Atributos de un nodo: valor, apuntador al nodo izquierdo y derecho.
		T value;
		Node *left, *right;

		//Función que regresa un apuntador al sucesor de un nodo.
		Node<T>* successor();

	public:
		//Constructor
		Node(T);
		//Constructor 
		Node(T, Node<T>*, Node<T>*);
		//Función que agrega un valor a la estructura.
		void add(T);
		//Función que encuentra un valor en la estructura.
		bool find(T);
		//Función que devuelve el nivel en el que se encuentra un valor.
		int whatlevelamI(T);
		//Función que elimina un elemento de la estructura.
		void remove(T);
		//Función que elimina todos los nodos de un árbol, menos el primero (root).
		void removeChilds();
		//Funciones que registran los valores del árbol en un string ordenados de forma distinta.
		void inorder(std::stringstream&) const;
		void preorder(std::stringstream&) const;
		void postorder(std::stringstream&) const;
		void levelorder(std::stringstream&) const;
		//Funcion auxiliar que ayuda a levelorder para que sólo necesite recibir un dato.
		void levelorder_aux(std::stringstream&, int) const;
		//Función que devuelve true si un nodo tiene ancestros.
		bool ancestors(T, std::stringstream&) const;
		//Función que devuelve la altura total del árbol.
		int height() const;
		
		//Indica que la clase BST puede acceder a los atributos privados de Node
		friend class BST<T>;
};

//Constructor que recibe un valor de tipo T. El valor del nodo es igual al recibido, left y right apuntan a NULL.
template <class T>
Node<T>::Node(T val) {
	value = val;
	left = 0;
	right = 0;
}

//Constructur que recibe un valor y dos apuntadores. Cada atributo es igual a su respectiva entrada.
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri) {
	value = val;
	left = le;
	right = ri;
}

///ADD//////////////////////////////////////
//Recibe un valor para agregarlo al árbol.
template <class T>
void Node<T>::add(T val) {
	//Se compara el valor introducido con un valor existente en el árbol.
	if (val < value) {
		//Si el valor introducido es menor que el que ya existe y left no apunta a NULL, se sobreescribe el valor de left.
		if (left != 0) {
			left->add(val);
		//Si left apunta a NULL, se crea un nodo nuevo con el valor introducido.
		} else {
			left = new Node<T>(val);
		}
	//Si el valor introducido es mayor que el que ya existe y right no apunta a NULL, se sobreescribe el valor de right.
	} else {
		if (right != 0) {
			right->add(val);
		//Si right apunta a NULL, se crea un nodo nuevo con el valor introducido.
		} else {
			right = new Node<T>(val);
		}
	}
}

///FIND/////////////////////////////////////
//Recibe un valor y lo busca en el árbol.
template <class T>
bool Node<T>::find(T val) {
	
	//Caso base. Si el valor es igual al valor actual, regresa true.
	if (val == value) {
		return true;
		//Si el valor es menor al primero, realiza una búsqueda en su left si este no apunta a NULL.
	} else if (val < value) {
		return (left != 0 && left->find(val));
		//Si el valor es mayor al primero, realiza una búsqueda en su right si este no apunta a NULL.
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

///WHATLEVELAMI/////////////////////////////
//Recibe un valor y regresa el nivel en el que se encuentra.
template <class T>
int Node<T>::whatlevelamI(T val) {
	//Caso base. Si el valor buscado es igual al valor actual, regresa 1.
	if (val == value) {
		return 1;
	//Si el valor buscado es menor al valor actual, verifica que left no apunte a NULL y realiza una búsqueda sumándole 1 a su resultado.
	} else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	//Si el valor buscado es mayor al valor actual, verifica que right no apunte a NULL y realiza una búsqueda sumándole 1 a su resultado.
	} else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	//Si el valor buscado no está en la estructura, regresa -1.
	return -1;
}

///ANCESTORS////////////////////////////////
//Recibe un valor y un stringstream en donde guardar los ancestros de ese valor.
template <class T>
bool Node<T>::ancestors(T val, std::stringstream &aux) const{
	//Caso base. Regresa true cuando el programa topa con el valor solicitado, terminando la función.
	if (val == value) {
	  return true;
	//Si el valor buscado es menor al actual...
	} else if (val < value) {
		//...y si la posición actual en el stringstream es diferente a 1, se le agrega un espacio y el valor actual.
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		//Después de modificar el stringstream, se repite el proceso para buscar el resto de los ancestros.
		return (left != 0 && left->ancestors(val,aux));
	//Si el valor buscado es mayor al actual...
	} else if (val > value) {
		//...y si la posición actual en el stringstream es diferente a 1, se le agrega un espacio y el valor actual.
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		//Después de modificar el stringstream, se repite el proceso para buscar el resto de los ancestros.
		return (right != 0 && right->ancestors(val,aux));
	}
}

///Successor////////////////////////////////
template <class T>
Node<T>* Node<T>::successor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

///REMOVE///////////////////////////////////
//Elimina un nodo del árbol.
template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;
	
	//Si el valor a eliminar es menor que el valor actual
	if (val < value) {
		//y si el left del valor actual no apunta a NULL
		if (left != 0) {
			//y si el valor al que apunta left es igual al valor a eliminar
			if (left->value == val) {
				//Old apunta a donde apunta left.
				old = left;
				//Succ apunta al sucesor de left.
				succ = left->successor();
				//Si succ no apunta a NULL
				if (succ != 0) {
					//Los apuntadores left y right de succ apuntan al left y right de old.
					succ->left = old->left;
					succ->right = old->right;
				}
				//Left apunta a donde succ y se elimina old.
				left = succ;
				delete old;
			//Si el valor de left no es igual al valor actual, realiza otra búsqueda en el left de este.
			} else {
				left->remove(val);
			}
		}
	//Si el valor a eliminar es mayor que el valor actual
	} else if (val > value) {
		//y si el right del valor actual no apunta a NULL
		if (right != 0) {
			//y si el valor al que apunta right es igual al valor a eliminar
			if (right->value == val) {
				//Old apunta a donde apunta right.
				old = right;
				//Succ apunta al sucesor de right.
				succ = right->successor();
				if (succ != 0) {
					//Los apuntadores left y right de succ apuntan al left y right de old.
					succ->left = old->left;
					succ->right = old->right;
				}
				//Right apunta a donde succ y se elimina old.
				right = succ;
				delete old;
			//Si el valor de right no es igual al valor actual, realiza otra búsqueda en el right de este.
			} else {
				right->remove(val);
			}
		}
	}
}

///REMOVECHILDS/////////////////////////////
//Elimina todos los nodos menos el primero.
template <class T>
void Node<T>::removeChilds() {
	//Si left no apunta a NULL
	if (left != 0) {
		//Repite la función en el left para llegar al fondo
		left->removeChilds();
		//Después de que se llegue al fondo del árbol, elimina todos los left.
		delete left;
		//Left se apunta a NULL.
		left = 0;
	}
	//Si right no apunta a NULL
	if (right != 0) {
		//Repite la función en el right para llegar al fondo
		right->removeChilds();
		//Después de que se llegue al fondo del árbol, elimina todos los right.
		delete right;
		//Right se apunta a NULL.
		right = 0;
	}
}

///INORDER//////////////////////////////////
//Despliega primero el subárbol izquierdo y luego el derecho.
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	//Se repite la función hasta que left sea NULL (Hasta llegar al límite izquierdo del árbol)
	if (left != 0) {
		left->inorder(aux);
	}
	//Si la posición en el string es distinta a 1 se agrega un espacio; luego, el valor.
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	//Se repite lo mismo para right.
	if (right != 0) {
		right->inorder(aux);
	}
}

///PREORDER/////////////////////////////////
//Se despliegan los elementos de la izquierda, luego los que sobraron a la derecha en el subárbol izquierdo.
template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	//Se agrega el valor al string
	aux << value;
	//Se agrega un espacio y se repite la función mientras left no sea NULL.
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	//Después de registrar los izquierdos, agrega un espacio y se repite la función mientras right no sea NULL.
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

///POSTORDER////////////////////////////////
//Despliega primero las hojas de un subárbol y luego su padre, empezando por el nodo izquierdo.
template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	//Mientras left no apunte a NULL se repite la función.
	if (left != 0) {
		left->postorder(aux);
	}
	
	//Mientras right no apunte a NULL se repite la función.
	if (right != 0) {
		right->postorder(aux);
	}
	//Si la posición en el string no es 1, agrega un espacio y luego el valor actual.
	if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}

///LEVELORDER_AUX///////////////////////////
//Recibe un string y el nivel en el que se encuentra el valor actual. Despliega todos los nodos de cada nivel de izquierda a derecha.
template <class T>
void Node<T>::levelorder_aux(std::stringstream &aux, int level) const {
	
	//Si el nivel es 0 y  la posición en el string no es 1, agrega un espacio al string y luego el valor.
	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	//Mientras left no apunte a NULL, repite la operación disminuyendo el nivel en 1.
	if (left != 0) {
		left->levelorder_aux(aux, level -1);
	}
	//Mientras right no apunte a NULL, repite la operación disminuyendo el nivel en 1.
	if (right != 0) {
		right->levelorder_aux(aux, level -1);
	}

}

///LEVELORDER///////////////////////////////
//Función que recibe únicamente el string donde guardar los datos.
template <class T>
void Node<T>::levelorder(std::stringstream &aux) const {
	//El nivel inicial va a ser igual a la altura total del árbol.
	int level = height();
	//Se llama la función auxiliar por cada nivel.
	for(int i = 0; i < level; i++){
			levelorder_aux(aux, i);
	}
}

///HEIGHT///////////////////////////////////
//Regresa la altura total del árbol.
template <class T>
int Node<T>::height() const {

	int lev_left = 0;
	int lev_right = 0;
	
	//Mientras left no apunte a NULL
	if (left != 0) {
		//Se repite la función, sumándole 1 al valor de retorno.
		lev_left = left->height() + 1;
	}
	//Mientras right no apunte a NULL
	if (right != 0) {
		//Se repite la función, sumándole 1 al valor de retorno.
		lev_right= right->height() +1;
	}
	//Si ambos contadores son 0, no hay mayor altura. Se regresa 1.
	if (lev_left == 0 && lev_right == 0) {
		return 1;
	}
	//Regresa el contador más grande, pues es el que llegó más abajo en el árbol.
	if (lev_right > lev_left) {
		return lev_right;
	} else {
		return lev_left
	}
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	//Constructor de la estructura
	BST();
	//Destructor de la estructura
	~BST();
	//Verifica si la estructura está vacía.
	bool empty() const;
	//Agrega a la estructura.
	void add(T);
	//Encuentra (o no) un valor en la estructura.
	bool find(T) const;
	//Regresa el nivel en el que se encuentra un valor de la estructura.
	int  whatlevelamI(T) const;
	//Elimina un nodo de la estructura.
	void remove(T);
	//Elimina todos los nodos de la estructura, incluyendo el root.
	void removeAll();
	//Funciones de tipo string en donde se manipulan los strings auxiliares de las funciones de la clase Node.
	std::string inorder() const;
	std::string preorder() const;
	std::string postorder() const;
	std::string levelorder() const;
	//Función que junta todos los orders en un sólo string.
	std::string visit();
	//Función de tipo string que modifica el string auxiliar de la función de la clase Node.
	std::string ancestors(T) const;
	//Regresa la altura (cantidad de niveles) de la estructura.
	int height() const;
};

//Constructor de una estructura vacía.
template <class T>
BST<T>::BST(){
	root = 0;
}

//Destructor de la estructura.
template <class T>
BST<T>::~BST() {
	//Se eliminan todos los nodos.
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	//Si root apunta a NULL quiere decir que no hay ningún valor ahí, indicando que la estructura está vacía.
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	//Verifica que root no apunte a NULL
	if (root != 0) {
		//Verifica que el valor no esté repetido.
		if (!root->find(val)) {
			//Agrega el valor en el root.
			root->add(val);
		}
	//Crea un nuevo nodo con el valor introducido. Root apunta a ese nuevo nodo.
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (root != 0) {
		//Si el valor a eliminar es el mismo dentro de root...
		if (val == root->value) {
			//Se crea un apuntador que apunta al successor de root.
			Node<T> *succ = root->successor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			//Se elimina el root.
			delete root;
			//Root ahora apunta a succ
			root = succ;
		} else {
		//Si el valor no es igual al que está dentro del root, se repite la función.
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		//Elimina todos los nodos ddependientes del root.
		root->removeChilds();
	}
	//Elimina el root y lo apunta a NULL.
	delete root;
	root = 0;
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		//Repite la misma función mientras root no apunte a NULL.
		return root->find(val);
	}
	else {
		//Si root es NULL, regresa false.
		return false;
	}
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	//Si root no apunta a NULL
	if (root != 0) {
		//se repite la función y su valor de retorno se guarda en num
	 	int num = root->whatlevelamI(val);
		//Si num es menor a 0, se regresa un -1.
		if(num < 0){
			return -1;
		}
		return num;
	}
	else {
		//Si el valor es inválido, se regresa un -1.
		return -1;
	}
}

template <class T>
std::string BST<T>::inorder() const {
	//Se crea el string auxiliar y se manda a llamar el inorder de Node empezando en el root.
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	//Se crea el string auxiliar y se manda a llamar el preorder de Node empezando en el root.
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	//Se crea el string auxiliar y se manda a llamar el postorder de Node empezando en el root.
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levelorder() const {
	//Se crea el string auxiliar y se manda a llamar el levelorder de Node empezando en el root.
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::height() const {
	//Se regresa el height de la clase Node empezando en el root.
	return root->height();
}


template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	aux << "[";
	if (!empty()) {
		//Se regresa el height de la clase Node empezando en el root.
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() {
	std::stringstream aux;
	//Se juntan todos los orders en uno. Se separan con un salto de línea.
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelorder();
	return aux.str();
}


#endif /* BST_H_ */
