typedef struct data{
	double x;
	double y;
	int    qul; 
	int    num;  
}data;

typedef struct rec{
        double x;
        double y;
	int num;
}rec;
int BubSort2(struct data *s_data); //sort.c
void ShowData(struct rec *s_data); //sort.c
//void fit(struct rec *t_func,struct data *L_data); //fit.c
void fit2(struct rec *t_func,struct data *L_data); //fit.c
double w_func_x_p(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_x_m(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_y_p(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_y_m(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_x_p2(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_x_m2(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_y_p2(double thore,struct data *L_data,int c_i); //w_func.c
double w_func_y_m2(double thore,struct data *L_data,int c_i); //w_func.c
