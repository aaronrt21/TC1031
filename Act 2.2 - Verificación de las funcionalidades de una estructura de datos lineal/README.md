**Aarón Gonzalo Ramírez Tafolla - A01351621**
**Act 2.2: Análisis de complejidad**

**add**

Como la lista cuenta con el apuntador tail, el elemento solicitado se agrega de manera directa sin tener que realizar algún tipo de ciclo o comprobación. Por esto,
su complejidad es constante (O(1)).

**find**

La función debe de comparar cada valor de cada nodo en la lista, por lo que su complejidad es de O(n). La única excepcions se da si el usuario pide el primer o
valor; como ya existe un apuntador capaz de extraer el valor de manera directa, su complejidad sería O(1). De la misma manera, si se implementara una condición
en donde verifique si el valor corresponde al que apunta tail, esta tendría complejidad constante si el usuario pide buscar el último valor.

**update**

La función debe comparar el índice introducido por el usuario con la variable posición en aumentos de 1. Si el usuario pide actualizar el primer elemento,
la complejidad de la función es O(1). Si no, será O(n). De la misma manera, si se implementara una condición en donde verifique si el valor corresponde al
que apunta tail, esta tendría complejidad constante si el usuario pide reemplazar el último valor.

**remove**

La función sigue el mismo razonamiento que **update** en términos de complejidad. Puede ser O(1) u O(n).
