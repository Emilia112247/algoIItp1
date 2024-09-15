#include "csv.h"
#include <stdio.h>
#include <string.h>

struct archivo_csv {
	FILE *mis_archivos;//creo un puntero a mis archivos
};

char* mi_strtok(char *str, char separador, char** siguiente){
	if(str == NULL && *siguiente == NULL){
		return NULL;
	}
	if(str == NULL){
		str = *siguiente;
	}
	char* inicio = str;
	char* donde = strchr(str,separador);
	if(donde != NULL){
		*donde = '\0';
		*siguiente = donde+1;
		
	} else {
		*siguiente=donde;
	}
	return inicio;
}

struct archivo_csv *abrir_archivo_csv(const char *nombre_archivo,
				      char separador)
{
	struct archivo_csv *archivo = malloc(sizeof(struct archivo_csv));
					  if (archivo == NULL){
						return false; //No se reservo memoria 
						}
						archivo->mis_archivos = fopen("nombre_archivo","r");
						
						if (archivo->mis_archivos == NULL){
							free(archivo);
							return NULL;
						}
						else{
							return archivo;
						}
}
//T(n) < C*(f(n))
//8+n < C(n)
//c>10
//8+n < 10n
//O(n)


size_t leer_linea_csv(struct archivo_csv *archivo, size_t columnas,
		      bool (*funciones[])(const char *, void *), void *ctx[])
{
	if(archivo == NULL || funciones == NULL || ctx == NULL){
		return 0;
	}
	char linea[300];
	if(fgets(linea,sizeof(linea),archivo->mis_archivos) == NULL){
		return 0;//si no puede leer 
	}
	if(columnas > 5){
		return 0;
	}
	linea[strcspn(linea, "\n")] = '\0';
	size_t columnas_leidas = 0;
	char* siguiente = NULL;
	char* aux = mi_strtok(linea,';',&siguiente);
	
	while ((aux != NULL) && (columnas_leidas <= columnas)) {
		if (!funciones[columnas_leidas](aux, ctx[columnas_leidas])) {
			return columnas_leidas;  // Error al parsear
		}
		columnas_leidas++;
		aux = mi_strtok(NULL, ';', &siguiente);
    }

    return columnas_leidas;
}
//T(n) < C*(f(n))
//15 + 2n < C(n)
//c>100
//15 + 2n < 100n
//O(n)


void cerrar_archivo_csv(struct archivo_csv *archivo)
{
	if(archivo != NULL && archivo->mis_archivos != NULL){
		fclose(archivo->mis_archivos);	
	}
	free(archivo);
}
//O(1);
