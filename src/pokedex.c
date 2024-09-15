#include "pokedex.h"
#include <string.h>

typedef struct nodo_pokemon { //un nodo de la lista de pokemones
    struct pokemon *pokemones; 
    struct nodo_pokemon *siguiente; //este es un puntero que me apunta al siguiente de la lista, 
}nodo_pokemon;

typedef struct pokedex{
	struct nodo_pokemon *primero; //apunta al primer nodo de la lista
	struct nodo_pokemon *ultimo; //apunta al ultimo de la lista
	size_t cantidad_pokemones;
}pokedex;

struct pokedex *pokedex_crear()
{	
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	if(nueva_pokedex == NULL){
		return NULL;
	}
	
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;
	return nueva_pokedex;
	
}
//T(n)<c*(f(n))
//6+n <C*(n)
//6+n <100n
//n = 1
//O(n)
void ordenar_alfabeticamente(struct pokedex *pokedex) //m'etodo de burbujeo
{	
	if(pokedex == NULL){
		return;
	}
	bool cambios_realizados;
	struct nodo_pokemon *nodo_actual;
	struct nodo_pokemon *nodo_siguiente;
	
	do{
		cambios_realizados = false;
		nodo_actual = pokedex->primero;
	
		while(nodo_actual->siguiente != NULL){
			nodo_siguiente = nodo_actual->siguiente;
			if(strcmp(nodo_actual->pokemones->nombre,nodo_siguiente->pokemones->nombre) > 0){
				struct pokemon *auxiliar = nodo_actual->pokemones;
				nodo_actual->pokemones = nodo_siguiente->pokemones;
				nodo_siguiente->pokemones = auxiliar;
				cambios_realizados = true;
			}
			nodo_actual = nodo_actual->siguiente;
		}
	}
	while(cambios_realizados);
}

//T(n) < 7T(n/n-1)+O(f(n))
//T(n) <C*(f(n))
//13 + 2n < c(n)
//13 + 2n < 100n
//n>1
//O(n)


bool pokedex_agregar_pokemon(struct pokedex *pokedex, struct pokemon pokemon)
{	
	if(pokedex == NULL){
		return false;
	}
	struct nodo_pokemon *nuevo_nodo = malloc(sizeof(struct nodo_pokemon));
	if(nuevo_nodo == NULL){
		return false;
	}
	nuevo_nodo->pokemones = malloc(sizeof(struct pokemon));
	if(nuevo_nodo->pokemones == NULL){
		free(nuevo_nodo);
		return false;
	}
	nuevo_nodo->pokemones->nombre = malloc(strlen(pokemon.nombre) + 1);
	
	if(nuevo_nodo->pokemones->nombre == NULL){
		free(nuevo_nodo->pokemones);
		free(nuevo_nodo);
		return false;
	}
	strcpy(nuevo_nodo->pokemones->nombre,pokemon.nombre);
	nuevo_nodo->pokemones->tipo = pokemon.tipo;
	nuevo_nodo->pokemones->fuerza = pokemon.fuerza;
	nuevo_nodo->pokemones->destreza = pokemon.destreza;
	nuevo_nodo->pokemones->resistencia = pokemon.resistencia;
	nuevo_nodo->siguiente = NULL;
	pokedex->cantidad_pokemones++;
	if(pokedex->ultimo == pokedex->primero){
		pokedex->primero = nuevo_nodo;
	}
	else{
		pokedex->ultimo->siguiente = nuevo_nodo;
	}
	pokedex->ultimo = nuevo_nodo; //hago que apunte al ultimo nodo agregado
	return true;
}
//T(n) < C*(f(n))
//22+3n < c(n)
//22+3n < 100n
//n > 1
//O(n)


size_t pokedex_cantidad_pokemones(struct pokedex *pokedex)
{
	return pokedex->cantidad_pokemones;
}
//O(1)

const struct pokemon *pokedex_buscar_pokemon(struct pokedex *pokedex,
					     const char *nombre)
{	
	if(pokedex == NULL || nombre == NULL){
		return false;
	}
	struct nodo_pokemon *nodo_actual = pokedex->primero;
	while(nodo_actual != NULL){
		if(strcmp(nodo_actual->pokemones->nombre,nombre) == 0){
			return nodo_actual->pokemones;
		} else{
			nodo_actual = nodo_actual->siguiente;
		}
	}
	return NULL;
}
//5+2n < c(n)
//5+2n < 10n
//n>1
//O(n)

size_t pokedex_iterar_pokemones(struct pokedex *pokedex,
				bool (*funcion)(struct pokemon *, void *),
				void *ctx)
{
	if(pokedex == NULL){
		return false;
	}
	bool continua_iterando;
	size_t cantidad_iteraciones = 0;
	//no s'e si tengo que iterar sobre el nodo actual o sobre la pokedex, si itero sobre la pokedex pierdo la informacion
	struct nodo_pokemon *nodo_actual = pokedex->primero;
	while(nodo_actual != NULL){
		continua_iterando = funcion(nodo_actual->pokemones,ctx);
		cantidad_iteraciones++;
		if(!continua_iterando){
			break;
		}
		nodo_actual = nodo_actual->siguiente;
	}
	return cantidad_iteraciones;
}
//10+2n < c(n)
//c>12
//n>1
//o(n)

void pokedex_destruir(struct pokedex *pokedex)
{
	if(pokedex != NULL){
		struct nodo_pokemon *nodo_actual = pokedex->primero;
		struct nodo_pokemon *nodo_siguiente;

		while(nodo_actual != NULL){
			nodo_siguiente = nodo_actual->siguiente;
			if(nodo_actual->pokemones != NULL){
				free(nodo_actual->pokemones->nombre);
				free(nodo_actual->pokemones);
			}
			free(nodo_actual);
			nodo_actual = nodo_siguiente;
		}
	}
	free(pokedex->ultimo);
	free(pokedex);
}

//o(n)
