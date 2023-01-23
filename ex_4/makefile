OBJS	= Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o Reader.o TCPServer.o server.o \
	TCPClient.o client.o StandardMain.o KnnData.o ChangeSetsCommand.o UploadCommand.o DownloadResultsCommand.o \
	DisplayStringCommand.o ClassifyCommand.o CLI.o StandardIO.o SocketIO.o
OUT	= server.out client.out test.out

OBJS0	= Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o Reader.o TCPServer.o server.o KnnData.o ChangeSetsCommand.o \
	UploadCommand.o DownloadResultsCommand.o DisplayStringCommand.o ClassifyCommand.o CLI.o SocketIO.o
SOURCE0	= server.cpp Algorithm.cpp Classifiable.cpp Distance.cpp Initializer.cpp KNN.cpp Reader.cpp \
	KnnData.cpp ChangeSetsCommand.cpp UploadCommand.cpp DownloadResultsCommand.cpp DisplayStringCommand.cpp \
	ClassifyCommand.cpp CLI.cpp TCPServer.cpp SocketIO.cpp
HEADER0	= Algorithm.h Classifiable.h Distance.h Initializer.h KNN.h Reader.h TCPServer.h
OUT0 = server.out

OBJS1	= TCPClient.o client.o Reader.o SocketIO.o
SOURCE1	= TCPClient.cpp client.cpp Reader.cpp SocketIO.cpp
HEADER1 = TCPClient.h
OUT1 = client.out

OBJS2 = StandardMain.o Algorithm.o Classifiable.o Distance.o Initializer.o KNN.o Reader.o KnnData.o ChangeSetsCommand.o \
	UploadCommand.o DownloadResultsCommand.o DisplayStringCommand.o ClassifyCommand.o CLI.o StandardIO.o
SOURCE2 = StandardMain.cpp Algorithm.cpp Classifiable.cpp Distance.cpp Initializer.cpp KNN.cpp Reader.cpp \
	KnnData.cpp ChangeSetsCommand.cpp UploadCommand.cpp DownloadResultsCommand.cpp DisplayStringCommand.cpp \
	ClassifyCommand.cpp CLI.cpp StandardIO.cpp
OUT2 = test.out 


CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = -lpthread

all: server client

server: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0) $(LFLAGS)

client: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1) $(LFLAGS)

test: $(OBJS2) $(LFLAGS)
	$(CC) -g $(OBJS2) -o $(OUT2) $(LFLAGS)

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

ChangeSetsCommand.o: ChangeSetsCommand.cpp
	$(CC) $(FLAGS) ChangeSetsCommand.cpp -std=c++11

ClassifyCommand.o: ClassifyCommand.cpp
	$(CC) $(FLAGS) ClassifyCommand.cpp -std=c++11

CLI.o: CLI.cpp
	$(CC) $(FLAGS) CLI.cpp -std=c++11

DisplayStringCommand.o: DisplayStringCommand.cpp
	$(CC) $(FLAGS) DisplayStringCommand.cpp -std=c++11

DownloadResultsCommand.o: DownloadResultsCommand.cpp
	$(CC) $(FLAGS) DownloadResultsCommand.cpp -std=c++11

KnnData.o: KnnData.cpp
	$(CC) $(FLAGS) KnnData.cpp -std=c++11

StandardIO.o: StandardIO.cpp
	$(CC) $(FLAGS) StandardIO.cpp -std=c++11

UploadCommand.o: UploadCommand.cpp
	$(CC) $(FLAGS) UploadCommand.cpp -std=c++11

StandardMain.o: StandardMain.cpp
	$(CC) $(FLAGS) StandardMain.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)
