.PHONY: clean
a.out: stablo.o resenje.o
	gcc stablo.o resenje.o
resenje.o: resenje.c
	gcc -c resenje.c
stablo.o: stablo.c
	gcc -c stablo.c
clean:
	rm *.o a.out
