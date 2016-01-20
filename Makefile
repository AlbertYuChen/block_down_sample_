# Author: Albert Yu Chen
# Date: Jan 15 2015

# I'm using gcc version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04) 
CC=g++
CFLAGS= -pthread -lpthread -std=c++11 -fpermissive
SOURCES=Block_Down_Sample.cpp main.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=block_down_sample.exe
# This will automatically find the path, in the folder
INCLUDES = -I ./zi_lib/ -I ./zi_lib/external/include 

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

.cpp.o:
	$(CC) $^ $(INCLUDES) $(CFLAGS) -c -o $@

.PHONY: clean

clean:
	rm *.o $(EXECUTABLE) 
