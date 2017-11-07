# this is probobly not something necessary for the proj
# delete when done
CC=g++
CPPFLAGS= -Wall

SRCS=main.cpp calculator.cpp
OBJS=main.o calculator.o

EXEC=test
# project name
all: $(EXEC)

# cmd to make project exec
$(EXEC): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXEC) $(OBJS)

# cmds to make each object file
main.o: main.cpp calculator.h
	$(CC) $(CPPFLAGS) -c main.cpp

calculator.o: calculator.cpp calculator.h
	$(CC) $(CPPFLAGS) -c calculator.cpp

clean:
	rm *.o *.exe 
