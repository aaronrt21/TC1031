**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Actividad 3.2 - Árbol Heap: Implementación de una fila priorizada**

**Análisis de complejidad**

**push**

La función push utiliza la función parent para introducir valores al arreglo. Como la función parent funciona dividiendo el índice sobre 2, la complejidad siempre será
O(log(n)).

**pop**

La función pop utiliza las funciones left y right para encontrar los índices necesarios para eliminar el valor del arreglo. La función pop tendrá complejidad
O(log(n)).

**top**

La función top no realiza ninguna operación; regresa el primer valor del arreglo. Debido a esto, su complejidad es constante: O(1).

**empty**

La función empty sólo comprueba si count es igual a 0, no realiza ninguna operación. Debido a esto, su complejidad es constante: O(1).

**size**

La función size sólo regresa un valor (count) sin modificarlo. Debido a esto, su complejidad es constante: O(1).
