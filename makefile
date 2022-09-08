node.o:
	gcc node.c utilities.c -g -o rns
clean:
	rm -f *.o rns