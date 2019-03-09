typedef struct { 
	      
	        int depth;
		double min_real;                                     
		double min_img;                                            
		double max_real;                                           
		double max_img;                                            
		double delta;                                              
		int threads;                                              
		char *output_file;  
		int rows;
		int cols;

}parametro;


extern void mandelbrot_secuencial(parametro *parametros, float *image);
extern void mandelbrot_paralelo(parametro *parametros, float *image);
