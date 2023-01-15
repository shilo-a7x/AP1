OBJS	= Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o Reader.o TCPServer.o server.o TCPClient.o client.o
OUT	= server.out client.out

OBJS0	= Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o Reader.o TCPServer.o server.o
SOURCE0	= Algorithm.cpp Classifiable.cpp Distance.cpp Initializer.cpp KNN.cpp Reader.cpp TCPServer.cpp server.cpp
HEADER0	= Algorithm.h Classifiable.h Distance.h Initializer.h KNN.h Reader.h TCPServer.h
OUT0 = server.out

OBJS1	= TCPClient.o client.o
SOURCE1	= TCPClient.cpp client.cpp
HEADER1 = TCPClient.h
OUT1 = client.out

CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: server client

server: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0) $(LFLAGS)

client: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1) $(LFLAGS)

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

TCPServer.o: TCPServer.cpp
	$(CC) $(FLAGS) TCPServer.cpp -std=c++11

server.o: server.cpp
	$(CC) $(FLAGS) server.cpp -std=c++11

TCPClient.o: TCPClient.cpp
	$(CC) $(FLAGS) TCPClient.cpp -std=c++11

client.o: client.cpp
	$(CC) $(FLAGS) client.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)
