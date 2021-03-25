# ** Christopher Gundlach
# ** CS-325							      	 
# ** Makefile for lightUp.cpp				   
# *********************************************

CXX = g++		#enables g++ as compiler
CXXFLAGS =  -std=c++11	#enables c++11 standards
CXXFLAGS += -Wall	#enables warnings

lightUp: lightUp.o
	g++ $(CXXFLAGS) lightUp.o -o lightUp

lightUp.o: lightUp.cpp
	g++ $(CXXFLAGS) -c lightUp.cpp 

clean:
	rm *.o lightUp