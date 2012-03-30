#include  <stdio.h>
#include "svm.h"

int svm_thre(struct data *s_data)
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

    for (i = 0; i <thre[0].num-1 ; i++) {
                thre[i].x = (thre[i].x + thre[i+1].x)/2;
                thre[i].y = (thre[i].y + thre[i+1].y)/2;
                 
    }
	Find(thre,s_data);
	ShowData(thre,s_data);
	fit(thre,s_data);
}
	
void Find(struct rec *thre,struct data *s_data)
{
	int i,j;
	int count_p_p=0,count_p_m=0,count_m_p=0,count_m_m=0;
	int *count_p_x,*count_m_x,*count_p_y,*count_m_y;	
	double max;
	int flag;
	int best_thre;

	count_p_x=(int *)malloc(sizeof(int)*s_data[0].num);
	count_m_x=(int *)malloc(sizeof(int)*s_data[0].num);
        count_p_y=(int *)malloc(sizeof(int)*s_data[0].num);
        count_m_y=(int *)malloc(sizeof(int)*s_data[0].num);


	for(i=0;i<s_data[0].num;i++)
	{
		count_p_x[i] = 0;
		count_m_x[i] = 0;
	        count_p_y[i] = 0;
                count_m_y[i] = 0;

	}

//	count_p_x
	for (i = 0; i <thre[0].num-1 ; i++) {
		for(j=0;j<s_data[0].num;j++){
                	if((thre[i].x < s_data[j].x) && (s_data[j].qul == 1)) 
                	{
				count_p_p++;
			}
			if((thre[i].x > s_data[j].x) && (s_data[j].qul == -1))
                        {
                                count_m_m++;
                        }
		}
		count_p_x[i] = count_p_p+count_m_m;
		count_p_p = 0;
		count_m_m = 0;
    	}
// count_m_x	
	for (i = 0; i <thre[0].num-1 ; i++) {
                for(j=0;j<s_data[0].num;j++){ 
                        if((thre[i].x < s_data[j].x) && (s_data[j].qul == -1))
                        { 
                                count_p_m++;
                        } 
                        if((thre[i].x > s_data[j].x) && (s_data[j].qul == 1))
                        { 
                                count_m_p++;
                        } 
                }
                count_m_x[i] = count_p_m+count_m_p;
                count_p_m = 0;
                count_m_p = 0;
	}
// count_p_y
        for (i = 0; i <thre[0].num-1 ; i++) {
                for(j=0;j<s_data[0].num;j++){
                        if((thre[i].x < s_data[j].x) && (s_data[j].qul == 1))
                        {
                                count_p_p++;
                        }
                        if((thre[i].x > s_data[j].x) && (s_data[j].qul == -1))
                        {
                                count_m_m++;
                        }
                } 
                count_p_y[i] = count_p_p+count_m_m;
                count_p_p = 0;
                count_m_m = 0;
        } 
// count_m_y     
        for (i = 0; i <thre[0].num-1 ; i++) {
                for(j=0;j<s_data[0].num;j++){
                        if((thre[i].x < s_data[j].x) && (s_data[j].qul == -1))
                        { 
                                count_p_m++;
                        }
                        if((thre[i].x > s_data[j].x) && (s_data[j].qul == 1))
                        {
                                count_m_p++;
			}
		}
                count_m_y[i] = count_p_m+count_m_p;
                count_p_m = 0;
                count_m_p = 0;
        }
	
	max = count_p_x[0];
	flag = 1;

	for (i = 1; i <s_data[0].num ; i++) {
		if(count_p_x[i] >max)
		{
			max = count_p_x[i];
			flag = 1;
			best_thre = i;	
		}
	}
        for (i = 0; i <s_data[0].num ; i++) {
                if(count_m_x[i] >max)
                {
                        max = count_m_x[i];
			flag = 2;
			best_thre = i;
                }
        }
        for (i = 0; i <s_data[0].num ; i++) {
                if(count_p_y[i] >max)
                {
                        max = count_p_y[i];
			flag = 3;
			best_thre = i;
                }
        }
        for (i = 0; i <s_data[0].num ; i++) {
                if(count_m_y[i] >max)
                {
                        max = count_m_y[i];
			flag = 4;
			best_thre = i;
                }
        }
	sv(thre,s_data,flag,best_thre);

}

