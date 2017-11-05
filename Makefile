# this is probobly not something necessary for the proj
# delete when done
CC=g++
CPPFLAGS= -Wall

SRCS=main.cpp calculator.cpp
OBJS=main.o calculator.o

INPUTFILE=input.txt

# project name
all: proj3_lam

# cmd to make project exec
proj3_lam: $(OBJS)
	$(CC) $(CPPFLAGS) -o proj3_lam $(OBJS)

# cmds to make each object file
main.o:
