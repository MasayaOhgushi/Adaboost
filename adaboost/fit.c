#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"ada.h"
/*
#ifdef __cplusplus

template<typename T>T**AllocMatrix(int u,int v)
{
    int i; T**a,*b;
    try { a=(T**)new char[(sizeof*a+sizeof*b*v)*u]; }
    catch (...) { a=0; }
    if (a) b=(T*)(a+u); else return 0;
    for (i=0;i<u;i++,b+=v) a[i]=b;
    return a;
}
#define ALLOC_MATRIX(T,U,V) AllocMatrix<T>(U,V)
#define FREE(X) delete[]X

#else

void*AllocMatrix(int s,int u,int v)
{
    int i,t=s*v; char**a,*b;

    a=(char**)malloc((sizeof*a+t)*u);
    if (a) b=(char*)(a+u); else return 0;
    for (i=0;i<u;i++,b+=t) a[i]=b;
    return a;
}
#define ALLOC_MATRIX(T,U,V) (T**)AllocMatrix(sizeof(T),U,V)
#define FREE(X) free(X)

#endif

*/

void fit(struct rec *t_func,struct data *L_data){
	
	int i,j,k=0,Nm,Np;
	double *w;
	double sum_p=0,sum_m=0;
	double u_w_x=0,u_w_y=0,s_y=0,t_y;
	double *jm_x_p,*jm_x_m,*jm_y_p,*jm_y_m,*sepa,*alpha;
	double db_x_p,db_x_m,db_y_p,db_y_m;	
	double thore;
	double min;
	double best;
	int best_x_p,best_x_m,best_y_p,best_y_m,*s_flag;

        w=(double *)malloc(sizeof(double)*L_data[0].num);
	jm_x_p=(double *)malloc(sizeof(double)*L_data[0].num);	
	jm_x_m=(double *)malloc(sizeof(double)*L_data[0].num);
	jm_y_p=(double *)malloc(sizeof(double)*L_data[0].num);
	jm_y_m=(double *)malloc(sizeof(double)*L_data[0].num);
	sepa=(double *)malloc(sizeof(double)*L_data[0].num);
	s_flag=(int *)malloc(sizeof(int)*L_data[0].num);
	alpha=(double *)malloc(sizeof(double)*L_data[0].num);
	printf("1\n");

	Nm = 0;
	Np = 0;
	for(i=0;i<L_data[0].num;i++)
	{
		if(L_data[i].qul == 1)
		{
			Np++;
		}
		if(L_data[i].qul == -1)
                {
                        Nm++;
                }
	}
	
	for(i=0;i<L_data[0].num;i++)
        {
	
        	w[i]=1.0/(2*Np);
		
        }
Label:
        for(i=0;i<L_data[0].num-1;i++)
        {
               jm_x_p[i]=0.0;
               jm_y_p[i]=0.0;
               jm_x_m[i]=0.0;
               jm_y_m[i]=0.0;
        }

	printf("2\n");
//thoreshold x


	printf("loop %d\n",k);	
	for(i=0;i<L_data[0].num-1;i++)
        {
	 for(j=0;j<L_data[0].num;j++)
        	{
		thore = t_func[i].x;
		jm_x_p[i] += w[j] * w_func_x_p(thore,L_data,j);
		jm_x_m[i] += w[j] * w_func_x_m(thore,L_data,j);
		u_w_x += w[j];
//		printf("w_x_p %lf w_x_m %lf w_f_x_p %lf w_f_x_m %lf\n",w_x_p[i][j],w_x_m[i][j],w_func_x_p(thore,L_data,j),w_func_x_m(thore,L_data,j));
//		printf("x %lf y %lf label %d thore_x %lf jm_x_p %lf jm_x_m %lf\n",L_data[j].x,L_data[j].y,L_data[j].qul,t_func[i].x,jm_x_p[i],jm_x_m[i]);
		}
		jm_x_p[i] /= u_w_x;
		jm_x_m[i] /= u_w_x;
		printf("jm_x_p %lf jm_x_m %lf\n",jm_x_p[i],jm_x_m[i]);
                u_w_x = 0;
//		printf("thore_x %lf number%d sum_p %lf sum_m %lf\n",t_func[i].x,i,sum_p,sum_m);
        }

	min = jm_x_p[0];
	best_x_p = 0;
        printf("0 rec_x_p %lf rec_x_l %lf\n",t_func[0].x,jm_x_p[0]);

	for(i=1;i<L_data[0].num-1;i++)
        {
		printf("%d rec_x_p %lf rec_x_l %lf\n",i,t_func[i].x,jm_x_p[i]);
		if(min > jm_x_p[i])
		{
			min = jm_x_p[i];
			best_x_p = i;
		}
	}
        printf("%d learn %d min_rec_x_p %lf\n",k,best_x_p,min);

        min = jm_x_m[0];
        best_x_m = 0;
        printf("0 rec_x_m %lf rec_x_m_l %lf\n",t_func[0].x,jm_x_m[0]);
	
        for(i=1;i<L_data[0].num-1;i++)
        {
                printf("%d rec_x_m %lf rec_x_l %lf\n",i,t_func[i].x,jm_x_m[i]);
                if(min > jm_x_m[i])
                {
                        min = jm_x_m[i];
                        best_x_m = i;
                }
        }
	printf("%d learn %d min_rec_x_m %lf\n",k,best_x_m,min);


//thoreshold y
        for(i=0;i<L_data[0].num-1;i++)
        {
         for(j=0;j<L_data[0].num;j++)
                {
                thore = t_func[i].y;
                jm_y_p[i] += w[j] * w_func_y_p(thore,L_data,j);       
		jm_y_m[i] += w[j] * w_func_y_m(thore,L_data,j);
		u_w_y += w[j];
//		printf("w_y_m %lf w_y_f_m %lf\n",w_y_m[i][j], w_func_y_m(thore,L_data,j));
		 }
//		printf("jm_y_p %lf jm_y_m %lf\n",jm_y_p[i],jm_y_m[i] );
		jm_y_p[i] /= u_w_y;
                jm_y_m[i] /= u_w_y;
//        	printf("jm_y_p %lf jm_y_m %lf\n",jm_y_p[i],jm_y_m[i] );
		printf("u_w_y %lf\n",u_w_y);
		u_w_y = 0;
	}

        min = jm_y_p[0];
	best_y_p = 0;
	printf("0 rec_y_p %lf rec_y_l %lf\n",t_func[0].y,jm_y_p[0]);
        
	for(i=1;i<L_data[0].num-1;i++)
        {
        	printf("%d rec_y_p %lf rec_y_l %lf\n",i,t_func[i].y,jm_y_p[i]);
	        if(min > jm_y_p[i])
                {
                        min = jm_y_p[i];
                        best_y_p = i;
                }
        }
        printf("%d learn %d min_rec_y_p %lf\n",k,best_y_p,min);	

    	min = jm_y_m[0];
        best_y_m = 0;
        printf("0 rec_y_m %lf rec_y_l %lf\n",t_func[0].y,jm_y_m[0]);
        
	for(i=1;i<L_data[0].num-1;i++)
        {
                printf("%d rec_y_m %lf rec_y_l %lf\n",i,t_func[i].x,jm_y_m[i]);
                if(min > jm_y_m[i])
                {
                        min = jm_y_m[i];
                        best_y_m = i;
                }
        }
        printf("%d learn %d min_rec_y_m %lf\n",k,best_y_m,min);

// best function search
	printf("3\n");
	
//	printf("x_%d %d\n",k,best_x);
	sepa[k] = t_func[best_x_p].x;
	s_flag[k] = 1;
	alpha[k] = log((1-jm_x_p[best_x_p])/jm_x_p[best_x_p]);
	db_x_p = alpha[k];
//	printf("best_x_p %d rec_x_p %lf jm_x_p %lf\n",best_x_p,sepa[k],jm_x_p[best_x_p]);
//	printf("alpha %lf\n",alpha[k]);
//	printf("s_flag %d\n",s_flag[k]);	
	
	best = jm_x_p[best_x_p];
	
	if(best > jm_x_m[best_x_m] )
	{
		best = jm_x_m[best_x_m];
//		printf("y_%d %d\n",k,best_y);
		sepa[k] = t_func[best_x_m].x;
		s_flag[k] = 2; 
	        alpha[k] = log((1-jm_x_m[best_x_m])/jm_x_m[best_x_m]);
  		
//		printf("rec_x_m %lf\n",sepa[k]);
//		printf("alpha %lf\n",alpha[k]);
//		printf("s_flag %d\n",s_flag[k]);
	      	
	
       	}
	db_x_m =  log((1-jm_x_m[best_x_m])/jm_x_m[best_x_m]);

        if(best > jm_y_p[best_y_p] )
        {
                best = jm_y_p[best_y_p];
//              printf("y_%d %d\n",k,best_y);
                sepa[k] = t_func[best_y_p].y;
                s_flag[k] = 3; 
                alpha[k] = log((1-jm_y_p[best_y_p])/jm_y_p[best_y_p]);

//                printf("rec_y_p %lf\n",sepa[k]);
//                printf("alpha %lf\n",alpha[k]);
//		printf("s_flag %d\n",s_flag[k]);
                
		thore = t_func[best_y_p].y;

        }
	db_y_p =  log((1-jm_y_p[best_y_p])/jm_y_p[best_y_p]);

        if(best > jm_y_m[best_y_m] )
        {
                best = jm_y_m[best_y_m];
//              printf("y_%d %d\n",k,best_y);
                sepa[k] = t_func[best_y_m].y;
                s_flag[k] = 4; 
                alpha[k] = log((1-jm_y_m[best_y_m])/jm_y_m[best_y_m]);

//                printf("rec_y_m %lf\n",sepa[k]);
//                printf("alpha %lf\n",alpha[k]);
//		printf("s_flag %d\n",s_flag[k]);


        }
	db_y_m =  log((1-jm_y_m[best_y_m])/jm_y_m[best_y_m]);

        printf("%d alpha_x_p %lf alpha_x_m %lf alpha_y_p %lf alpha_y_m %lf\n",k,db_x_p,db_x_m,db_y_p,db_y_m);
	
	printf("alpha_best %lf\n",alpha[k]);

	if(best == jm_x_p[best_x_p])
        {
	thore = t_func[best_x_p].x;
	for(j=0;j<L_data[0].num;j++)
        	{
        	w[j] = w[j] * exp(alpha[k] * w_func_x_p(thore,L_data,j));
//        	printf("%lf\n",w[best_x][j]);
        	}
	}
	
        if(best == jm_x_m[best_x_m])
        {
        thore = t_func[best_x_m].x;
        for(j=0;j<L_data[0].num;j++)
                {
                w[j] = w[j] * exp(alpha[k] * w_func_x_m(thore,L_data,j));
//              printf("%lf\n",w[best_x][j]);
                }
        }

        if(best == jm_y_p[best_y_p])
        {
        thore = t_func[best_y_p].y;
        for(j=0;j<L_data[0].num;j++)
                {
                w[j] = w[j] * exp(alpha[k] * w_func_y_p(thore,L_data,j));
//              printf("%lf\n",w[best_x][j]);
                }
        }

        if(best == jm_y_m[best_y_m])
        {
        thore = t_func[best_y_m].y;
        for(j=0;j<L_data[0].num;j++)
                {
                w[j] = w[j] * exp(alpha[k] * w_func_y_m(thore,L_data,j));
//              printf("%lf\n",w[best_x][j]);
                }
        }

	k++;
// Evaluation
	if(k>=L_data[0].num-1)
	{
		printf("4\n");
		Evaluation(s_flag,sepa,alpha,L_data);
		return;

	}

	goto Label;

}
