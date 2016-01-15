CC=g++
CFLAGS=-fpermissive -pthread -lpthread -std=c++11
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=block_down_sample.exe
INCLUDES = -I ./zi_lib/ -I ./zi_lib/external/include 

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

.cpp.o:
	$(CC) $< $(INCLUDES) $(CFLAGS) -c -o $@

.PHONY: clean
	
clean:
	rm *.o $(EXECUTABLE) 
