nclude<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"svm.h"

sv_search(struct rec *thre,struct data *s_data,int flag,int best_thre)
{
	int i,j;
	sv *sv

	sv = (struct sv*)malloc(sizeof(struct sv)*s_data[0].num);


	for(i=0;i<s_data[0].num;i++){
		if((flag == 1) && (s_data[i].x < (thre[best_thre].x + Margine) ) (s_data[i].qul == 1) && (s_data[i].x > thre[best_thre].x  ))
		{
			sv[j].x = s_data[i].x;
			sv[j].y = s_data[i].y;
			sv[j].qul = s_data[i].qul
			j++;		
		}
                if((flag == 1) && (s_data[i].x > (thre[best_thre].x - Margine) ) (s_data[i].qul == -1) && (s_data[i].x < thre[best_thre].x  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;
                }

                if((flag == 2) && (s_data[i].x > (thre[best_thre].x - Margine) ) (s_data[i].qul == 1) && (s_data[i].x < thre[best_thre].x  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;        
                }
                if((flag == 2) && (s_data[i].x < (thre[best_thre].x + Margine) ) (s_data[i].qul == -1) && (s_data[i].x > thre[best_thre].x  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;
                }

                if((flag == 3) && (s_data[i].y < (thre[best_thre].y + Margine) ) (s_data[i].qul == 1) && (s_data[i].y > thre[best_thre].y  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;        
                }
                if((flag == 3) && (s_data[i].y > (thre[best_thre].y - Margine) ) (s_data[i].qul == -1) && (s_data[i].y < thre[best_thre].y  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;
                }
                if((flag == 4) && (s_data[i].y > (thre[best_thre].y - Margine) ) (s_data[i].qul == 1) && (s_data[i].y < thre[best_thre].x  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;        
                }
                if((flag == 4) && (s_data[i].y < (thre[best_thre].y + Margine) ) (s_data[i].qul == -1) && (s_data[i].y > thre[best_thre].y  ))
                {
                        sv[j].x = s_data[i].x;
                        sv[j].y = s_data[i].y;
                        sv[j].qul = s_data[i].qul
                        j++;
                }

	}
	sv[0].num = j;

}
