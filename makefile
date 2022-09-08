node.o:
	gcc rns.c node.h -g -o rns
clean:
	rm -f *.o rns