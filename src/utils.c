#include <stdio.h> 
#include <math.h>

/**
 * Calcula la distancia de un numero complejo al origen
 */
extern double complex_abs(double real, double img){
    return sqrt(pow(real, 2) + pow(img, 2));
}


