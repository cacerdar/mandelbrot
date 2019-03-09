<b>High Performance Computing<br />
Generación de Imágenes Mandelbrot<br />
Programación multihebra con OpenMP<br /><br /></b>

./mandelbrot -i 500 -a -1 -b -1 -c 1 -d 1 -s 0.001 -f out.raw<br />
-i: número máximo de iteraciones<br />
-a: límite inferior del componente real del plano complejo<br />
-b: límite inferior del componente imaginario<br />
-c: límite superior del componente real<br />
-d: límite superior del componente imaginario<br />
-s: muestreo<br />
-f: imagen de salida en formato raw.<br />

<br />
<br />

Para compilar<br />
<br />
 $ make <br />
<br />
Para limpiar objetos y ejecutable<br />
 <br />
  make clean<br />

