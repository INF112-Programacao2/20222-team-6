CC = g++
FLAGS= -g -lsfml-graphics -lsfml-window -lsfml-system
OUTPUT= main
allt:
		$(CC) -g -std=c++11 -O2 -Wall *.cpp $(FLAGS) -o $(OUTPUT)

all:
		$(CC) -g *.cpp $(FLAGS) -o $(OUTPUT)

run: all
	./$(OUTPUT)

runt: allt
	./$(OUTPUT)

clean:
		rm.o -f