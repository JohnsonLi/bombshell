cake: fish.o
	gcc fish.o

fish.o : fish.c

run:
	./a.out

clean:
	rm *.out
	rm *.o
