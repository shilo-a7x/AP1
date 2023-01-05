OBJS	= Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o .o Reader.o
SOURCE	= Algorithm.cpp Classifiable.cpp Distance.cpp Initializer.cpp KNN.cpp Main.cpp Reader.cpp
HEADER	= Algorithm.h Classifiable.h Distance.h Initializer.h KNN.h Reader.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: server.out client.out
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Algorithm.o: Algorithm.cpp
	$(CC) $(FLAGS) Algorithm.cpp -std=c++11

Classifiable.o: Classifiable.cpp
	$(CC) $(FLAGS) Classifiable.cpp -std=c++11

Distance.o: Distance.cpp
	$(CC) $(FLAGS) Distance.cpp -std=c++11

Initializer.o: Initializer.cpp
	$(CC) $(FLAGS) Initializer.cpp -std=c++11

KNN.o: KNN.cpp
	$(CC) $(FLAGS) KNN.cpp -std=c++11

Reader.o: Reader.cpp
	$(CC) $(FLAGS) Reader.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
