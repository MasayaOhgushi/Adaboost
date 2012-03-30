
CC = gcc

adain	 : ada_input.o sort.o fit.o w_func.o Evaluation.o
	$(CC) -lm -o $@ ada_input.o sort.o fit.o w_func.o Evaluation.o     

ada_input.o : ada_input.c ada.h
		$(CC) -c $*.c
sort.o : sort.c ada.h
	$(CC) -c $*.c

fit.o : fit.c ada.h
	 $(CC) -c $*.c

w_func.o : w_func.c ada.h
	$(CC) -c $*.c

Evaluation.o : Evaluation.c ada.h
	$(CC) -c $*.c

clean :
	rm ada.h ada_input.o sort.o fit.o w_func.o Evaluation.o
