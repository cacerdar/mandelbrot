High Performance Computing__
Generación de Imágenes Mandelbrot__
Programación multihebra con OpenMP____

./mandelbrot -i 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f out.raw__
-i: número máximo de iteraciones__
-a: límite inferior del componente real del plano complejo__
-b: límite inferior del componente imaginario__
-c: límite superior del componente real__
-d: límite superior del componente imaginario__
-s: muestreo__
-f: imagen de salida en formato raw.__

__
__

Para compilar__
__
 $ make __
__
Para limpiar objetos y ejecutable__
 __
  make clean__

