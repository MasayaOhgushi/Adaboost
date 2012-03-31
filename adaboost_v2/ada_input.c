#include <stdio.h>
#include <stdlib.h>
#include "ada.h"

int main(int argc,char *argv[])
{
	FILE *fp;
	data *L_data;
	char *str;
	int i;
	
	fp = fopen( argv[1], "r" );
	if( fp == NULL )
	{
		printf( "%s is dont open\n",argv[1]);
		return 1;
	}

	fseek(fp,  0L, SEEK_END);
	i = ftell(fp);
//	printf("%d\n",i);
     L_data = (struct data*)malloc(sizeof(struct data)*i);
     if (L_data == NULL) {
         printf( "memory allocation error\n" );
         exit(EXIT_FAILURE);
     }
	fseek(fp, 0L,SEEK_SET);
	i=0;	
	while((fscanf( fp, "%lf %lf %d", &L_data[i].x, &L_data[i].y, &L_data[i].qul )) != EOF)
        {
//	printf("%d\n",i);
//	printf( "%lf %lf %d\n", L_data[i].x, L_data[i].y, L_data[i].qul );
        i++;
        }
	L_data[0].num = i;
	BubSort(L_data);
	free(L_data);
	fclose( fp );
	return 0;
}
