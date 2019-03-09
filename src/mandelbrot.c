#include <stdio.h> 
#include <math.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "utils.h"
#include "mandelbrot.h"

/*
 * Funcion Mandelbrot secuencial 
 * retorna puntero a float con el arreglo de valores de la imagen
 * La manipulacion del numero complejo se realiza mediante dos variables, 
 * una con la parte real y otra con la imaginaria.
 */
extern void mandelbrot_secuencial(parametro *parametros, float *imagen){

    int fi,co,n,cont;

    
    double z0_re, z0_im, zn_re, zn_im;
    double c_re, c_im;	
    
    cont = 0;

    //recorre por cada columna (parte real del numero complejo)
    for(co=0;co<parametros->cols;co++){
  
	//calcula la parte real del numero complejo a partir del valor minimo, delta y la posicion de la columna    
        c_re = (parametros->min_real) + parametros->delta * co;   
      
	//recorre por cada fila (parte imaginaria)
	for(fi=0;fi<parametros->rows;fi++){
	   
	   //reinicializa valores	
	   z0_re = 0;
	   z0_im = 0;
	   n = 1;
	   
	   //calcula la parte imaginaria del complejo a partir del minimo, delta y posicion de la fila
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
		
          //almacena en el puntero al arreglo + contador
	  *(imagen+cont) = (float) log(n) + 1;
	   cont++;	
	}

    }

}


