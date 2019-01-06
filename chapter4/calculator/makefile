object = getch.o getop.o main.o stack.o

calculator: $(object)
	cc -o calculator $(object)
getch.o: getch.c
	cc -c getch.c
getop.o: getop.c calc.h
	cc -c getop.c
main.o: main.c calc.h
	cc -c main.c
stack.o: stack.c
	cc -c stack.c
clean:
	rm $(object)