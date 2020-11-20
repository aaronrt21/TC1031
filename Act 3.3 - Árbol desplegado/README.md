**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Funciones y análisis de complejidad**

**add**

La función add agrega un valor al árbol igual que en un BST. Después de agregarlo, se realiza un splay para que el valor recién agregado se vaya al root. Como el
algoritmo no garantiza un árbol balanceado, el add puede generar un árbol degenerado, lo cual hace que su complejidad sea de O(n).

**remove**

La función remove elimina un nodo del árbol siguiendo el mismo proceso que un BST. Después de eliminarlo, realiza un splay sobre el padre del nodo eliminado para
moverlo al root. Como tiene que recorrer nodo por nodo, el algoritmo tiene complejidad O(n).

**find**

Esta función busca un valor y realiza un splay sobre el nodo en el que se encuentra para moverlo al root del árbol. El algoritmo de búsqueda tiene complejidad O(n).

**inorder**

Esta función guarda los valores del árbol usando el algoritmo inorder: en un subárbol, se despliega primero el izquierdo, luego el root y al final el derecho. También
se incluye la función preorder, la cual despliega el root de un subárbol, su izquierdo y finalmente el derecho.

**size**

Esta función simplemente regresa una constante, por lo que su complejidad es de O(1). La constante representa la cantidad de datos guardados en el árbol.
