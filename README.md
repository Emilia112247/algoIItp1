<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP1

## Alumno: Emilia Avila Cabrera - 112247 - (Mail) emiliaavilacabrera2@gmail.com

- Para compilar:

```bash
línea de compilación
```

- Para ejecutar:

```bash
línea de ejecución
```

- Para ejecutar con valgrind:
```bash
línea con valgrind
```

---

##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).



El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Guarda la informacion leida de cada linea en el struct pokedex y luego se cierra el archivo.
Decid'i crear una funci'on void que ordena alfabeticamente los pokemones agregados en el struct pokedex para luego utilizar las otras funciones pokedex.c. 


En el archivo "pokedex.c" la función `pokedex_agregar_pokemon` utiliza `malloc` para reservar memoria para el nuevo pokemon que se quiere agregar. Se crea un puntero auxiliar donde se reserva la memoria. Struct pokedex *ultimo->siguiente apunta al nuevo pokemon y struct pokedex *ultimo apunta al nuevo pokemon agregado.




## Respuestas a las preguntas teóricas




Complejidad de las funciones

Complejidad de csv.h

abrir_archivo_csv -> O(n) porque son instrucciones y una instruccion de complejidad n
leer_linea_csv -> O(n) porque depende de la cantidad de lineas que se van a leer
cerrar_archivo_csv -> O(1)

Complejidad de pokedex.h

crear_pokedex -> O(n) porque son intrucciones simples;
pokedex_agregar_pokemon -> O(n) porque algunas instrucciones dependen de la cantidad de elementos que se van a ingresar
pokedex_cantidad_pokemones -> O(1) porque es una instruccion
pokedex_buscar_pokemon -> O(n) porque depende del tamano del elemento a buscar para saber cuanta memoria se va a reservar
pokedex_iterar_pokemones -> O(n) porque hace n iteraciones






