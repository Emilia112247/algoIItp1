#include "pa2m.h"
#include "src/csv.h"
#include "src/pokedex.h"
#include<string.h>

typedef struct nodo_pokemon { //un nodo de la lista de pokemones
    struct pokemon *pokemones; 
    struct nodo_pokemon *siguiente; //este es un puntero que me apunta al siguiente de la lista, 
}nodo_pokemon;

typedef struct pokedex{
	struct nodo_pokemon *primero; //apunta al primer nodo de la lista
	struct nodo_pokemon *ultimo; //apunta al ultimo de la lista
	size_t cantidad_pokemones;
}pokedex;


void abrirUnArchivoInexistenteDebeRetornarNull()
{
	struct archivo_csv *archivo =
		abrir_archivo_csv("noexiste/noexiste/noexiste/no", ';');
	pa2m_afirmar(archivo == NULL, "El archivo no existe y se retorna NULL");
}

/*
void elarchivoquesequiereleerestavacio()
{
	size_t columnas = 5;
	size_t ctx;

	struct archivo_csv *archivo = 
		leer_linea_csv(archivo,columnas,,ctx);
	pa2m_afirmar(archivo == NULL, "El archivo no existe");
}
*/

/*void erroralcerrarelarchivo()
{
	struct archivo_csv {
		FILE *mis_archivos;//creo un puntero a mis archivos
	};
	struct archivo_csv *archivo;
	
	cerrar_archivo_csv(archivo);
	pa2m_afirmar(archivo->mis_archivos != NULL, "Error al cerrar el archivo");

}*/

void erroralagregarunpokemon()
{
	struct pokedex *pokedex = NULL;
	
	struct pokemon pokemon;
	pokemon.nombre = malloc(sizeof("Pikachu") + 1);
	if(pokemon.nombre == NULL){
		return;
	}
	strcpy(pokemon.nombre,"Pikachu");
	pokemon.tipo = 'E';
	pokemon.fuerza = 80;
	pokemon.destreza = 100;
	pokemon.resistencia = 94;
	pokedex_agregar_pokemon(pokedex, pokemon);
	pa2m_afirmar(pokedex == NULL, "No existe la pokedex");
	free(pokemon.nombre);
}

void noseingresounpokemon()
{
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
    nueva_pokedex->cantidad_pokemones = 0;

    struct pokemon *pokemon = NULL; // Pokémon nulo

	pokedex_agregar_pokemon(nueva_pokedex, *pokemon);
	pa2m_afirmar(pokemon == NULL, "No hay pokemon para agregar");
	free(nueva_pokedex);
}

void errorencantidaddepokemones()
{
	struct pokemon pokemon;
	pokemon.nombre = malloc(strlen("Pikachu") + 1);
	if(pokemon.nombre == NULL){
		return;
	}
	strcpy(pokemon.nombre,"Pikachu");
	pokemon.tipo = 'E';
	pokemon.fuerza = 80;
	pokemon.destreza = 100;
	pokemon.resistencia = 94;

	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));

	struct nodo_pokemon *nuevo_nodo = malloc(sizeof(struct nodo_pokemon));
	nuevo_nodo->pokemones = NULL;
	nuevo_nodo->pokemones->nombre =malloc(strlen("Pikachu")+ 1);
	strcpy(nuevo_nodo->pokemones->nombre,pokemon.nombre);
	nuevo_nodo->pokemones->destreza = pokemon.destreza;
	nuevo_nodo->pokemones->resistencia = pokemon.resistencia;
	nuevo_nodo->pokemones->tipo = pokemon.tipo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->primero = nuevo_nodo;

	nueva_pokedex->ultimo = nueva_pokedex->primero;
	nueva_pokedex->cantidad_pokemones = 1;

	pokedex_cantidad_pokemones(nueva_pokedex);
	pa2m_afirmar(nueva_pokedex->cantidad_pokemones != 1,"Error al guardar la cantidad de pokemones");
	free(nueva_pokedex);
	free(pokemon.nombre);
	free(nuevo_nodo->pokemones->nombre);
	free(nuevo_nodo);
}

void pokedexesigualanull()
{
	struct pokedex {//tiene que guardar todos los nodos
		struct nodo_pokemon *primero; //tiene que apuntar al primer nodo de la lista
		struct nodo_pokemon *ultimo; //apunta al ultimo de la lista
		size_t cantidad_pokemones;
	};
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;
	pokedex_buscar_pokemon(nueva_pokedex,"Pikachu");
	pa2m_afirmar(nueva_pokedex == NULL, "Error al ingresar una pokedex");
	free(nueva_pokedex);
}

void noseingresoelnombredelpokemon()
{
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;

	struct pokemon pokemon;
	pokemon.nombre = malloc(strlen("Pikachu") + 1);
	if(pokemon.nombre == NULL){
		return;
	}
	strcpy(pokemon.nombre,"Pikachu");
	pokemon.tipo = 'E';
	pokemon.fuerza = 80;
	pokemon.destreza = 100;
	pokemon.resistencia = 94;


	struct nodo_pokemon *nuevo_nodo = malloc(sizeof(struct nodo_pokemon));
	nuevo_nodo->pokemones = NULL;
	nuevo_nodo->pokemones->nombre =malloc(strlen("Pikachu")+ 1);
	strcpy(nuevo_nodo->pokemones->nombre,pokemon.nombre);
	nuevo_nodo->pokemones->destreza = pokemon.destreza;
	nuevo_nodo->pokemones->resistencia = pokemon.resistencia;
	nuevo_nodo->pokemones->tipo = pokemon.tipo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->primero = nuevo_nodo;
	nueva_pokedex->ultimo = nueva_pokedex->primero;
	nueva_pokedex->cantidad_pokemones = 1;


	const char *nombre = NULL;
	pokedex_buscar_pokemon(nueva_pokedex,nombre);
	pa2m_afirmar(nombre == NULL, "No se ingreso el nombre del pokemon");
	free(nueva_pokedex);
	free(pokemon.nombre);
	free(nuevo_nodo->pokemones->nombre);
	free(nuevo_nodo);
}

void seencutraelnombrebuscado()
{
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;

	struct pokemon pokemon;
	pokemon.nombre = malloc(strlen("Pikachu") + 1);
	if(pokemon.nombre == NULL){
		return;
	}
	strcpy(pokemon.nombre,"Pikachu");
	pokemon.tipo = 'E';
	pokemon.fuerza = 80;
	pokemon.destreza = 100;
	pokemon.resistencia = 94;

	struct pokemon poke;
	poke.nombre = malloc(strlen("Rattata") + 1);
	if(poke.nombre == NULL){
		return;
	}
	strcpy(poke.nombre,"Rattata");
	poke.tipo = 'E';
	poke.fuerza = 20;
	poke.destreza = 80;
	poke.resistencia = 10;

	struct nodo_pokemon *nuevo_nodo = malloc(sizeof(struct nodo_pokemon));
	nuevo_nodo->pokemones = NULL;
	nuevo_nodo->pokemones->nombre = malloc(strlen("Pikachu")+ 1);
	strcpy(nuevo_nodo->pokemones->nombre,pokemon.nombre);
	nuevo_nodo->pokemones->destreza = pokemon.destreza;
	nuevo_nodo->pokemones->resistencia = pokemon.resistencia;
	nuevo_nodo->pokemones->tipo = pokemon.tipo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->primero = nuevo_nodo;
	nueva_pokedex->ultimo = nueva_pokedex->primero;

	strcpy(nuevo_nodo->pokemones->nombre,poke.nombre);
	nuevo_nodo->pokemones->tipo = poke.tipo;
	nuevo_nodo->pokemones->destreza = poke.destreza;
	nuevo_nodo->pokemones->fuerza = poke.fuerza;
	nuevo_nodo->pokemones->resistencia = poke.resistencia;

	nueva_pokedex->primero->siguiente = nuevo_nodo;
	nueva_pokedex->ultimo = nuevo_nodo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->cantidad_pokemones = 2;

	const char *nombre = {"Rattata"};
	pokedex_buscar_pokemon(nueva_pokedex,nombre);
	pa2m_afirmar(strcmp(nueva_pokedex->primero->pokemones->nombre,nombre) == 0, "Se encontro el pokemon buscado");
	free(nueva_pokedex);
	free(pokemon.nombre);
	free(poke.nombre);
	free(nuevo_nodo->pokemones->nombre);
	free(nuevo_nodo);
}

void noseencuentraelpokemonenlapokedex()
{
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;

	struct pokemon pokemon;
	pokemon.nombre = malloc(strlen("Pikachu") + 1);
	if(pokemon.nombre == NULL){
		return;
	}
	strcpy(pokemon.nombre,"Pikachu");
	pokemon.tipo = 'E';
	pokemon.fuerza = 80;
	pokemon.destreza = 100;
	pokemon.resistencia = 94;

	struct pokemon poke;
	poke.nombre = malloc(strlen("Rattata") + 1);
	if(poke.nombre == NULL){
		return;
	}
	strcpy(poke.nombre,"Rattata");
	poke.tipo = 'E';
	poke.fuerza = 20;
	poke.destreza = 80;
	poke.resistencia = 10;

	struct nodo_pokemon *nuevo_nodo = malloc(sizeof(struct nodo_pokemon));
	nuevo_nodo->pokemones = NULL;
	nuevo_nodo->pokemones->nombre = malloc(strlen("Pikachu")+ 1);
	strcpy(nuevo_nodo->pokemones->nombre,pokemon.nombre);
	nuevo_nodo->pokemones->destreza = pokemon.destreza;
	nuevo_nodo->pokemones->resistencia = pokemon.resistencia;
	nuevo_nodo->pokemones->tipo = pokemon.tipo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->primero = nuevo_nodo;
	nueva_pokedex->ultimo = nueva_pokedex->primero;

	strcpy(nuevo_nodo->pokemones->nombre,poke.nombre);
	nuevo_nodo->pokemones->tipo = poke.tipo;
	nuevo_nodo->pokemones->destreza = poke.destreza;
	nuevo_nodo->pokemones->fuerza = poke.fuerza;
	nuevo_nodo->pokemones->resistencia = poke.resistencia;

	nueva_pokedex->primero->siguiente = nuevo_nodo;
	nueva_pokedex->ultimo = nuevo_nodo;
	nuevo_nodo->siguiente = NULL;

	nueva_pokedex->cantidad_pokemones = 2;


	const char *nombre = {"Charmander"};
	pokedex_buscar_pokemon(nueva_pokedex,nombre);
	pa2m_afirmar(strcmp(nueva_pokedex->primero->pokemones->nombre,nombre) != 0, "No se encontro el pokemon buscado");
	free(nueva_pokedex);
	free(pokemon.nombre);
	free(poke.nombre);
	free(nuevo_nodo->pokemones->nombre);
	free(nuevo_nodo);
}

void noseingresounapokedex()
{
	struct pokedex {//tiene que guardar todos los nodos
		struct nodo_pokemon *primero; //tiene que apuntar al primer nodo de la lista
		struct nodo_pokemon *ultimo; //apunta al ultimo de la lista
		size_t cantidad_pokemones;
	};
	struct pokedex *nueva_pokedex = malloc(sizeof(struct pokedex));
	nueva_pokedex->primero = NULL;
	nueva_pokedex->ultimo = NULL;
	nueva_pokedex->cantidad_pokemones = 0;

	pokedex_iterar_pokemones(nueva_pokedex,);
	pa2m_afirmar(nueva_pokedex == NULL, "No se ingreso una pokedex"); //al poner nueva_pokedex == NULL, es como que este preguntando si se reservo memoria en esa variable en lugar de estas preguntando si esta vacia nueva_pokedex
	free(nueva_pokedex);
}

int main()
{
	pa2m_nuevo_grupo("Pruebas de archivos CSV");
	abrirUnArchivoInexistenteDebeRetornarNull();
	pa2m_nuevo_grupo("Pruebas pokemones");
	erroralagregarunpokemon();
	noseingresounpokemon();
	erroralagregarunpokemon();
	errorencantidaddepokemones();
	pa2m_nuevo_grupo("Pruebas buscar pokemon");
	pokedexesigualanull();
	noseingresoelnombredelpokemon();
	seencutraelnombrebuscado();
	noseencuentraelpokemonenlapokedex();
	pa2m_nuevo_grupo("Pruebas iterar pokemones");
	noseingresounapokedex();

	return pa2m_mostrar_reporte();
}