cake: shell.o redirection.o pipe.o 
	gcc shell.o redirection.o pipe.o

shell.o: shell.c shell.h
	gcc -c shell.c

redirection.o: redirection.c redirection.h
	gcc -c redirection.c

pipe.o: pipe.c pipe.h
	gcc -c pipe.c

run:
	./a.out

clean:
	rm *.o
	rm *.out