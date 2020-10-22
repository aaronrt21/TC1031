**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Funciones y análisis de complejidad**

**add**

La función add agrega un valor al árbol igual que en un BST. Después de agregarlo, se realiza un splay para que el valor recién agregado se vaya al root.

**remove**

La función remove elimina un nodo del árbol siguiendo el mismo proceso que un BST. Después de eliminarlo, realiza un splay sobre el padre del nodo eliminado para
moverlo al root.

**find**

Esta función busca un valor y realiza un splay sobre el nodo en el que se encuentra para moverlo al root del árbol.

**inorder**

Esta función guarda los valores del árbol usando el algoritmo inorder: en un subárbol, se despliega primero el izquierdo, luego el root y al final el derecho. También
se incluye la función preorder, la cual despliega el root de un subárbol, su izquierdo y finalmente el derecho.

**size**

Esta función simplemente regresa una constante. La constante representa la cantidad de datos guardados en el árbol.

**Complejidad**

A pesar de que se dice que un Splay Tree tiene una complejidad O(log(n)), el hecho de que no garantiza que el árbol esté balanceado puede ocasionar que este se vuelva
degenerado. Si se tiene un árbol degenerado (peor de los casos), la complejidad de las funciones add, remove, find e inorder se volverá lineal (O(n)). La función
size, al regresar una constante, tiene una complejidad de O(1).
