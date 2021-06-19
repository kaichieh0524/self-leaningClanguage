main: raw_queue.o wrapped_queue.o main.c
	gcc -o main raw_queue.o wrapped_queue.o main.c

raw_queue.o: raw_queue.c
	gcc -c raw_queue.c

wrapped_queue.o: wrapped_queue.c
	gcc -c wrapped_queue.c

.PHONY : clean test

test: main
	./main


clean:
	rm *.o main -rf
	