
#/*
#* Course: CS 100 Fall 2013
#*
#* First Name: Marco
#* Last Name: Tobon
#* Username: mtobo001
#* email address: mtobo001@ucr.edu
#*
#*
#* Assignment: “Homework #4”
#*
#* I hereby certify that the contents of this file represent
#* my own original individual work. Nowhere herein is there
#* code from any outside resources such as another individual,
#* a website, or publishings unless specifically designated as
#* permissible by the instructor or TA.
#*/

OBJECTS = testLinkedString.o String.o
SOURCE = String.cpp testLinkedString.cpp signale_handler.cpp #my_shell.cpp
COMPILE = g++ 
DEBUG = -g

#/Defalut====================================================================== 
default: all

#/All====================================================================== 
all: string signal
#my_shell not there did not finish

#/String Class====================================================================== 
string: $(OBJECTS)
	$(COMPILE) $(DEBUG) -o $@ $^

#/Signal====================================================================== 
signal: signal_handler.cpp
	$(COMPILE) $(DEBUG) -o $@ $^

#/my_shell====================================================================== 
#my_shell: my_shell.cpp
#	$(COMPILE) $(DEBUG) -c -o $@ $^


#/String.o====================================================================== 
String.o: String.cpp
	$(COMPILE) $(DEBUG) -c -o $@ $^

#/Clean====================================================================== 
clean:
	rm -rf *.o *~ signal string

#/Print====================================================================== 
print:
	cat String.cpp; cat String.h; cat testLinkedString.cpp

#/Strip====================================================================== 
strip:
	strip -g -S -d --strip-debug string signal
