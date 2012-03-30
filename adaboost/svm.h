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
int svm_thre(struct data *s_data);
void Find(struct rec *thre,struct data *s_data);
void sv_search(struct rec *thre,struct data *s_data,int flag,int best_thre);
void fit(struct rec *t_func,struct data *L_data);
double w_func_x_p(double thore,struct data *L_data,int c_i);
double w_func_x_m(double thore,struct data *L_data,int c_i);
double w_func_y_p(double thore,struct data *L_data,int c_i);
double w_func_y_m(double thore,struct data *L_data,int c_i);
double w_func_x_p2(double thore,struct data *L_data,int c_i);
double w_func_x_m2(double thore,struct data *L_data,int c_i);
double w_func_y_p2(double thore,struct data *L_data,int c_i);
double w_func_y_m2(double thore,struct data *L_data,int c_i);
void Evaluation(int *s_flag, double *sepa,double *alpha, struct data *L_data);
