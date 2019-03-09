#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include "filemgm.h"
#include "mandelbrot.h"

void printHelp();
void getParametros(int argc, char **argv, parametro *parametros);

int main(int argc, char **argv){
	
     int rows, cols;
    
     //Tipo de dato parametro se encuentra en mandelbrot.h
     parametro *parametros = (parametro * ) malloc(sizeof(parametro));
     
     //puntero a arreglo de float
     float *imagen; 
     	     
     //obtiene parametros desde linea de comando
     getParametros(argc, argv, parametros);
   

     //calcula cantidad de filas y columnas a partir de los limites ingresados.
     //+1 por instrucciones dadas 
     rows = (int)((parametros->max_img - parametros->min_img) / parametros->delta)+1;
     cols = (int)((parametros->max_real- parametros->min_real) / parametros->delta)+1;    
     
     //almacena en la estructura de datos el numero de filas y columnas calculadas
     parametros->cols = cols;
     parametros->rows = rows;

     //muestra cantidad de filas y columnas para imprimir en octave
     //printf("fil: %d\n", parametros->rows);
     //printf("col: %d\n", parametros->cols); 
     
     //reserva memoria para el arreglo de salida
     imagen = malloc(rows * cols * sizeof(float));

     //si se ingresa el parametro de hebras calcula mediante el la funcion mandelbrot_paralelo
     //de lo contrario utilizando el secuencial
     //De todas formas se generan ambos binarios mandelbrotp y mandelbrot 
     if(parametros->threads > 0){
	     printf("Paralelo..\n");
	     mandelbrot_paralelo(parametros, imagen);
     }
     else{
	     printf("Secuencial..");
	     mandelbrot_secuencial(parametros, imagen);
     }
     
     //guarda archivo en formato binario float  
     guardaArchivo(parametros->output_file, imagen, rows * cols);     
}

void printHelp(){

	printf("Uso :  ");
	printf(" \n");
	
}

/*
 *Obtiene parametros de linea de comando y 
 * retorna valores en tipo de dato parametro
 */
void getParametros(int argc, char **argv, parametro *parametros){

		char c;
		char *empty = '\0';

		while((c=getopt(argc, argv, "i:a:b:c:d:s:f:t:h"))!=-1)
		{
			switch(c){
				case 'i': //depth
				        parametros->depth = atoi(optarg);
					break;
				case 'a': //lim inferior real
					parametros->min_real = atof(optarg);
					break;
				case 'b': //lim inferior img	
					parametros->min_img = atof(optarg);
					break;
				case 'c': //lim superior real
					parametros->max_real = atof(optarg);
					break;
				case 'd': //lim superior img
					parametros->max_img = atof(optarg);
					break;	
				case 's': //muestreo
					parametros->delta = atof(optarg);
					break;
				case 'f': //archivo de salida
					parametros->output_file = optarg;
					break;
				case 't': //numero hilos
				        parametros->threads = atoi(optarg);
					break;	
				case 'h':
					printHelp();
					break;	
			}
		}
}

