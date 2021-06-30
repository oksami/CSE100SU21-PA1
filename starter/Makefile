# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall -std=c++11

#include debugging symbols in executable
LDFLAGS= -g	

default: test_bst 

test_bst: test_BST.o 
	g++ -o test_bst test_BST.o


test_BST.o: BST.hpp BSTNode.hpp BSTIterator.hpp 


clean:
	$(RM) test_bst *.o
