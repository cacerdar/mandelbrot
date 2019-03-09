DIRO = ./
DIRI = ./src
DIR2 = ./obj

all: release

release:
	mkdir -p $(DIR2)
	gcc -c $(DIRI)/filemgm.c -o $(DIR2)/filemgm.o
	gcc -c $(DIRI)/utils.c -o $(DIR2)/utils.o
	gcc -c $(DIRI)/mandelbrot.c -o $(DIR2)/mandelbrot.o -lm -fopenmp
	gcc -c $(DIRI)/mandelbrotp.c -o $(DIR2)/mandelbrotp.o -lm -fopenmp
	gcc -c $(DIRI)/main.c -o $(DIR2)/main.o -fopenmp
	gcc -o ./mandelbrotp $(DIR2)/*.o -lm -fopenmp
	gcc -o ./mandelbrot $(DIR2)/*.o -lm -fopenmp

clean:
	rm -f mandelbrot
	rm -f mandelbrotp
	rm -rf $(DIR2)
