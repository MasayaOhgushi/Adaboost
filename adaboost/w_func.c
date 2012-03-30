#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"ada.h"


double w_func_x_p(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if((L_data[c_i].x > thore) && (L_data[c_i].qul == 1))
        {
        	I = 0.0;
	}

        if((L_data[c_i].x > thore) && (L_data[c_i].qul == -1))
        {
                I=1.0;
        }

	if((L_data[c_i].x < thore) && (L_data[c_i].qul == 1))
        {
                I=1.0;
        }

        if((L_data[c_i].x < thore) && (L_data[c_i].qul == -1))
        {
                I=0.0;
        }


             return I;
}

double w_func_x_m(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if((L_data[c_i].x < thore) && (L_data[c_i].qul == 1))
        {
                I=0.0;
        }

        if((L_data[c_i].x < thore) && (L_data[c_i].qul == -1))
        {
                I=1.0;
        }

        if((L_data[c_i].x > thore) && (L_data[c_i].qul == 1))
        {
                I=1.0;
        }

        if((L_data[c_i].x > thore) && (L_data[c_i].qul == -1))
        {
                I=0.0;
        }


             return I;
}

double w_func_y_p(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if((L_data[c_i].y > thore) && (L_data[c_i].qul == 1))
        {
                I=0.0;
        }

        if((L_data[c_i].y > thore) && (L_data[c_i].qul == -1))
        {
                I=1.0;
        }

        if((L_data[c_i].y < thore) && (L_data[c_i].qul == 1))
        {
                I=1.0;
        }

        if((L_data[c_i].y < thore) && (L_data[c_i].qul == -1))
        {
                I=0.0;
        }

             return I;
}

double w_func_y_m(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if((L_data[c_i].y < thore) && (L_data[c_i].qul == 1))
        {
                I=0.0;
        }

        if((L_data[c_i].y < thore) && (L_data[c_i].qul == -1))
        {
                I=1.0;
        }

        if((L_data[c_i].y > thore) && (L_data[c_i].qul == 1))
        {
                I=1.0;
        }

        if((L_data[c_i].y > thore) && (L_data[c_i].qul == -1))
        {
                I=0.0;
        }

             return I;
}

double w_func_x_p2(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if(L_data[c_i].x > thore)
        {
                I = 1.0;
        }

        if(L_data[c_i].x < thore)
        {
                I=-1.0;
        }
        return I;
}

double w_func_x_m2(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
       if(L_data[c_i].x < thore)
        {
                I = 1.0;
        }

        if(L_data[c_i].x > thore)
        {
                I = -1.0;
        } 
	return I;
}

double w_func_y_p2(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if(L_data[c_i].y > thore)
        {
                I = 1.0;
        }

        if(L_data[c_i].y < thore)
        {
                I = -1.0;
        }
	return I; 
}

double w_func_y_m2(double thore,struct data *L_data,int c_i)
{
        double I;

//pluse and minus thoreshold count
        if(L_data[c_i].y < thore)
        {
                I = 1.0;
        }

        if(L_data[c_i].y > thore)
        {
                I = -1.0;
        } 
	return I;
}
