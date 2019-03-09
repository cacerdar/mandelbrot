#include <stdio.h> 
#include <math.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "mandelbrot.h"
#include "utils.h"

/*
 * Funcion Mandelbrot paralela
 * retorna puntero a float con el arreglo de valores de la imagen
 * La manipulacion del numero complejo se realiza mediante dos variables,
 * una con la parte real y la otra con la imaginaria
 */
void mandelbrot_paralelo(parametro *parametros, float *imagen){

   int fi,co,n,cont;

   double z0_re, z0_im, zn_re, zn_im;
   double c_re, c_im;	
   int num_threads;
  
   cont = 0;
   //asigna el numero de threads ingresado por parametro  
   num_threads = parametros->threads;
   
   //inicio bloque paralelizacion
   #pragma omp parallel num_threads(num_threads)   
   {
    //inicio bloque paralelizacion ciclo for con declaracion de variables privadas por hebra	   
    #pragma omp for private(c_re,c_im,z0_re,z0_im,zn_re,zn_im,n,fi) ordered    
    for(co=0;co<parametros->cols;co++){
        
	//calcula parte real del numero complejo    
        c_re = (parametros->min_real) + parametros->delta * co;   
      
	//por cada fila (parte imaginaria)
	for(fi=0;fi<parametros->rows;fi++){
	   
           //reinicializa valores		
	   z0_re = 0;
	   z0_im = 0;
	   n = 1;

	   //calcula parte imaginaria del numero complejo
           c_im = (parametros->min_img) + parametros->delta * fi;	
	
	   //almacena el numero complejo para la primera iteracion
	   zn_re = c_re;
	   zn_im = c_im;  
	  
	   //mientras el pitagoras del complejo sea < 2 y como maximo depth iteraciones
	   while(complex_abs(zn_re, zn_im)< 2 && n < parametros->depth){
	     
		 //Zn^2  
		 z0_re = (pow(zn_re, 2) - pow(zn_im, 2));
		 z0_im = 2 * zn_re * zn_im;
		
		 //Zn+1 = Zn^2 + c
		 zn_re = z0_re + c_re;
		 zn_im = z0_im + c_im;
		 //cuenta iteraciones para calcular escape
	         n++;
	   } 
          //seccion critica 
          // #pragma omp critical
	   //{
	   *(imagen+parametros->rows*co+fi) = (float) log(n) + 1;
	   //}
	}

    }
  }
}



