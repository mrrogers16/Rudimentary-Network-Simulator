node.o:
	gcc node.c node.h -g -o node.o
clean:
	rm -f *.o node 