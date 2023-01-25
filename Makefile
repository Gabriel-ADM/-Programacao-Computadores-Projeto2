filesC = $(wildcard *.c)
filesO = $(filesC:.c=.o)

main: $(filesO)
	gcc -Wall $(filesO) -o main

main.o: main.c
	gcc -c -Wall main.c

%.o: %.c %.h
	gcc -Wall -c $<

.PHONY: clean
clean:
	rm main $(filesO)
