#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.14159
#define FOMULA(X) 1/4*(X) 

int main(int *argc, char *argv[])
{
  int i,samp;
  double x,y,samp2;
  samp = atoi(argv[1]);
  samp2 = atof(argv[1]);
  FILE *fp,*fp2;

	if ((fp = fopen("t_smpl", "w+")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	
	}

  srand( (unsigned int)time( NULL ) );

  for( i=0; i<samp/4; i++ ){
    
		x = 5*(rand()%samp)/samp2;
                y = 5*(rand()%samp)/samp2;  
                if(y > FOMULA(x)){
			fprintf(fp, "%lf\t", x );
			fprintf(fp, "%lf\t", y );
			fprintf(fp,"1");
			fprintf(fp,"\n");
		}
		 else {
			fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"-1");
			fprintf(fp,"\n");
                }
  	
   }
  for( i=0; i<samp/4; i++ ){

                x = -5*(rand()%samp)/samp2;
                y = 5*(rand()%samp)/samp2;
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"-1");
                        fprintf(fp,"\n");
                } 

   } 
  
   for( i=0; i<samp/4; i++ ){

                x = 5*(rand()%samp)/samp2;
                y = -5*(rand()%samp)/samp2;
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"-1");
                        fprintf(fp,"\n");
                } 

   } 

  for( i=0; i<samp/4; i++ ){

                x = -5*(rand()%samp)/samp2; 
                y = -5*(rand()%samp)/samp2;
         
                if(y > FOMULA(x)){
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"1");
                        fprintf(fp,"\n");
                }
                 else {
                        fprintf(fp, "%lf\t", x );
                        fprintf(fp, "%lf\t", y );
                        fprintf(fp,"-1");
                        fprintf(fp,"\n");
                }
	
 	}
  return 0;
}
