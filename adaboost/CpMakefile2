
CC = gcc

adain	 : ada_input.o sort.o fit2.o w_func.o 
	$(CC) -lm -o $@ ada_input.o sort.o fit2.o w_func.o      

ada_input.o : ada_input.c ada.h
		$(CC)  $*.c
sort.o : sort.c ada.h
	$(CC)  $*.c

fit2.o : fit2.c ada.h
	 $(CC) $*.c

w_func.o : w_func.c ada.h
	$(CC) $*.c

clean :
	rm ada.h ada_input.o sort.o fit2.o w_func.o 
