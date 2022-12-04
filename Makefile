all: Exp1 Exp2 

Exp1: Exp1.o  # test program for BinarySearchTree class
	g++ -Wall -o Exp1 Exp1.o  

Exp2: Exp2.o  # test program for BinarySearchTree class
	g++ -Wall -o Exp2 Exp2.o  

Exp1.o: Exp1.cpp dsexceptions.h
	g++ -Wall -o Exp1.o -c Exp1.cpp 

BSTtest2.o: Exp2.cpp dsexceptions.h
	g++ -Wall -o Exp2.o -c Exp2.cpp 

clean:
	rm -f Exp1 Exp2 *.o
