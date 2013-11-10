#/*
#* Course: CS 100 Fall 2013
#*
#* First Name: Marco
#* Last Name: Tobon
#* Username: mtobo001
#* email address: mtobo001@ucr.edu
#*
#*
#* Assignment: “Homework #2”
#*
#* I hereby certify that the contents of this file represent
#* my own original individual work. Nowhere herein is there
#* code from any outside resources such as another individual,
#* a website, or publishings unless specifically designated as
#* permissible by the instructor or TA.
#*/

OBJECTS = main.o String.o
SOURCE = String.cpp main.cpp fork.cpp input_main.cpp
COMPILE = g++ 
DEBUG = -g

#/Defalut====================================================================== 
default: all

#/All====================================================================== 
all: string fork input_main

#/String Class====================================================================== 
string: $(OBJECTS)
	$(COMPILE) $(DEBUG) -o $@ $^

#/Fork====================================================================== 
fork: fork.cpp
	$(COMPILE) $(DEBUG) -o $@ $^

#/String.o====================================================================== 
String.o: String.cpp
	$(COMPILE) $(DEBUG) -c -o $@ $^

#/Input Files====================================================================== 
input_main: input_main.cpp
	$(COMPILE) $(DEBUG) -o $@ $^

#/Clean====================================================================== 
clean:
	rm -rf *.o *~ fork string input_main
