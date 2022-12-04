all: Exp1 Exp3 

Exp1: Exp1.o  # test program for BinarySearchTree class
	g++ -Wall -o Exp1 Exp1.o  

Exp3: Exp3.o  # test program for BinarySearchTree class
	g++ -Wall -o Exp3 Exp3.o  

Exp1.o: Exp1.cpp dsexceptions.h
	g++ -Wall -o Exp1.o -c Exp1.cpp 

Exp3.o: Exp3.cpp dsexceptions.h
	g++ -Wall -o Exp3.o -c Exp3.cpp 

clean:
	rm -f Exp1 Exp3 *.o
