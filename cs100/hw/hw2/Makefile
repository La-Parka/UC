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

#Variables
SOURCES = Coins.cc main.cc betterMain.cc bestMain.cc
OBJECTS = Coins.o main.o
B_OBJECTS = Coins.o  betterMain.o
BST_OBJECTS = Coins.o bestMain.o
COMPILE = g++

#Targets
default: all

#ALL 3 PROGRAMS =======================================
all: my_ls main betterMain bestMain 

#MY_LS ===============================================
my_ls: my_ls.cc
	$(COMPILE) -ggdb -o $@ $^

#NORMAL MAIN =========================================
main: $(OBJECTS)
	$(COMPILE) -ggdb -o $@ $^

#BETTER MAIN ========================================	
betterMain: $(B_OBJECTS)
	$(COMPILE) -ggdb -o $@ $^

#BEST MAIN =========================================
bestMain: $(BST_OBJECTS)
	$(COMPILE) -ggdb -o $@ $^

#COINS =========================================
Coins.o: Coins.h Coins.cc
	$(COMPILE) -ggdb -c -o $@ Coins.cc

clean:
	rm -rf *~ *.o bestMain betterMain main my_ls


