.PHONY: clean
a.out: lista.o resenje.o
	gcc lista.o resenje.o
resenje.o: resenje.c
	gcc -c resenje.c
lista.o: lista.c
	gcc -c lista.c
clean:
	rm *.o a.out
