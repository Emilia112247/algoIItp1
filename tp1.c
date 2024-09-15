#include "src/csv.h"
#include "src/pokedex.h"
#include <stdio.h>
#include <string.h>

struct nodo_pokemon { //un nodo de la lista de pokemones
    struct pokemon *pokemones; 
    struct nodo_pokemon *siguiente; //este es un puntero que me apunta al siguiente de la lista, 
};

struct pokedex{
	struct nodo_pokemon *primero; //apunta al primer nodo de la lista
	struct nodo_pokemon *ultimo; //apunta al ultimo de la lista
	size_t cantidad_pokemones;
};



void mostrar_pokemon(struct pokedex *pokedex){
	struct nodo_pokemon *nodo_actual;
	nodo_actual = pokedex->primero;
	while(nodo_actual != NULL){
		printf("Nombre: %s\n", nodo_actual->pokemones->nombre);
		printf("Tipo: %c\n", nodo_actual->pokemones->tipo);
		printf("Fuerza: %d\n", nodo_actual->pokemones->fuerza);
		printf("Destreza: %d\n", nodo_actual->pokemones->destreza);
		printf("Resistencia: %d\n", nodo_actual->pokemones->resistencia);
		nodo_actual = nodo_actual->siguiente;
	}
}

int main(int argc, char const *argv[])
{
	struct pokedex *ctx;
	struct archivo_csv *mi_archivo = abrir_archivo_csv("pokedex.csv",';');
	struct pokedex *nueva_pokedex = pokedex_crear();
	leer_linea_csv(mi_archivo,5,pokedex_agregar_pokemon,ctx);
	cerrar_archivo_csv(mi_archivo);
	ordenar_alfabeticamente(nueva_pokedex);
	pokedex_iterar_pokemones(nueva_pokedex,pokedex_agregar_pokemon,ctx);
	pokedex_iterar_pokemones(nueva_pokedex,mostrar_pokemon,ctx);//no entiendo bien la funcionalidad del puntero ctx
	return 0;
}
