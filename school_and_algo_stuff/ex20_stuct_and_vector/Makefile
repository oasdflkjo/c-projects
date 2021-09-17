main: main.o complex.o
	gcc -o main main.o complex.o
	./main

%.o: %.c
	gcc -c -o $@ $<

clean:
	rm -f *.o main