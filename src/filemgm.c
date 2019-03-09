#include <stdio.h>
#include <stdlib.h>
#include "filemgm.h"


/*
 * Guarda archivo en formato binario de float
 *
 * Parametros:
 *  nombre_archivo : puntero al nombre de archivo 
 *  out: puntero a float donde se encuentra el arreglo de salida
 *  npixeles : largo del arreglo de salida
 *
 * */
extern int guardaArchivo(char *nombre_archivo, float *out, int npixeles){

	 FILE *archivo;
	 long largo; 
	 int c, cont;

	 largo = npixeles * sizeof(float);
	 archivo = fopen(nombre_archivo, "wb");

	 if(!archivo){
	 	printf("Error al abrir el archivo\n");
		return 0;
	 }
	
	 //Menor a 1 porque es 1 item
	 if(fwrite(out,largo , 1, archivo ) < 1){
	 	printf("Error al guardar el archivo %s ", nombre_archivo);
		return 0;
	 }


	 fclose(archivo);
	 return 1;
}

