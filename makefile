node.exe: node node.h
	gcc -Wall -g -std=c89 -o node.exe node 
clean:
	rm -f node.exe 