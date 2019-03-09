High Performance Computing
Generación de Imágenes Mandelbrot
Programación multihebra con OpenMP

./mandelbrot -i 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f out.raw
-i: número máximo de iteraciones
-a: límite inferior del componente real del plano complejo
-b: límite inferior del componente imaginario
-c: límite superior del componente real
-d: límite superior del componente imaginario
-s: muestreo
-f: imagen de salida en formato raw.



Para compilar

 $ make 

Para limpiar objetos y ejecutable
 
  make clean

