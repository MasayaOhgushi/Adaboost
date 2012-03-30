#include  <stdio.h>
#include "ada2.h"

int BubSort2(struct data *s_data)
{
    int i, j;
    double temp;	
    rec *thre; 

     thre = (struct rec*)malloc(sizeof(struct rec)*s_data[0].num);
     for (i = 0; i <s_data[0].num ; i++) {
        	thre[i].x = s_data[i].x;
		thre[i].y = s_data[i].y;
	}
    thre[0].num = s_data[0].num;
    for (i = 0; i <thre[0].num ; i++) {
        for (j = thre[0].num - 1; j > i; j--) {
            if (thre[j - 1].x > thre[j].x) {
                temp = thre[j].x;       
                thre[j].x = thre[j - 1].x;
                thre[j - 1].x= temp;  
//		printf("%lf\n", thre[j].x);
          }
        }	
    }

    for (i = 0; i <thre[0].num ; i++) {
        for (j = thre[0].num - 1; j > i; j--) {
            if (thre[j - 1].y > thre[j].y) {
                temp = thre[j].y;
                thre[j].y = thre[j - 1].y;
                thre[j - 1].y= temp;
//              printf("%lf\n", thre[j].x);
          }
        }
    }

    for (i = 0; i <thre[0].num-1 ; i++) {
                thre[i].x = (thre[i].x + thre[i+1].x)/2;
                thre[i].y = (thre[i].y + thre[i+1].y)/2;
                 
    }
	ShowData(thre);
	fit2(thre,s_data);
}
	
void ShowData(struct rec *s_data)
{
    int i;

//    for (i = 0; i < s_data[0].num; i++)
//       printf("%lf %lf\n", s_data[i].x,s_data[i].y);
}

