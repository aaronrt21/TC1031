**Análisis de complejidad de la suma iterativa**

La función utiliza un ciclo cuyo límite es de i = 1, mientras i sea menor o igual a n y n crece de 1 en 1. Por esto, su complejidad es O(n).

**Análisis de complejidad de la suma recursiva**
La función se manda a llamar a sí mismo 1 vez por cada ciclo. Este ciclo se va a repetir n número de veces. Su complejidad es O(n) porque la variable de control (n)
disminuye de manera lineal (n - 1)-.

**Análisis de complejidad de la suma directa**
Debido a que esta función no tiene ciclos ni funciones dentro de sí misma, su nivel de complejidad es constante; O(1).
