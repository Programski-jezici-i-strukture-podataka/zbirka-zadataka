.PHONY: all clean

all: pravougaonik.o kvadrat.o main.o
	gcc pravougaonik.o kvadrat.o main.o

pravougaonik.o: pravougaonik.c
	gcc -c pravougaonik.c

kvadrat.o: kvadrat.c
	gcc -c kvadrat.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o ./a.out