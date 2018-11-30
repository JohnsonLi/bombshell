cake: fish.o pipe.o
	gcc fish.o pipe.o

fish.o : fish.c

pipe.o: pipe.c
	gcc -c pipe.c

run:
	./a.out

clean:
	rm *.out
	rm *.o
